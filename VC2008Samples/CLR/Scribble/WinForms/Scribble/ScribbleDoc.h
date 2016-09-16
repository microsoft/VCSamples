#pragma once 

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Collections;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

//Document class
ref class ScribbleDoc
{
public:
   ScribbleDoc( MainWindow^ mainWin );
   ~ScribbleDoc();
   void SaveDocument( String^ fileName );
   void OpenDocument( String^ fileName );
   Pen^ GetCurrentPen();
   void UpdateAllViews( ScribbleView^ view, Stroke^ newStroke );
   void DeleteContents();
   Stroke^ NewStroke();
   void ReplacePen();
   ArrayList^ strokeList;
   ArrayList^ viewList;
   bool isDirty;
   int docID;

protected:
   UInt32 penWidth;
   Pen^ currentPen;

public:
   bool thickPen;
   UInt32 thinWidth;
   UInt32 thickWidth;
};

