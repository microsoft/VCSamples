#ifndef __SCRIBBLEDOC_H__
#define __SCRIBBLEDOC_H__

#using <mscorlib.dll>

#using <System.DLL>
#using <System.Drawing.DLL> 
#using <System.Windows.Forms.DLL>
#using <System.Runtime.Remoting.DLL>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Collections;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary ;

//Forward declaration of ScribbleView to keep compiler happy

ref class ScribbleView;


[Serializable] ref class Stroke 
{
public:
		 int		penWidth;
		 ArrayList^	pointArray;
		 Rectangle	boundingRect;

		 Stroke(int nPenWidth);
		 ~Stroke();
		 Rectangle GetBoundingRectangle() {return boundingRect;}

		 void DrawStroke(Graphics^ g);
		 void FinishStroke();		
		 int Min(int x,int y) {return (x < y) ? x : y;}
		 int Max(int x,int y) {return  (x > y) ? x : y ;}
};


//Document class
 ref class ScribbleDoc
{
public:
	ScribbleDoc(MainWindow^ mainWin);
	~ScribbleDoc();

    void SaveDocument(String^ fileName);
	void OpenDocument(String^ fileName);
	Pen^ GetCurrentPen();
	void UpdateAllViews(ScribbleView^ view, Stroke^ newStroke);
	void DeleteContents();
	Stroke^ NewStroke();
	void ReplacePen();

	ArrayList^ strokeList ;
	ArrayList^ viewList;
	bool isDirty;

	int docID; 

protected:
    UInt32 penWidth;
	Pen^  currentPen;  
public:
	bool thickPen;
	UInt32 thinWidth;
	UInt32 thickWidth;	    
};

#endif  __SCRIBBLEDOC_H__