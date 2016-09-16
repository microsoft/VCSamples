///////////////////////////////////////////////////////////////////////////////////
// IDrawServ : IDispatch (Dual)

template <class T>
class CProxyIDrawServ :
    public IConnectionPointImpl<T, &IID_IDrawServ, CComDynamicUnkArray>
{
public:
//  CProxyIDrawServ(IConnectionPointContainer* pCont) :
//      CComConnectionPoint< CComDynamicArrayCONNECTDATA >(pCont, &IID_IDrawServ)
//  {
//  }

public:
    HRESULT Draw(
        long x1, long y1,
        long x2, long y2,
        unsigned long col)
    {
        T* pT = (T*)this;
        pT->Lock();
        HRESULT hr = S_OK;
        IUnknown** pp = m_vec.begin();
        IUnknown** ppEnd = m_vec.end();
        while (pp < ppEnd && hr == S_OK)
        {
            if (*pp != NULL)
            {
                IDrawServ* pIDrawServ = (IDrawServ*)*pp;
                hr = pIDrawServ->Draw(x1, y1, x2, y2, col);
            }
            pp++;
        }
        pT->Unlock();
        return hr;
    }
};
