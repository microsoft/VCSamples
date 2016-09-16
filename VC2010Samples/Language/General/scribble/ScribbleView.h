#ifndef __SCRIBBLEVIEW_H__
#define __SCRIBBLEVIEW_H__

#using <mscorlib.dll>

#using <System.DLL>
#using <System.Drawing.DLL> 
#using <System.Windows.Forms.DLL>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Printing;
using namespace System::Collections;

#include "ScribbleDoc.h"
	
ref class ScribbleView : public Form
{
    /// <summary> 
    ///    Required designer variable
    /// </summary>
private:
	System::ComponentModel::Container^ components;
	ScribbleDoc^ myDoc;
	MainWindow^ mainWin;

public:
	 Point previousPoint;
	 Stroke^ currentStroke;

     ScribbleView(ScribbleDoc^ doc,MainWindow^ parent);
    ~ScribbleView();
    
     void InitializeComponent();
	 void MouseDownHandler(Object^ sender,MouseEventArgs^ e);
	 void MouseMoveHandler(Object^ sender,MouseEventArgs^ e);
	 void MouseUpHandler(Object^ sender,MouseEventArgs^ e);
	 void PaintHandler(Object^ sender, PaintEventArgs^ e);
	 //void CloseHandler(Object^ sender, CancelEventArgs^ e);	
	 void ClosingHandler(Object^ sender, CancelEventArgs^ e);	
	 void ClosedHandler(Object^ sender, EventArgs^ e);	
	 ScribbleDoc^ GetDocument();
};

#endif __SCRIBBLEVIEW_H__