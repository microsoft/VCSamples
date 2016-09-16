#include "Scribble.h"
#include "ScribbleView.h"
#include "ScribbleDoc.h"

ScribbleView::ScribbleView( ScribbleDoc^ doc, MainWindow^ parent )
{
   InitializeComponent();
   myDoc = doc;
   MdiParent = parent;
   mainWin = parent;
   this->Text = String::Concat( "ScribbleDoc", doc->docID.ToString(), ":", doc->viewList->Count.ToString() );
}

ScribbleView::~ScribbleView(){}

void ScribbleView::InitializeComponent()
{
   components = gcnew System::ComponentModel::Container;
   AutoScaleBaseSize = System::Drawing::Size( 5, 13 );
   Text =  "ScribbleDoc";
   BackColor = Color::White;
   
   //AddOnMouseDown(new MouseEventHandler(this,&ScribbleView::MouseDownHandler)); 
   MouseDown += gcnew MouseEventHandler( this, &ScribbleView::MouseDownHandler );
   
   //AddOnMouseMove(new MouseEventHandler(this,&ScribbleView::MouseMoveHandler));  
   MouseMove += gcnew MouseEventHandler( this, &ScribbleView::MouseMoveHandler );
   
   //AddOnMouseUp(new MouseEventHandler(this,&ScribbleView::MouseUpHandler));  
   MouseUp += gcnew MouseEventHandler( this, &ScribbleView::MouseUpHandler );
   
   //AddOnPaint(new PaintEventHandler (this,&ScribbleView::PaintHandler));
   Paint += gcnew PaintEventHandler( this, &ScribbleView::PaintHandler );
   
   //AddOnClosing(new CancelEventHandler (this,&ScribbleView::CloseHandler));
   Closing += gcnew CancelEventHandler( this, &ScribbleView::ClosingHandler );
   Closed += gcnew EventHandler( this, &ScribbleView::ClosedHandler );
   
   //@design this.TrayLargeIcon = true;
   //@design this.TrayHeight = 0;
}

void ScribbleView::MouseDownHandler( Object^, MouseEventArgs^ e )
{
   if (  !this->Capture )
      return;

   try
   {
      Point p( e->X,e->Y );
      
      currentStroke = myDoc->NewStroke();
      currentStroke->pointArray->Add( p ); // Add first point to the new stroke   
      previousPoint =  p;
      this->Capture = true; // Capture the mouse until button up 
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleView::MouseMoveHandler( Object^, MouseEventArgs^ e )
{
   if (  !this->Capture )
      return;

   try
   {
      Point p( e->X,e->Y );
      
      currentStroke->pointArray->Add( p );
      Graphics^ g = CreateGraphics();
      g->DrawLine( myDoc->GetCurrentPen(), previousPoint,  p );
      previousPoint =  p;
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleView::MouseUpHandler( Object^, MouseEventArgs^ e )
{
   if (  !currentStroke )
      return;

   try
   {
      Point p( e->X,e->Y );
      currentStroke->pointArray->Add( p );
      Graphics^ g = CreateGraphics();
      g->DrawLine( myDoc->GetCurrentPen(), previousPoint,  p );
      previousPoint =  p;
      
      // Tell the stroke item that we're done adding points to it.
      // This is so it can finish computing its bounding rectangle.   
      currentStroke->FinishStroke();
      
      // Now that a stoke is added, inform all the views of the document about this
      myDoc->UpdateAllViews( this, currentStroke );
      Capture = false;
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleView::PaintHandler( Object^, PaintEventArgs^ e )
{
   Rectangle rectClip = e->ClipRectangle;
   rectClip.Inflate( 1, 1 );
   Rectangle rectStroke;
   for ( int i = 0; i < myDoc->strokeList->Count; i++ )
   {
      Stroke^ st = dynamic_cast<Stroke^>(myDoc->strokeList[ i ]);
      rectStroke = st->GetBoundingRectangle();
      rectStroke.Inflate( 1, 1 );
      if (  !rectStroke.IntersectsWith( rectClip ) )
            continue;
      st->DrawStroke( e->Graphics );

   }
}

void ScribbleView::ClosingHandler( Object^, CancelEventArgs^ e )
{
   if ( myDoc->isDirty && myDoc->viewList->Count == 1 )
   {
	  System::Windows::Forms::DialogResult save = MessageBox::Show(  "Do you want to Save changes ?",  "Scribble", MessageBoxButtons::YesNoCancel );
      if ( save == System::Windows::Forms::DialogResult::Yes )
      {
         SaveFileDialog^ saveDlg = gcnew SaveFileDialog;
         saveDlg->Filter =  "Scribble Files (*.scb)|*.scb|All Files (*.*)|*.*";
         saveDlg->DefaultExt =  ".scb";
         
         //saveDlg.FileName = "Scribb1.scb";
         System::Windows::Forms::DialogResult res = saveDlg->ShowDialog();
         if ( res == System::Windows::Forms::DialogResult::OK )
         {
            myDoc->SaveDocument( saveDlg->FileName );
            myDoc->viewList->Remove( this );
         }
         else
         if ( res == System::Windows::Forms::DialogResult::Cancel )
                  e->Cancel = true;
      }
      else
      if ( save == System::Windows::Forms::DialogResult::Cancel )
            e->Cancel = true;
      //If user selected 'Cancel',don't close the form
      else
      
      //If user selected 'Cancel',don't close the form
      if ( save == System::Windows::Forms::DialogResult::No )
            myDoc->viewList->Remove( this );
   }
   else
   {
      myDoc->viewList->Remove( this );
   }
}

void ScribbleView::ClosedHandler( Object^, EventArgs^ )
{
   
   //If there are no child views, then disable menu and toolbar items
   if ( mainWin->MdiChildren->Length == 0 )
      mainWin->DisableItems();
}

ScribbleDoc^ ScribbleView::GetDocument()
{
   return myDoc;
}

