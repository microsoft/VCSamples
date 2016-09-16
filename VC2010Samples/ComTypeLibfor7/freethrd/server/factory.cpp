/*+==========================================================================
  File:      FACTORY.CPP

  Summary:   Implementation file for the class factories of the FRESERVE
             server.  This server provides the Ball COM component. For
             this component, IClassFactory is implemented in an
             appropriate class factory COM object: CFBall. The COM
             component that can be manufactured by this server is known
             outside the server by its CLSID: CLSID_DllBall.

             For a comprehensive tutorial code tour of this module's
             contents and offerings see the accompanying FRESERVE.TXT
             file. For more specific technical details on the internal
             workings see the comments dispersed throughout the module's
             source code.

  Classes:   CFBall.

  Functions: .

  Origin:    4-6-96: atrent - Editor-inheritance from CAR.CPP in
               the DLLSERVE OLE Tutorial Code Sample.

----------------------------------------------------------------------------
  This file is part of the Microsoft OLE Tutorial Code Samples.

  Copyright (c) Microsoft Corporation, 1996.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
==========================================================================+*/

/*---------------------------------------------------------------------------
  We include WINDOWS.H for all Win32 applications.
  We include OLE2.H because we will be making calls to the OLE Libraries.
  We include APPUTIL.H because we will be building this DLL using
    the convenient Virtual Window and Dialog classes and other
    utility functions in the APPUTIL Library (ie, APPUTIL.LIB).
  We include IBALL.H and BALLGUID.H for the common ball-related Interface
    class, GUID, and CLSID specifications.
  We include SERVER.H because it has the necessary internal class and
    resource definitions for this DLL.
  We include FACTORY.H because it has the necessary internal class factory
    declarations for this DLL component server.  Those factories we will be
    implementing in this module.
  We include BALL.H, for the object class declarations for the COBall
    COM object.
---------------------------------------------------------------------------*/
#include "preserve.h"
#include "factory.h"
#include "ball.h"

/*---------------------------------------------------------------------------
  Implementation the CFBall Class Factory.  CFBall is the COM
  object class for the Class Factory that can manufacture COBall
  COM Components.
---------------------------------------------------------------------------*/

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CFBall

  Summary:  CFBall Constructor. Note the member initializer:
            "m_ImpIClassFactory(this, pUnkOuter, pServer)" which is used
            to pass the 'this', pUnkOuter, and pServer pointers of this
            constructor function to the constructor executed in the
            instantiation of the CImpIClassFactory interface whose
            implementation is nested inside this present object class.

  Args:     IUnknown* pUnkOuter,
              Pointer to the the outer Unknown.  NULL means this COM Object
              is not being Aggregated.  Non NULL means it is being created
              on behalf of an outside COM object that is reusing it via
              aggregation.
            CServer* pServer)
              Pointer to the server's control object.

  Modifies: m_cRefs, m_pUnkOuter.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CFBall::CFBall(
  IUnknown* pUnkOuter,
  CServer* pServer) :
  m_ImpIClassFactory(this, pUnkOuter, pServer)
{
  // Zero the COM object's reference count.
  m_cRefs = 0;

  // No AddRef necessary if non-NULL, as we're nested.
  m_pUnkOuter = pUnkOuter;

  // Init the pointer to the server control object.
  m_pServer = pServer;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::~CFBall

  Summary:  CFBall Destructor.

  Args:     void

  Modifies: .

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CFBall::~CFBall(void)
{
  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::QueryInterface

  Summary:  QueryInterface of the CFBall non-delegating
            IUnknown implementation.

  Args:     REFIID riid,
              [in] GUID of the Interface being requested.
            PPVOID ppv)
              [out] Address of the caller's pointer variable that will
              receive the requested interface pointer.

  Modifies: .

  Returns:  HRESULT
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP CFBall::QueryInterface(
               REFIID riid,
               PPVOID ppv)
{
  HRESULT hr = E_NOINTERFACE;

  if (OwnThis())
  {
    *ppv = NULL;

    if (IID_IUnknown == riid)
      *ppv = this;
    else if (IID_IClassFactory == riid)
      *ppv = &m_ImpIClassFactory;

    if (NULL != *ppv)
    {
      // We've handed out a pointer to the interface so obey the COM rules
      // and AddRef the reference count.
      ((LPUNKNOWN)*ppv)->AddRef();
      hr = NOERROR;
    }

    UnOwnThis();
  }

  return (hr);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::AddRef

  Summary:  AddRef of the CFBall non-delegating IUnknown implementation.

  Args:     void

  Modifies: m_cRefs.

  Returns:  ULONG
              New value of m_cRefs (COM object's reference count).
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) CFBall::AddRef(void)
{
  ULONG cRefs = 0;

  if (OwnThis())
  {
    cRefs = ++m_cRefs;

    UnOwnThis();
  }

  return cRefs;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::Release

  Summary:  Release of the CFBall non-delegating IUnknown implementation.

  Args:     void

  Modifies: m_cRefs.

  Returns:  ULONG
              New value of m_cRefs (COM object's reference count).
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) CFBall::Release(void)
{
  ULONG cRefs = 0;

  if (OwnThis())
  {
    cRefs = --m_cRefs;

    if (0 == cRefs)
    {
      // We've reached a zero reference count for this COM object.
      // So we tell the server housing to decrement its global object
      // count so that the server will be unloaded if appropriate.
      if (NULL != m_pServer)
        m_pServer->ObjectsDown();

      // We artificially bump the main ref count to prevent reentrancy
      // via the main object destructor.  Not really needed in this
      // CFBall but a good practice because we are aggregatable and
      // may at some point in the future add something entertaining like
      // some Releases to the CFBall destructor.
      m_cRefs++;
      UnOwnThis();
      delete this;
    }
    else
      UnOwnThis();
  }

  return cRefs;
}


/*---------------------------------------------------------------------------
  CFBall's nested implementation of the IClassFactory interface
  including Constructor, Destructor, QueryInterface, AddRef, Release,
  CreateInstance, and LockServer methods.
---------------------------------------------------------------------------*/

/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::CImpIClassFactory

  Summary:  Constructor for the CImpIClassFactory interface instantiation.

  Args:     CFBall* pBackObj,
              Back pointer to the parent outer object.
            IUnknown* pUnkOuter,
              Pointer to the outer Unknown.  For delegation.
            CServer* pServer)
              Pointer to the server's control object.

  Modifies: m_pBackObj, m_pUnkOuter, m_pServer.

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CFBall::CImpIClassFactory::CImpIClassFactory(
  CFBall* pBackObj,
  IUnknown* pUnkOuter,
  CServer* pServer)
{
  // Init the Back Object Pointer to point to the parent object.
  m_pBackObj = pBackObj;

  // Init the pointer to the server control object.
  m_pServer = pServer;

  // Init the CImpIClassFactory interface's delegating Unknown pointer.
  // We use the Back Object pointer for IUnknown delegation here if we are
  // not being aggregated.  If we are being aggregated we use the supplied
  // pUnkOuter for IUnknown delegation.  In either case the pointer
  // assignment requires no AddRef because the CImpIClassFactory lifetime is
  // quaranteed by the lifetime of the parent object in which
  // CImpIClassFactory is nested.
  if (NULL == pUnkOuter)
    m_pUnkOuter = pBackObj;
  else
    m_pUnkOuter = pUnkOuter;

  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::~CImpIClassFactory

  Summary:  Destructor for the CImpIClassFactory interface instantiation.

  Args:     void

  Modifies: .

  Returns:  void
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
CFBall::CImpIClassFactory::~CImpIClassFactory(void)
{
  return;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::QueryInterface

  Summary:  The QueryInterface IUnknown member of this IClassFactory
            interface implementation that delegates to m_pUnkOuter,
            whatever it is.

  Args:     REFIID riid,
              [in] GUID of the Interface being requested.
            PPVOID ppv)
              [out] Address of the caller's pointer variable that will
              receive the requested interface pointer.

  Modifies: .

  Returns:  HRESULT
              Returned by the delegated outer QueryInterface call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP CFBall::CImpIClassFactory::QueryInterface(
               REFIID riid,
               PPVOID ppv)
{
  // Delegate this call to the outer object's QueryInterface.
  return m_pUnkOuter->QueryInterface(riid, ppv);
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::AddRef

  Summary:  The AddRef IUnknown member of this IClassFactory interface
            implementation that delegates to m_pUnkOuter, whatever it is.

  Args:     void

  Modifies: .

  Returns:  ULONG
              Returned by the delegated outer AddRef call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) CFBall::CImpIClassFactory::AddRef(void)
{
  // Delegate this call to the outer object's AddRef.
  return m_pUnkOuter->AddRef();
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::Release

  Summary:  The Release IUnknown member of this IClassFactory interface
            implementation that delegates to m_pUnkOuter, whatever it is.

  Args:     void

  Modifies: .

  Returns:  ULONG
              Returned by the delegated outer Release call.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP_(ULONG) CFBall::CImpIClassFactory::Release(void)
{
  // Delegate this call to the outer object's Release.
  return m_pUnkOuter->Release();
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::CreateInstance

  Summary:  The CreateInstance member method of this IClassFactory
            interface implementation.  Creates an instance of the COBall
            COM component.

  Args:     IUnknown* pUnkOuter,
              [in] Pointer to the controlling IUnknown.
            REFIID riid,
              [in] GUID of the Interface being requested.
            PPVOID ppvCob)
              [out] Address of the caller's pointer variable that will
              receive the requested interface pointer.

  Modifies: .

  Returns:  HRESULT
              Standard OLE result code.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP CFBall::CImpIClassFactory::CreateInstance(
               IUnknown* pUnkOuter,
               REFIID riid,
               PPVOID ppv)
{
  HRESULT hr = E_FAIL;
  COBall* pCob = NULL;

  // NULL the output pointer.
  *ppv = NULL;

  // If the creation call is requesting aggregation (pUnkOuter != NULL),
  // the COM rules state the IUnknown interface MUST also be concomitantly
  // be requested.  If it is not so requested (riid != IID_IUnknown) then
  // an error must be returned indicating that no aggregate creation of
  // the CFBall COM Object can be performed.
  if (NULL != pUnkOuter && riid != IID_IUnknown)
    hr = CLASS_E_NOAGGREGATION;
  else
  {
    // Instantiate a COBall COM Object.
    pCob = new COBall(pUnkOuter, m_pServer);
    if (NULL != pCob)
    {
      // We initially created the new COM object so tell the server
      // to increment its global server object count to help ensure
      // that the server remains loaded until this partial creation
      // of a COM component is completed.
      m_pServer->ObjectsUp();

      // We QueryInterface this new COM Object not only to deposit the
      // main interface pointer to the caller's pointer variable, but to
      // also automatically bump the Reference Count on the new COM
      // Object after handing out this reference to it.
      hr = pCob->QueryInterface(riid, (PPVOID)ppv);
      if (FAILED(hr))
      {
        m_pServer->ObjectsDown();
        delete pCob;
      }
      
    }
    else
      hr = E_OUTOFMEMORY;
  }

  return hr;
}


/*M+M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M+++M
  Method:   CFBall::CImpIClassFactory::LockServer

  Summary:  The LockServer member method of this IClassFactory interface
            implementation.

  Args:     BOOL fLock)
              [in] Flag determining whether to Lock or Unlock the server.

  Modifies: .

  Returns:  HRESULT
              Standard OLE result code.
M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M---M-M*/
STDMETHODIMP CFBall::CImpIClassFactory::LockServer(
               BOOL fLock)
{
  HRESULT hr = NOERROR;

  if (fLock)
    m_pServer->Lock();
  else
    m_pServer->Unlock();

  return hr;
}
