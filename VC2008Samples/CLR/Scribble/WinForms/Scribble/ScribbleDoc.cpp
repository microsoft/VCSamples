
#include "Scribble.h"
#include "ScribbleView.h"
#include "ScribbleDoc.h"
#include "Stroke.h"

ScribbleDoc:: ScribbleDoc(MainWindow^ mainWin)
{
    //
    // TODO: Add Constructor Logic here
    //				
		isDirty= false;
		thickPen=false;
		thinWidth=2;
		thickWidth=5;
		strokeList = gcnew ArrayList() ;
		viewList = gcnew ArrayList();
		ReplacePen();

		//Set the ID to be the current count + 1. This is so that the ID starts with 1
		docID = MainWindow::documentCount+1;
		//Create a view (Form) for this document
		ScribbleView^ view = gcnew ScribbleView(this,mainWin);
		viewList->Add(view);
		view->Show();
}

ScribbleDoc::~ScribbleDoc(){}

Stroke^ ScribbleDoc::NewStroke()
{
   Stroke ^ s = gcnew Stroke( penWidth );
   strokeList->Add( s );
   isDirty = true; //Now that the doc is modified, set the dirty flag
   return s;
}

void ScribbleDoc::ReplacePen()
{
   penWidth = thickPen ? thickWidth : thinWidth;
   currentPen = gcnew Pen( Color::Black,(float)penWidth );
}

void ScribbleDoc::SaveDocument( String^ fileName )
{
   try
   {
      Stream^ s = File::Open( fileName, FileMode::Create );
      BinaryFormatter^ b = gcnew BinaryFormatter;
      b->Serialize( s, strokeList );
      s->Close();
      
      //Now that the doc is saved, its no more dirty
      isDirty = false;
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

void ScribbleDoc::OpenDocument( String^ fileName )
{
   try
   {
      Stream^ s = File::Open( fileName, FileMode::Open );
      BinaryFormatter^ b = gcnew BinaryFormatter;
      strokeList = dynamic_cast<ArrayList^>(b->Deserialize( s ));
      s->Close();
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}

Pen^ ScribbleDoc::GetCurrentPen()
{
   return currentPen;
}


//Updates all the views of the document with the new data
void ScribbleDoc::UpdateAllViews( ScribbleView ^ sender, Stroke ^ newStroke )
{
   ScribbleView ^ view;
   for ( int i = 0; i < viewList->Count; i++ )
   {
      view = dynamic_cast<ScribbleView^>(viewList[ i ]);
      if ( view->Equals( sender ) )
            continue;
      
      //If this is for a new stroke
      if ( newStroke )
      {
         view->Invalidate( newStroke->GetBoundingRectangle() );
      }
      else
      {
         
         //must be ClearAll,hence invalidate the entire region
         view->Invalidate();
      }
      view->Update();

   }
}


// Deletes the contents of the document
void ScribbleDoc::DeleteContents()
{
   strokeList->Clear();
   UpdateAllViews( nullptr, nullptr );
}

