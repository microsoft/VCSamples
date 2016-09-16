/*+==========================================================================
  File:      FACTORY.H

  Summary:   Include file for the class factory COM object: CFBall. This
             constitutes the FRESERVE server's class factory for this COM
             component.

             The multiple interface COM Object Classe is achieved via
             the technique of nested classes: the implementation of the
             IClassFactory interface is nested inside of the class
             factory COM object class.

             For a comprehensive tutorial code tour of this module's
             contents and offerings see the accompanying FRESERVE.TXT file.
             For more specific technical details on the internal workings
             see the comments dispersed throughout the module's source code.

  Classes:   CFBall.

  Functions: .

  Origin:    4-5-96: atrent - Editor-inheritance from FACTORY.H in
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

#if !defined(FACTORY_H)
#define FACTORY_H

#ifdef __cplusplus

/*O+O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O+++O
  ObjectClass: CFBall

  Summary:     Class Factory COM Object Class for Ball COM components.
               Used to manufacture COBall COM objects.  The mulitple
               interfaces on this COM object class are constructed via
               the nested interface classes technique.

  Interfaces:  IUnknown
                 Standard interface providing COM object features.
               IClassFactory
                 Standard interface providing COM Class Factory features.

  Aggregation: Yes, CFBall COM objects are aggregatable by
               passing a non-NULL pUnkOuter IUnknown pointer into the
               constructor.
O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O---O-O*/
class CFBall : public IUnknown, public CThreaded
{
  public:
    // Main Object Constructor & Destructor.
    CFBall(IUnknown* pUnkOuter, CServer* pServer);
    ~CFBall(void);

    // IUnknown methods. Main object, non-delegating.
    STDMETHODIMP         QueryInterface(REFIID, PPVOID);
    STDMETHODIMP_(ULONG) AddRef(void);
    STDMETHODIMP_(ULONG) Release(void);

    // We declare nested class interface implementations here.

    // We implement the IClassFactory interface (ofcourse) in this class
    // factory COM object class.
    class CImpIClassFactory : public IClassFactory, public CThreaded
    {
      public:
        // Interface Implementation Constructor & Destructor.
        CImpIClassFactory(
          CFBall* pBackObj,
          IUnknown* pUnkOuter,
          CServer* pServer);
        ~CImpIClassFactory(void);

        // IUnknown methods.
        STDMETHODIMP         QueryInterface(REFIID, PPVOID);
        STDMETHODIMP_(ULONG) AddRef(void);
        STDMETHODIMP_(ULONG) Release(void);

        // IClassFactory methods.
        STDMETHODIMP         CreateInstance(IUnknown*, REFIID, PPVOID);
        STDMETHODIMP         LockServer(BOOL);

      private:
        // Data private to this interface implementation of IClassFactory.
        CFBall*       m_pBackObj;    // Parent Object back pointer.
        IUnknown*     m_pUnkOuter;   // Outer unknown for Delegation.
        CServer*      m_pServer;     // Server's control object.
    };

    // Make the otherwise private and nested IClassFactory interface
    // implementation a friend to COM object instantiations of this
    // selfsame CFBall COM object class.
    friend CImpIClassFactory;

  private:
    // Private data of CFBall COM objects.

    // Nested IClassFactory implementation instantiation.
    CImpIClassFactory m_ImpIClassFactory;

    // Main Object reference count.
    ULONG             m_cRefs;

    // Outer unknown (aggregation & delegation). Used when this
    // CFBall object is being aggregated.  Otherwise it is used
    // for delegation if this object is reused via containment.
    IUnknown*         m_pUnkOuter;

    // Pointer to this component server's control object.
    CServer*          m_pServer;
};

typedef CFBall* PCFBall;


#endif // __cplusplus


#endif // FACTORY_H
