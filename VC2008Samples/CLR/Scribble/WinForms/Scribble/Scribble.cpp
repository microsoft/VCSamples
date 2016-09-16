#include "Scribble.h"
#include "ScribbleView.h"
#include "ScribbleDoc.h"
#include "Stroke.h"

#include "StringDialog.h"

using namespace System::Reflection;
using namespace System::Resources;

MainWindow::MainWindow()
{
   parentWindow = this;
   InitializeComponent();
   documentCount = 0;
   CreateDocument();
}

MainWindow::~MainWindow(){}

void MainWindow::InitializeComponent()
{
   components = gcnew System::ComponentModel::Container;
   printDoc = gcnew System::Drawing::Printing::PrintDocument;
   printDoc->PrintPage += gcnew PrintPageEventHandler( this, &MainWindow::ScribblePrintPage );
   this->AutoScaleBaseSize = System::Drawing::Size( 5, 13 );
   this->Text =  "Scribble";
   this->IsMdiContainer = true;
   this->Menu = mainMenu;
   this->ClientSize = System::Drawing::Size( 600, 400 );
   this->helpProvider1 = gcnew System::Windows::Forms::HelpProvider;
   this->helpProvider1->HelpNamespace = "Help\\scribble.chm";
   this->helpProvider1->SetShowHelp( this, true );
   
   //File
   newMenuItem = gcnew Windows::Forms::MenuItem( "&New",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   openMenuItem = gcnew Windows::Forms::MenuItem( "&Open",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   closeMenuItem = gcnew Windows::Forms::MenuItem( "&Close",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   saveMenuItem = gcnew Windows::Forms::MenuItem( "&Save",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   saveAsMenuItem = gcnew Windows::Forms::MenuItem( "Save &As",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   line1MenuItem = gcnew Windows::Forms::MenuItem( "-" );
   printMenuItem = gcnew Windows::Forms::MenuItem( "&Print",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   printPreviewMenuItem = gcnew Windows::Forms::MenuItem( "P&rintPreview",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   line2MenuItem = gcnew Windows::Forms::MenuItem( "-" );
   line3MenuItem = gcnew Windows::Forms::MenuItem( "-" );
   exitMenuItem = gcnew Windows::Forms::MenuItem( "E&xit",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   array<Windows::Forms::MenuItem^>^rFileItems = gcnew array<Windows::Forms::MenuItem^>(10);
   rFileItems[ 0 ] = newMenuItem;
   rFileItems[ 1 ] = openMenuItem;
   rFileItems[ 2 ] = closeMenuItem;
   rFileItems[ 3 ] = saveMenuItem;
   rFileItems[ 4 ] = saveAsMenuItem;
   rFileItems[ 5 ] = line1MenuItem;
   rFileItems[ 6 ] = printMenuItem;
   rFileItems[ 7 ] = printPreviewMenuItem;
   rFileItems[ 8 ] = line2MenuItem;
   rFileItems[ 9 ] = exitMenuItem;
   fileMenuItem = gcnew Windows::Forms::MenuItem( "&File",rFileItems );
   
   //EDIT
   clearAllMenuItem = gcnew Windows::Forms::MenuItem( "Clear &All",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   array<Windows::Forms::MenuItem^>^rEditItems = gcnew array<Windows::Forms::MenuItem^>(2);
   rEditItems[ 0 ] = clearAllMenuItem;
   rEditItems[ 1 ] = line3MenuItem;
   editMenuItem = gcnew Windows::Forms::MenuItem( "&Edit",rEditItems );
   
   //Pen
   thickLineMenuItem = gcnew Windows::Forms::MenuItem( "Thick Line",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   penWidthMenuItem = gcnew Windows::Forms::MenuItem( "Pen Width",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   array<Windows::Forms::MenuItem^>^rPenItems = gcnew array<Windows::Forms::MenuItem^>(2);
   rPenItems[ 0 ] = thickLineMenuItem;
   rPenItems[ 1 ] = penWidthMenuItem;
   penMenuItem = gcnew Windows::Forms::MenuItem( "Pen",rPenItems );
   
   //View
   toolbarMenuItem = gcnew Windows::Forms::MenuItem( "Toolbar",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   toolbarMenuItem->Checked = true;
   statusbarMenuItem = gcnew Windows::Forms::MenuItem( "Statusbar",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   statusbarMenuItem->Checked = true;
   array<Windows::Forms::MenuItem^>^rviewItems = gcnew array<Windows::Forms::MenuItem^>(2);
   rviewItems[ 0 ] = toolbarMenuItem;
   rviewItems[ 1 ] = statusbarMenuItem;
   viewMenuItem = gcnew Windows::Forms::MenuItem( "View",rviewItems );
   
   //Windows
   newWindowMenuItem = gcnew Windows::Forms::MenuItem( "New Window",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   cascadeMenuItem = gcnew Windows::Forms::MenuItem( "Cascade",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   tileMenuItem = gcnew Windows::Forms::MenuItem( "Tile",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   array<Windows::Forms::MenuItem^>^rwindowItems = gcnew array<Windows::Forms::MenuItem^>(3);
   rwindowItems[ 0 ] = newWindowMenuItem;
   rwindowItems[ 1 ] = cascadeMenuItem;
   rwindowItems[ 2 ] = tileMenuItem;
   windowMenuItem = gcnew Windows::Forms::MenuItem( "Window",rwindowItems );
   
   //Help
   helpTopicsMenuItem = gcnew Windows::Forms::MenuItem( "Help Topics",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   helpAboutMenuItem = gcnew Windows::Forms::MenuItem( "About Scribble",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   helpUnmanagedStringMenuItem = gcnew Windows::Forms::MenuItem("GetUnmanagedString",gcnew EventHandler( this, &MainWindow::MenuItemHandler ) );
   array<Windows::Forms::MenuItem^>^rhelpItems = gcnew array<Windows::Forms::MenuItem^>(3);
   rhelpItems[ 0 ] = helpTopicsMenuItem;
   rhelpItems[ 1 ] = helpAboutMenuItem;
   rhelpItems[ 2 ] = helpUnmanagedStringMenuItem;
   helpMenuItem = gcnew Windows::Forms::MenuItem( "Help",rhelpItems );
   
   //MainMenu
   array<Windows::Forms::MenuItem^>^rMainItems = gcnew array<Windows::Forms::MenuItem^>(6);
   rMainItems[ 0 ] = fileMenuItem;
   rMainItems[ 1 ] = editMenuItem;
   rMainItems[ 2 ] = penMenuItem;
   rMainItems[ 3 ] = viewMenuItem;
   rMainItems[ 4 ] = windowMenuItem;
   rMainItems[ 5 ] = helpMenuItem;
   mainMenu = gcnew MainMenu( rMainItems );
   Menu = mainMenu;
   
   //toolbar and status bar
   statusBar1 = gcnew Windows::Forms::StatusBar;
   statusBar1->TabIndex = 2;
   statusBar1->Text =  "For Help,  press F1";
   helpButton = gcnew Windows::Forms::ToolBarButton;
   helpButton->ImageIndex = 5;
   helpButton->ToolTipText =  "Help";
   printButton = gcnew Windows::Forms::ToolBarButton;
   printButton->ImageIndex = 4;
   printButton->ToolTipText =  "Print";
   previewButton = gcnew Windows::Forms::ToolBarButton;
   previewButton->ImageIndex = 3;
   previewButton->ToolTipText =  "Print Preview";
   saveButton = gcnew Windows::Forms::ToolBarButton;
   saveButton->ImageIndex = 2;
   saveButton->ToolTipText =  "Save";
   openButton = gcnew Windows::Forms::ToolBarButton;
   openButton->ImageIndex = 1;
   openButton->ToolTipText =  "Open";
   newButton = gcnew Windows::Forms::ToolBarButton;
   newButton->ImageIndex = 0;
   newButton->ToolTipText =  "New";
   
   imageList1 = gcnew Windows::Forms::ImageList;
   imageList1->ImageSize = System::Drawing::Size( 16, 16 );
   imageList1->TransparentColor = System::Drawing::Color::Transparent;
   
   Assembly^ SampleAssembly;
   SampleAssembly = Assembly::GetAssembly( this->GetType() );

   ResourceManager^ rm = gcnew ResourceManager("Scribble.Scribble", SampleAssembly);

   imageList1->Images->Add( (Bitmap^)rm->GetObject("NEW") ); 
   imageList1->Images->Add( (Bitmap^)rm->GetObject("OPEN") );
   imageList1->Images->Add( (Bitmap^)rm->GetObject("SAVE") );
   imageList1->Images->Add( (Bitmap^)rm->GetObject("PREVIEW") );
   imageList1->Images->Add( (Bitmap^)rm->GetObject("PRINT") );
   imageList1->Images->Add( (Bitmap^)rm->GetObject("HELP") );

   toolBar1 = gcnew Windows::Forms::ToolBar;
   toolBar1->ImageList = imageList1;
   toolBar1->DropDownArrows = true;
   toolBar1->ShowToolTips = true;
   array<System::Windows::Forms::ToolBarButton^>^rToolbarButtons = gcnew array<System::Windows::Forms::ToolBarButton^>(6);
   rToolbarButtons[ 0 ] = newButton;
   rToolbarButtons[ 1 ] = openButton;
   rToolbarButtons[ 2 ] = saveButton;
   rToolbarButtons[ 3 ] = previewButton;
   rToolbarButtons[ 4 ] = printButton;
   rToolbarButtons[ 5 ] = helpButton;
   toolBar1->Buttons->AddRange( rToolbarButtons );
   toolBar1->ButtonClick += gcnew System::Windows::Forms::ToolBarButtonClickEventHandler( this, &MainWindow::ToolbarHandler );
   array<Control^>^rControls = gcnew array<Control^>(2);
   rControls[ 0 ] = statusBar1;
   rControls[ 1 ] = toolBar1;
   this->Controls->AddRange( rControls );
}

void MainWindow::MenuItemHandler( Object^ sender, EventArgs^ /* e */)
{
   if ( sender->Equals( newMenuItem ) )
   {
      New();
   }
   else
   if ( sender->Equals( openMenuItem ) )
   {
      Open();
   }
   else
   if ( sender->Equals( saveMenuItem ) )
   {
      Save();
   }
   else
   if ( sender->Equals( printPreviewMenuItem ) )
   {
      PrintPreview();
   }
   else
   if ( sender->Equals( printMenuItem ) )
   {
      Print();
   }
   else
   if ( sender->Equals( helpAboutMenuItem ) )
   {
      AboutHelp();
   }
   else
   if ( sender->Equals( exitMenuItem ) )
   {
      Exit();
   }
   else
   if ( sender->Equals( closeMenuItem ) )
   {
      CloseView();
   }
   else
   if ( sender->Equals( tileMenuItem ) )
   {
      Tile();
   }
   else
   if ( sender->Equals( cascadeMenuItem ) )
   {
      Cascade();
   }
   else
   if ( sender->Equals( clearAllMenuItem ) )
   {
      ClearAll();
   }
   else
   if ( sender->Equals( saveAsMenuItem ) )
   {
      Save();
   }
   else
   if ( sender->Equals( newWindowMenuItem ) )
   {
      NewWindow();
   }
   else
   if ( sender->Equals( penWidthMenuItem ) )
   {
      PenWidthsDlg();
   }
   else
   if ( sender->Equals( thickLineMenuItem ) )
   {
      ThickLine();
   }
   else
   if ( sender->Equals( helpTopicsMenuItem ) )
   {
      HelpTopics();
   }
   else
   if ( sender->Equals( toolbarMenuItem ) )
   {
      toolBar1->Visible =  !toolBar1->Visible;
      toolbarMenuItem->Checked = toolBar1->Visible;
   }
   else
   if ( sender->Equals( statusbarMenuItem ) )
   {
      statusBar1->Visible =  !statusBar1->Visible;
      statusbarMenuItem->Checked = statusBar1->Visible;
   }
   #ifndef _M_CEE_SAFE
   else
   if ( sender->Equals( helpUnmanagedStringMenuItem ) )
   {
      StringDialog ^sd = gcnew StringDialog();
	  sd->ShowDialog();
   }
#endif
}

void MainWindow::ToolbarHandler( Object^ /* sender */, ToolBarButtonClickEventArgs^ e )
{
   
   // Evaluate the Button property to determine which button was clicked.
   switch ( this->toolBar1->Buttons->IndexOf( e->Button ) )
   {
      case 0:
         New();
         break;

      case 1:
         Open();
         break;

      case 2:
         Save();
         break;

      case 3:
         PrintPreview();
         break;

      case 4:
         Print();
         break;

      case 5:
         HelpTopics();
         break;

      default:
         break;
   }
}


//About Scribble
void MainWindow::AboutHelp()
{
   MessageBox::Show( "Scribble Version 1.0", "About Scribble" );
}


//Help Topics
void MainWindow::HelpTopics()
{
   Help::ShowHelp( this, "help\\scribble.chm" );
}


//Print
void MainWindow::Print()
{
   try
   {
      printDoc->Print();
   }
   catch ( Exception^ e ) 
   {
      MessageBox::Show( e->ToString() );
   }

}


//PrintPage 
void MainWindow::ScribblePrintPage( Object^ /* sender */, PrintPageEventArgs^ printEv )
{
   try
   {
      ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
      ScribbleDoc^ activeDoc = activeView->GetDocument();
      for ( int i = 0; i < activeDoc->strokeList->Count; i++ )
      {
         Stroke^ st = dynamic_cast<Stroke^>(activeDoc->strokeList[ i ]);
         st->DrawStroke( printEv->Graphics );

      }
      printEv->HasMorePages = false;
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}


//PrintPreview
void MainWindow::PrintPreview()
{
   try
   {
      PrintPreviewDialog^ prevDlg = gcnew PrintPreviewDialog;
      prevDlg->Document = printDoc;
      prevDlg->Size = System::Drawing::Size( 600, 329 );
      prevDlg->ShowDialog();
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}


//Exit
void MainWindow::Exit()
{
   array<Form^>^childForm = this->MdiChildren;
   
   //Make sure to ask for saving the doc before exiting the app
   for ( int i = 0; i < childForm->Length; i++ )
      childForm[ i ]->Close();
   Application::Exit();
}


//Close
void MainWindow::CloseView()
{
   ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
   activeView->Close();
}


//Tile_Click
void MainWindow::Tile()
{
   this->LayoutMdi( MdiLayout::TileHorizontal );
}


//Cascade_Click
void MainWindow::Cascade()
{
   this->LayoutMdi( MdiLayout::Cascade );
}


//ClearAll
void MainWindow::ClearAll()
{
   ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
   if ( activeView )
   {
      ScribbleDoc^ activeDoc = activeView->GetDocument();
      activeDoc->DeleteContents();
   }
}


//Open
void MainWindow::Open()
{
   OpenFileDialog^ openDlg = gcnew OpenFileDialog;
   openDlg->Filter =  "Scribble Files (*.scb)|*.scb|All Files (*.*)|*.*";
   openDlg->FileName =  "";
   openDlg->DefaultExt =  ".scb";
   openDlg->CheckFileExists = true;
   openDlg->CheckPathExists = true;
   int res = static_cast<int>(openDlg->ShowDialog());
   if ( res == 1 )//TODO: Tarek: DialogResult::OK )
   {
      if (  !(openDlg->FileName)->EndsWith(  ".scb" ) &&  !(openDlg->FileName)->EndsWith(  ".SCB" ) )
            MessageBox::Show(  "Unexpected file format",  "Scribble", MessageBoxButtons::OK );
      else
      {
         ScribbleDoc^ newDoc = CreateDocument();
         newDoc->OpenDocument( openDlg->FileName );
      }
   }
}


//Save
void MainWindow::Save()
{
   try
   {
      ScribbleView^ selectedView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
      SaveFileDialog^ saveDlg = gcnew SaveFileDialog;
      saveDlg->Filter =  "Scribble Files (*.scb)|*.scb|All Files (*.*)|*.*";
      saveDlg->DefaultExt =  ".scb";
      saveDlg->FileName =  "Scribb1.scb";
      int res = static_cast<int>(saveDlg->ShowDialog());
      if ( res == 1 )//TODO: Tarek: DialogResult::OK )
      {
         if ( selectedView )
         {
            ScribbleDoc^ doc = selectedView->GetDocument();
            doc->SaveDocument( saveDlg->FileName );
         }
      }
   }
   catch ( Exception^ ex ) 
   {
      MessageBox::Show( ex->ToString() );
   }

}


//New
void MainWindow::New()
{
   
   //If this is the first child window, enable the Menu and Toolbar items
   if (  !this->ActiveMdiChild )
      EnableItems();

   CreateDocument();
}


//NewWindow
void MainWindow::NewWindow()
{
   ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
   ScribbleView^ newView = gcnew ScribbleView( activeView->GetDocument(),parentWindow );
   newView->GetDocument()->viewList->Add( newView );
   newView->Show();
}


//ThickLine
void MainWindow::ThickLine()
{
   ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
   ScribbleDoc^ activeDoc = activeView->GetDocument();
   activeDoc->thickPen =  !activeDoc->thickPen;
   activeDoc->ReplacePen();
   this->thickLineMenuItem->Checked = activeDoc->thickPen;
}


//PenWidthDlg
void MainWindow::PenWidthsDlg()
{
   Form^ f = gcnew Form;
   
   //Get the document of active view
   ScribbleView^ activeView = dynamic_cast<ScribbleView^>(this->ActiveMdiChild);
   ScribbleDoc^ activeDoc = activeView->GetDocument();
   f->AutoScaleBaseSize = System::Drawing::Size( 5, 13 );
   f->Text =  "Pen Widths";
   f->ClientSize = System::Drawing::Size( 352, 125 );
   Button^ button1 = gcnew Button;
   button1->Location = System::Drawing::Point( 264, 20 );
   button1->Size = System::Drawing::Size( 75, 23 );
   button1->TabIndex = 1;
   button1->Text =  "OK";
   button1->DialogResult = System::Windows::Forms::DialogResult::OK; //Make this "OK" button
   Button^ button2 = gcnew Button;
   button2->Location = System::Drawing::Point( 264, 52 );
   button2->Size = System::Drawing::Size( 75, 23 );
   button2->TabIndex = 6;
   button2->Text =  "Cancel";
   TextBox^ textBox1 = gcnew TextBox;
   textBox1->Location = System::Drawing::Point( 120, 36 );
   textBox1->Text = activeDoc->thinWidth.ToString();
   textBox1->TabIndex = 1;
   textBox1->Size = System::Drawing::Size( 64, 20 );
   TextBox^ textBox2 = gcnew TextBox;
   textBox2->Location = System::Drawing::Point( 120, 76 );
   textBox2->Text = activeDoc->thickWidth.ToString();
   textBox2->TabIndex = 2;
   textBox2->Size = System::Drawing::Size( 64, 20 );
   Label^ label1 = gcnew Label;
   label1->Location = System::Drawing::Point( 16, 36 );
   label1->Text =  "Thin Pen Width:";
   label1->Size = System::Drawing::Size( 88, 16 );
   label1->TabIndex = 3;
   Label^ label2 = gcnew Label;
   label2->Location = System::Drawing::Point( 16, 76 );
   label2->Text =  "Thick Pen Width:";
   label2->Size = System::Drawing::Size( 88, 16 );
   label2->TabIndex = 4;
   f->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
   
   // Set the MaximizeBox to false to remove the maximize box.
   f->MaximizeBox = false;
   
   // Set the MinimizeBox to false to remove the minimize box.
   f->MinimizeBox = false;
   
   // Set the accept button of the form to button1.
   f->AcceptButton = button1;
   
   // Set the cancel button of the form to button2.
   f->CancelButton = button2;
   f->StartPosition = FormStartPosition::CenterScreen;
   f->Controls->Add( button1 );
   f->Controls->Add( button2 );
   f->Controls->Add( label1 );
   f->Controls->Add( label2 );
   f->Controls->Add( textBox1 );
   f->Controls->Add( textBox2 );
   System::Windows::Forms::DialogResult res = f->ShowDialog();
   if ( res == System::Windows::Forms::DialogResult::OK )
   {
      activeDoc->thinWidth = UInt32::Parse( textBox1->Text );
      activeDoc->thickWidth = UInt32::Parse( textBox2->Text );
      activeDoc->ReplacePen();
      f->Close();
   }
}


//Disable the menu and toolbar items when there is no active child form
void MainWindow::DisableItems()
{
   this->editMenuItem->Visible = false;
   this->penMenuItem->Visible = false;
   this->windowMenuItem->Visible = false;
   this->closeMenuItem->Visible = false;
   this->saveAsMenuItem->Visible = false;
   this->saveAsMenuItem->Visible = false;
   this->printMenuItem->Visible = false;
   this->printPreviewMenuItem->Visible = false;
   this->saveButton->Enabled = false;
   this->previewButton->Enabled = false;
   this->printButton->Enabled = false;
}


//Enable the menu and toolbar items when the first child form is created
void MainWindow::EnableItems()
{
   this->editMenuItem->Visible = true;
   this->penMenuItem->Visible = true;
   this->windowMenuItem->Visible = true;
   this->closeMenuItem->Visible = true;
   this->saveAsMenuItem->Visible = true;
   this->saveAsMenuItem->Visible = true;
   this->printMenuItem->Visible = true;
   this->printPreviewMenuItem->Visible = true;
   this->saveButton->Enabled = true;
   this->previewButton->Enabled = true;
   this->printButton->Enabled = true;
}


//Creates a new document
ScribbleDoc^ MainWindow::CreateDocument()
{
   ScribbleDoc^ newDoc = gcnew ScribbleDoc( parentWindow );
   documentCount++;
   return newDoc;
}

[STAThreadAttribute]
#ifndef _M_CEE_SAFE
 int main()
#else
	int main(array<System::String ^> ^)
#endif

{
   Application::Run( gcnew MainWindow );
   return 0;
}

