// ATLButniface.h : AtlButton interface definition using attributes
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

[
	dispinterface,
	uuid(20D4CB52-DEC1-4696-A2D8-42ACBC19ECCC),
	helpstring("Event interface for ATL button control") 
]
__interface _ATLButton : IDispatch
{
	[id(1)] void OnClick();
};



[
	object,
	uuid(00886616-BFB4-4697-837C-D75C9916B016),
	dual,
	helpstring("IAtlButton Interface"),
	pointer_default(unique)
]
__interface IAtlButton : IDispatch
{
	[propputref, id(3)]
	HRESULT PictureStatic([in]IPictureDisp* pPicture);
	[propput, id(3)]
	HRESULT PictureStatic([in]IPictureDisp* pPicture);
	[propget, id(3)]
	HRESULT PictureStatic([out, retval]IPictureDisp** ppPicture);

	[propputref, id(4)]
	HRESULT PictureHover([in]IPictureDisp* pPicture);
	[propput, id(4)]
	HRESULT PictureHover([in]IPictureDisp* pPicture);
	[propget, id(4)]
	HRESULT PictureHover([out, retval]IPictureDisp** ppPicture);

	[propputref, id(5)]
	HRESULT PicturePush([in]IPictureDisp* pPicture);
	[propput, id(5)]
	HRESULT PicturePush([in]IPictureDisp* pPicture);
	[propget, id(5)]
	HRESULT PicturePush([out, retval]IPictureDisp** ppPicture);

	HRESULT _OnTimer();
};
