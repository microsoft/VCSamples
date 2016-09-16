
#include "Scribble.h"
#include "ScribbleView.h"
#include "ScribbleDoc.h"
#include "Stroke.h"

ScribbleView:: ScribbleView(ScribbleDoc ^ doc,MainWindow ^ parent)
{
	InitializeComponent();
	myDoc  = doc;
	MdiParent = parent;
	mainWin = parent;
	this->Text = String::Concat("ScribbleDoc",doc->docID.ToString(),":",doc->viewList->Count.ToString());				
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

void ScribbleView::MouseDownHandler( Object^ /* sender */, MouseEventArgs^ e )
{
   if (  !this->Capture )
      return;

   try
   {
      Point ^ p = gcnew Point( e->X,e->Y );
      
      currentStroke = myDoc->NewStroke();
      currentStroke->pointArray->Add( p ); // Add first point to the new stroke   
      previousPoint =  *p;
      this->Capture = true; // Capture the mouse until button up 
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleView::MouseMoveHandler( Object^ /* sender */, MouseEventArgs^ e )
{
   if (  !this->Capture )
      return;

   try
   {
      Point ^ p = gcnew Point( e->X,e->Y );
      
      currentStroke->pointArray->Add( p );
      Graphics^ g = CreateGraphics();
      g->DrawLine( myDoc->GetCurrentPen(), previousPoint,  *p );
      previousPoint =  *p;
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleView::MouseUpHandler( Object^ /* sender */, MouseEventArgs^ e )
{
   if (  !currentStroke )
      return;

   try
   {
      Point ^ p = gcnew Point( e->X,e->Y );

      currentStroke->pointArray->Add( p );
      Graphics^ g = CreateGraphics();
      g->DrawLine( myDoc->GetCurrentPen(), previousPoint,  *p );
      previousPoint =  *p;
      
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

void ScribbleView::PaintHandler( Object^ /* sender */, PaintEventArgs^ e )
{
   Rectangle rectClip = e->ClipRectangle;
   rectClip.Inflate( 1, 1 );
   Rectangle rectStroke;
   for ( int i = 0; i < myDoc->strokeList->Count; i++ )
   {
      Stroke ^ st = dynamic_cast<Stroke^>(myDoc->strokeList[ i ]);
      rectStroke = st->GetBoundingRectangle();
      rectStroke.Inflate( 1, 1 );
      if (  !rectStroke.IntersectsWith( rectClip ) )
            continue;
      st->DrawStroke( e->Graphics );

   }
}

void ScribbleView::ClosingHandler( Object^ /* sender */, CancelEventArgs^ e )
{
   if ( myDoc->isDirty && myDoc->viewList->Count == 1 )
   {
      int save = static_cast<int>(MessageBox::Show(  "Do you want to Save changes ?",  "Scribble", MessageBoxButtons::YesNoCancel ));
      if ( save == 6 )//TODO: Tarek : DialogResult::Yes )
      {
         SaveFileDialog^ saveDlg = gcnew SaveFileDialog;
         saveDlg->Filter =  "Scribble Files (*.scb)|*.scb|All Files (*.*)|*.*";
         saveDlg->DefaultExt =  ".scb";
         
         //saveDlg.FileName = "Scribb1.scb";
         int res = static_cast<int>(saveDlg->ShowDialog());
         if ( res == 1 )//TODO: Tarek: DialogResult::OK )
         {
            myDoc->SaveDocument( saveDlg->FileName );
            myDoc->viewList->Remove( this );
         }
         else
         if ( res == 2 )//TODO: Tarek: DialogResult::Cancel )
                  e->Cancel = true;
      }
      else
      if ( save == 2 )//TODO: Tarek: DialogResult::Cancel )
            e->Cancel = true;
      //If user selected 'Cancel',don't close the form
      else
      
      //If user selected 'Cancel',don't close the form
      if ( save == 7 )//TODO: Tarek: DialogResult::No )
            myDoc->viewList->Remove( this );
   }
   else
   {
      myDoc->viewList->Remove( this );
   }
}

void ScribbleView::ClosedHandler( Object^ /* sender */, EventArgs^ /* e */ )
{
   
   //If there are no child views, then disable menu and toolbar items
   if ( mainWin->MdiChildren->Length == 0 )
      mainWin->DisableItems();
}

ScribbleDoc^ ScribbleView::GetDocument()
{
   return myDoc;
}

