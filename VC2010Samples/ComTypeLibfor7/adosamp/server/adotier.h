// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

#if !defined(AFX_ADOTIER_H__7A3199A3_48C0_11D0_AE70_00C04FD7D06E__INCLUDED_)
#define AFX_ADOTIER_H__7A3199A3_48C0_11D0_AE70_00C04FD7D06E__INCLUDED_

// ADOTier.h : Declaration of the CADOTier


#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// ADOSamp

class CADOTier :
	public IDispatchImpl<IADOTier, &IID_IADOTier, &LIBID_ADOSAMPLib>,
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CADOTier,&CLSID_CADOTier>
{
public:
	CADOTier() {}
BEGIN_COM_MAP(CADOTier)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IADOTier)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CADOTier)
// Remove the comment from the line above if you don't want your object to
// support aggregation or if you want to provide support for
// Microsoft Transaction Server. The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_ADOTier)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IADOTier
public:
	STDMETHOD(get_Empty)(VARIANT_BOOL* bEmpty);
	STDMETHOD(ADORelease)();
	STDMETHOD(Requery)();
	STDMETHOD(ChangeParameter)(long idx, enum DataTypeEnum type, VARIANT value, enum ParameterDirectionEnum where, long size);
	STDMETHOD(put_StoredProc)(BSTR newVal);
	STDMETHOD(CallStoredProc)(long idx1, BSTR idx2, BSTR idx3);
	STDMETHOD(ParamQuery)(BSTR query, long idx1, BSTR idx2, BSTR idx3);
	STDMETHOD(get_BOF)(VARIANT_BOOL *newVal);
	STDMETHOD(get_EOF)(VARIANT_BOOL *newVal);
	STDMETHOD(Prev)();
	STDMETHOD(Last)();
	STDMETHOD(Next)();
	STDMETHOD(First)();
	STDMETHOD(Close)();
	STDMETHOD(get_FieldCount)(long *newVal);
	STDMETHOD(get_Field)(VARIANT idx, VARIANT *newVal);
	STDMETHOD(put_Field)(VARIANT idx, VARIANT newVal);
	STDMETHOD(Delete)();
	STDMETHOD(Update)();
	STDMETHOD(AppendParameter)(enum DataTypeEnum type, VARIANT value, enum ParameterDirectionEnum where, long size);
	STDMETHOD(get_CommandText)(BSTR *newVal);
	STDMETHOD(put_CommandText)(BSTR newVal);
	STDMETHOD(ExecuteCommand)(VARIANT_BOOL bStoredProcedure, VARIANT_BOOL bChangeRec = VARIANT_FALSE);
	STDMETHOD(ExecuteConnection)(BSTR query, VARIANT_BOOL bChangeRec = VARIANT_FALSE);
	STDMETHOD(CloseRecordset)(void);
	STDMETHOD(OpenRecordset)(VARIANT query);
	STDMETHOD(Open)(BSTR source, BSTR user, BSTR pwd);
private:
	_CommandPtr m_command;
	_RecordsetPtr m_recordset;
	_ConnectionPtr m_connection;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOTIER_H__7A3199A3_48C0_11D0_AE70_00C04FD7D06E__INCLUDED)
