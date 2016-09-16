#ifndef __SCRIBBLE_H__
#define __SCRIBBLE_H__


#using <mscorlib.dll>

#using <System.DLL>
#using <System.Drawing.DLL> 
#using <System.Windows.Forms.DLL>


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Drawing::Printing;

ref class ScribbleDoc;

ref class MainWindow : public Form
{
public:
	 static MainWindow^ parentWindow;

 public:
	  MainWindow();
	  virtual ~MainWindow();
	  static int documentCount; // static var which keeps track of the document count
								// This is used in the display of the form views

	 void DisableItems();
	 void EnableItems();


private:
	 void InitializeComponent();

	 void MenuItemHandler(Object^ sender, EventArgs^ e);
	 void ToolbarHandler(Object^ sender, ToolBarButtonClickEventArgs^ e);

	 void AboutHelp();
	
	//Help Topics
	 void HelpTopics();
	
	//The last 2 line of the InitComponent
	//printDocument1.AddOnPrintPage (new PrintPageEventHandler (ScribblePrintPage);
	//CreateDocument();

	//Print
	 void Print();
	
	//PrintPage event handler
	 void ScribblePrintPage(Object^ sender,PrintPageEventArgs^ ev);	

	//PrintPreview
	 void PrintPreview();
	
	//Exit
	 void Exit();
	
	//Close the View
	 void CloseView();
	//Tile
	 void Tile();
	//Cascade
	 void Cascade();
	
	//Clear the contents
	 void ClearAll();
	
//Open an existing document
	 void Open();
	
	//Save document
	 void Save();

	//Open new document
	 void New();
	
	//NewWindow
	 void NewWindow();

	 
	
	 //ThickLine
	 void ThickLine();
	 //PenWidth
	 void PenWidthsDlg();		
	//Creates a new document
	 ScribbleDoc^ CreateDocument();
	


private:
	System::ComponentModel::Container^ components;
	PrintDocument^ printDoc;	
	 HelpProvider^ helpProvider1;
	 Windows::Forms::MenuItem^ fileMenuItem;	
	 Windows::Forms::MenuItem^ editMenuItem;
	 Windows::Forms::MenuItem^ viewMenuItem;
	 Windows::Forms::MenuItem^ penMenuItem;
	 Windows::Forms::MenuItem^ helpMenuItem;
	 Windows::Forms::MenuItem^ windowMenuItem;
	 Windows::Forms::MenuItem^ newMenuItem;
	 Windows::Forms::MenuItem^ openMenuItem;
	 Windows::Forms::MenuItem^ closeMenuItem;
	 Windows::Forms::MenuItem^ saveMenuItem;
	 Windows::Forms::MenuItem^ saveAsMenuItem;
	 Windows::Forms::MenuItem^ printMenuItem;
	 Windows::Forms::MenuItem^ printPreviewMenuItem;
	 Windows::Forms::MenuItem^ exitMenuItem;
	 Windows::Forms::MenuItem^ thickLineMenuItem;
	 Windows::Forms::MenuItem^ newWindowMenuItem;
	 Windows::Forms::MenuItem^ cascadeMenuItem;
	 Windows::Forms::MenuItem^ tileMenuItem;
	 Windows::Forms::MenuItem^ clearAllMenuItem;
	 Windows::Forms::MenuItem^ toolbarMenuItem;
	 Windows::Forms::MenuItem^ statusbarMenuItem;
	 Windows::Forms::MenuItem^ helpAboutMenuItem;
	 Windows::Forms::MenuItem^ helpTopicsMenuItem;
	 Windows::Forms::MenuItem^ penWidthMenuItem;

	 Windows::Forms::MenuItem^ line1MenuItem;
	 Windows::Forms::MenuItem^ line2MenuItem;
	 Windows::Forms::MenuItem^ line3MenuItem;
	
	 //toolbar
	 Windows::Forms::ToolBar^ toolBar1;
	 Windows::Forms::StatusBar^ statusBar1;
	 Windows::Forms::ImageList^ imageList1;
	 Windows::Forms::ToolBarButton^ helpButton;
	 Windows::Forms::ToolBarButton^ printButton;
	 Windows::Forms::ToolBarButton^ previewButton;
	 Windows::Forms::ToolBarButton^ saveButton;
	 Windows::Forms::ToolBarButton^ openButton;
	 Windows::Forms::ToolBarButton^ newButton;

	 Windows::Forms::MainMenu^ mainMenu;

};
#endif __SCRIBBLE_H__