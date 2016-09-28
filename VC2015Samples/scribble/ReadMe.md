# SCRIBBLE Sample: MFC MDI Drawing Application
## SCRIBBLE Sample: MFC MDI Drawing Application

SCRIBBLE is a small drawing application that lets you draw freehand drawings using the mouse and save the images in a file. The sample provides simple illustrations of a wide breadth of MFC features:  


Application objects


Documents, views, and document templates

Commands, message maps, and command user interface updating

MDI (multiple document interface) frame and child windows

Toolbars and status bars

Update hints from documents to views

Dialog boxes, data exchange, and validation

Scroll view

Splitter window

Printing and print preview

Refer to other MFC samples for illustrations of advanced use of these features.SCRIBBLE also includes Visual Editing server functionality.
#### Security Note This sample code is provided to illustrate a concept and should not be used in applications or Web sites, as it may not illustrate the safest coding practices.
## Building and Running the Sample

To build and run the SCRIBBLE sample

1. Open the solution Scribble.sln. 


2. On the Build menu, click Build. 


3. On the Debug menu, click Start Without Debugging


## Other Versions of Scribble

Scribble is also available as a Managed Extensions for C++ sample and as a Visual C# sample:  

Scribble Sample: MDI Drawing Application Using Managed Extensions for C++

Scribble Sample: Visual C# MDI Drawing Application
The SCRIBBLE sample demonstrates the following keywords:
AfxMessageBox; AfxOleInit; CArchive::IsStoring; CCmdUI::Enable; CCmdUI::SetCheck; CControlBar::EnableDocking; CControlBar::GetBarStyle; CControlBar::SetBarStyle; CDC::DPtoLP; CDC::GetDeviceCaps; CDC::GetTextMetrics; CDC::LPtoDP; CDC::LPtoHIMETRIC; CDC::LineTo; CDC::MoveTo; CDC::SelectObject; CDC::SetMapMode; CDC::SetTextAlign; CDC::SetViewportExt; CDC::SetWindowExt; CDC::SetWindowOrg; CDC::TextOut; CDialog::DoModal; CDocTemplate::SetServerInfo; CDocument::DeleteContents; CDocument::GetFirstViewPosition; CDocument::GetNextView; CDocument::OnNewDocument; CDocument::OnOpenDocument; CDocument::SetModifiedFlag; CDocument::UpdateAllViews; CFont::CreateFontIndirect; CFrameWnd::Create; CFrameWnd::DockControlBar; CFrameWnd::EnableDocking; CFrameWnd::LoadFrame; CFrameWnd::OnCreateClient; CObList::GetHeadPosition; CObList::GetNext; CObject::AssertValid; CObject::Dump; CObject::IsKindOf; CObject::Serialize; COleDocument::EnableCompoundFile; COleIPFrameWnd::OnCreateControlBars; COleServerDoc::GetEmbeddedItem; COleServerDoc::GetZoomFactor; COleServerDoc::NotifyChanged; COleServerDoc::OnGetEmbeddedItem; COleServerDoc::OnSetItemRects; COleServerItem::CopyToClipboard; COleServerItem::GetDocument; COleServerItem::IsLinkedItem; COleServerItem::OnDraw; COleServerItem::OnGetExtent; COleTemplateServer::ConnectTemplate; COleTemplateServer::UpdateRegistry; CPen::CreatePen; CRect::InflateRect; CRect::IntersectRect; CRect::SetRectEmpty; CScrollView::SetScrollSizes; CSplitterWnd::Create; CStatusBar::Create; CStatusBar::SetIndicators; CToolBar::Create; CView::DoPreparePrinting; CView::GetDocument; CView::OnBeginPrinting; CView::OnDraw; CView::OnEndPrinting; CView::OnInitialUpdate; CView::OnPrepareDC; CView::OnPreparePrinting; CView::OnPrint; CView::OnUpdate; CWinApp::AddDocTemplate; CWinApp::InitInstance; CWinApp::LoadStdProfileSettings; CWnd::DoDataExchange; CWnd::GetCapture; CWnd::Invalidate; CWnd::InvalidateRect; CWnd::OnCreate; CWnd::OnLButtonDown; CWnd::OnLButtonUp; CWnd::OnMouseMove; CWnd::OnSize; CWnd::PreCreateWindow; CWnd::SetCapture; CWnd::SetOwner; CWnd::ShowWindow; CWnd::UpdateWindow; CreatePen; DeleteObject; DragAcceptFiles; GetClipBox; LPtoDP; RGB; ReleaseCapture; SetRectEmpty; max; memset; min
