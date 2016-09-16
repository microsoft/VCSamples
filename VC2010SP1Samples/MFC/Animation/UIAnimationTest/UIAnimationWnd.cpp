// UIAnimationWnd.cpp : implementation file
//

#include "stdafx.h"
#include "UIAnimationWnd.h"
#include "AFXTrackMouse.h"

static const int cnMarginX = 4;
static const int cnMarginY = 6;

static int GetTabHeight()
{
    return afxGlobalData.GetTextHeight() + cnMarginY * 2;
}

static void PrepareBitmap(CWnd* pWnd, CDC* pDC)
{
    pWnd->SendMessage(WM_PRINT, (WPARAM)pDC->GetSafeHdc(), (LPARAM)(PRF_CLIENT | PRF_ERASEBKGND | PRF_CHILDREN | PRF_NONCLIENT));

    if (pWnd->IsKindOf(RUNTIME_CLASS(CRichEditCtrl)))
    {
        CRect rectClient;
        pWnd->GetClientRect(rectClient);
        pDC->FillRect(rectClient, &afxGlobalData.brWindow);

        CRichEditCtrl* pRichEditCtrl = (CRichEditCtrl*)pWnd;

        CRect rectEdit;
        pRichEditCtrl->GetRect(rectEdit);

        CRect rcPage(rectEdit.left, rectEdit.top, 
            ::MulDiv(rectEdit.Width(), 1440, pDC->GetDeviceCaps(LOGPIXELSX)),
            ::MulDiv(rectEdit.Height(), 1440, pDC->GetDeviceCaps(LOGPIXELSY)));

        FORMATRANGE fr;
        fr.hdcTarget = pDC->m_hAttribDC;
        fr.hdc       = pDC->m_hDC;
        fr.rcPage    = rcPage;
        fr.rc        = rcPage;

        fr.chrg.cpMin = pRichEditCtrl->LineIndex(pRichEditCtrl->GetFirstVisibleLine());
        fr.chrg.cpMax = 0xFFFFFFFF;

        pRichEditCtrl->FormatRange(NULL, FALSE);
        pRichEditCtrl->FormatRange(&fr, TRUE);
        pRichEditCtrl->FormatRange(NULL, FALSE);
    }
}

static const COLORREF clrBorder = RGB(133, 158, 191);
static const D2D1_GRADIENT_STOP gradientBorder[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(clrBorder, 0)},
    {0.5f, CRenderTarget::COLORREF_TO_D2DCOLOR(clrBorder, 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(clrBorder, 0)}
};
static const D2D1_GRADIENT_STOP gradientControl[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(205, 220, 237), 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(181, 200, 223), 255)}
};
static const D2D1_GRADIENT_STOP gradientTabs[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(181, 200, 223), 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(174, 194, 219), 255)}
};
static const D2D1_GRADIENT_STOP gradient[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(205, 220, 237), 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(174, 194, 219), 255)}
};
static const COLORREF clrText[2] = {RGB(0, 25, 56), RGB(30, 57, 91)};

static const COLORREF clrBorderTab[] = {RGB(194, 138, 48), RGB(236, 199, 87)};
static const D2D1_GRADIENT_STOP gradientTab_H[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(248, 225, 135), 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(251, 249, 224), 255)}
};
static const D2D1_GRADIENT_STOP gradientTab_S[] =
{
    {0.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(255, 216, 107), 255)},
    {1.0f, CRenderTarget::COLORREF_TO_D2DCOLOR(RGB(255, 244, 128), 255)}
};

// CUIAnimationWnd

IMPLEMENT_DYNAMIC(CUIAnimationWnd, CWnd)

CUIAnimationWnd::CUIAnimationWnd()
    : m_rectTabs               (0, 0, 0, 0)
    , m_nCurSel                (-1)
    , m_nHighlighted           (-1)
    , m_bTracked               (FALSE)
    , m_Animation              (e_AnimationNone)
    , m_AnimationTypeSelect    (0)
    , m_AnimationDurationSelect(0.5)
    , m_AnimationValueFade     (0.0, 0)
    , m_AnimationValueSlide    (CPoint(0, 0), 0)
    , m_AnimationValueScale    (0.0, 0)
    , m_bTabHorz               (FALSE)
{
    EnableD2DSupport();

    m_AnimationController.SetRelatedWnd(this);
    m_AnimationController.EnableAnimationTimerEventHandler();

    CAnimationGroup* pGroup = m_AnimationController.AddAnimationObject(&m_AnimationValueFade);

    m_AnimationController.AddAnimationObject(&m_AnimationValueSlide);
    m_AnimationController.AddAnimationObject(&m_AnimationValueScale);

    // because all objects in this group are created as class members, they will be 
    // destroyed with the class, so the Animation Group shouldn't take care of them
    pGroup->m_bAutodestroyAnimationObjects = FALSE;

    for (int i = 0; i < 2; i++)
    {
        m_bmpD2D[i] = NULL;
    }

	m_pBrushBorder = new CD2DSolidColorBrush (GetRenderTarget(), clrBorder);
	m_pBrushTabBorder = new CD2DSolidColorBrush (GetRenderTarget(), clrBorderTab[0]);
	m_pBrushWhite = new CD2DSolidColorBrush (GetRenderTarget(), RGB(255, 255, 255), 128);

    m_pBrushTextRegular = new CD2DSolidColorBrush(GetRenderTarget(), clrText[0]);
    m_pBrushTextBold = new CD2DSolidColorBrush(GetRenderTarget(), clrText[1]);

	D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES emptyProps = D2D1::LinearGradientBrushProperties (CD2DPointF(0., 0.), CD2DPointF(0., 0.));

	m_pBrushFill = new CD2DLinearGradientBrush (GetRenderTarget(), gradientControl, ARRAYSIZE(gradientControl), emptyProps);
    m_pBrushTab = new CD2DLinearGradientBrush (GetRenderTarget(), gradientTabs, ARRAYSIZE(gradientTabs), emptyProps);
    m_pBrushSelectedTabBack = new CD2DLinearGradientBrush (GetRenderTarget(), gradientTab_S, ARRAYSIZE(gradientTab_S), emptyProps);
}

CUIAnimationWnd::~CUIAnimationWnd()
{
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
        if (m_arWindows[i] != NULL)
        {
            delete m_arWindows[i];
        }
    }

    ClearBitmaps();
}

BEGIN_MESSAGE_MAP(CUIAnimationWnd, CWnd)
    ON_WM_MOUSEMOVE()
    ON_WM_MOUSELEAVE()
    ON_WM_LBUTTONDOWN()
    ON_WM_SETCURSOR()
    ON_WM_SIZE()
	ON_REGISTERED_MESSAGE(AFX_WM_DRAW2D, &CUIAnimationWnd::OnDraw2D)
END_MESSAGE_MAP()


BOOL CUIAnimationWnd::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    LPCTSTR lpszClassName = AfxRegisterWndClass(CS_DBLCLKS, ::LoadCursor(NULL, IDC_ARROW), ::GetSysColorBrush(COLOR_3DFACE));
    return CWnd::CreateEx((dwStyle & WS_BORDER) == WS_BORDER ? WS_EX_CLIENTEDGE: 0, lpszClassName, _T(""), (dwStyle & ~WS_BORDER) | WS_CLIPCHILDREN, rect, pParentWnd, nID, NULL);
}


void CUIAnimationWnd::RecalcLayout()
{
    CRect rect;
    GetClientRect(rect);

    CRect rectTabs(m_rectTabs);

    if (GetCount() > 0)
    {
        m_rectTabs = rect;
        if (m_bTabHorz)
        {
            m_rectTabs.top = m_rectTabs.bottom - GetTabHeight();
        }
        else
        {
            m_rectTabs.top = m_rectTabs.bottom - GetTabHeight() * GetCount();
        }
    }
    else
    {
        m_rectTabs.SetRectEmpty();
    }

    if (rectTabs != m_rectTabs && !m_rectTabs.IsRectEmpty())
    {
        RepositionControls();
    }
}


CRect CUIAnimationWnd::GetControlRect() const
{
    CRect rect;
    GetClientRect(rect);

    rect.bottom -= m_rectTabs.Height();

    if (rect.right < rect.left)
    {
        rect.right = rect.left;
    }

    if (rect.bottom < rect.top)
    {
        rect.bottom = rect.top;
    }

    if (rect.Width() > 0 && rect.Height() > 0)
    {
        rect.DeflateRect(1, 1);
    }

    return rect;
}


void CUIAnimationWnd::RepositionControls(CWnd* pWnd/* = NULL*/)
{
    CRect rect(GetControlRect());

    if (pWnd != NULL)
    {
        pWnd->SetWindowPos(this, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOOWNERZORDER);
        return;
    }

    const INT_PTR count = GetCount();
    if (count == 0)
    {
        return;
    }

    HDWP hDWP = ::BeginDeferWindowPos(count);

    for (INT_PTR i = 0; i < GetCount(); i++)
    {
        CWnd* pWnd = m_arWindows[i];
        if (pWnd->GetSafeHwnd() != NULL)
        {
            ::DeferWindowPos (hDWP, pWnd->GetSafeHwnd(), GetSafeHwnd(), rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOZORDER | SWP_NOOWNERZORDER);
        }
    }

    ::EndDeferWindowPos(hDWP);
}


int CUIAnimationWnd::FindIndex(const CWnd* pWnd) const
{
    int index = -1;
    for (INT_PTR i = 0; i < GetCount(); i++)
    {
        if (m_arWindows[i] == pWnd)
        {
            index = (int)i;
            break;
        }
    }

    return index;
}


CWnd* CUIAnimationWnd::GetControl (int index)
{
    if (index < 0 || GetCount() <= (INT_PTR)index)
    {
        ASSERT(FALSE);
        return NULL;
    }

    return m_arWindows[index];
}


CRect CUIAnimationWnd::GetTabRect(int index) const
{
    CRect rect(0, 0, 0, 0);

    INT_PTR count = GetCount();
    if (index < 0 || count <= (INT_PTR)index)
    {
        ASSERT(FALSE);
        return rect;
    }

    if (m_bTabHorz)
    {
        int nDelta = m_rectTabs.Width() / count;
        if (nDelta > 0)
        {
            rect = m_rectTabs;
            rect.left = rect.left + nDelta * index;

            if (count > 1 && index == (count - 1))
            {
                rect.right = m_rectTabs.right;
            }
            else
            {
                rect.right = rect.left + nDelta;
            }
        }
    }
    else
    {
        int nDelta = GetTabHeight();
        rect = m_rectTabs;
        rect.top += nDelta * index;
        rect.bottom = rect.top + nDelta;
    }

    return rect;
}


BOOL CUIAnimationWnd::AddControl(CWnd* pWnd, const CString& strLabel)
{
    if (pWnd == NULL)
    {
        return FALSE;
    }

    if (FindIndex(pWnd) != -1)
    {
        return FALSE;
    }

    m_arWindows.Add(pWnd);
    m_arLabels.Add(strLabel);
    if (m_rectTabs.IsRectEmpty())
    {
        SetCurSel(0);
    }

    CAnimationValue* pValue = new CAnimationValue(0.0, m_arWindows.GetSize());
    m_arAnimationFade_H.Add(pValue);
    
	CAnimationGroup* pGroup = m_AnimationController.AddAnimationObject(pValue);

    pGroup->m_bAutodestroyAnimationObjects = TRUE;

    RecalcLayout();

    return TRUE;
}


void CUIAnimationWnd::ClearBitmaps()
{
    for (int i = 0; i < 2; i++)
    {
        m_bmpControl[i].DeleteObject();

        if (m_bmpD2D[i] != NULL)
        {
            delete m_bmpD2D[i];
            m_bmpD2D[i] = NULL;
        }
    }
}


void CUIAnimationWnd::PrepareBitmaps(int nCurrent, int nNext)
{
    ClearBitmaps();

    if (nCurrent == -1 || nNext == -1)
    {
        return;
    }

    CSize size(GetControlRect().Size());
    if (size.cx == 0 || size.cy == 0)
    {
        return;
    }

    CDC* pDC = GetDC();

    CDC memDC;
    memDC.CreateCompatibleDC(pDC);

    ReleaseDC(pDC);

    LPBYTE lpBits = NULL;
    HBITMAP hBmp = CDrawingManager::CreateBitmap_32(size, (LPVOID*)&lpBits);
    if (hBmp == NULL)
    {
        return;
    }

    m_bmpControl[0].Attach(hBmp);
    CBitmap* pOldBitmap = memDC.SelectObject(&m_bmpControl[0]);
    PrepareBitmap(GetControl(nCurrent), &memDC);
    memDC.SelectObject(pOldBitmap);

    for (int i = 0; i < size.cx * size.cy; i++)
    {
        lpBits[3] = 255;
        lpBits += 4;
    }

    lpBits = NULL;
    hBmp = CDrawingManager::CreateBitmap_32(size, (LPVOID*)&lpBits);
    if (hBmp == NULL)
    {
        m_bmpControl[0].DeleteObject();
        return;
    }

    m_bmpControl[1].Attach(hBmp);
    pOldBitmap = memDC.SelectObject(&m_bmpControl[1]);
    PrepareBitmap(GetControl(nNext), &memDC);
    memDC.SelectObject(pOldBitmap);

    for (int i = 0; i < size.cx * size.cy; i++)
    {
        lpBits[3] = 255;
        lpBits += 4;
    }

    for (int i = 0; i < 2; i++)
    {
        m_bmpD2D[i] = new CD2DBitmap(GetRenderTarget(), (HBITMAP)m_bmpControl[i]);
    }
}


void CUIAnimationWnd::StartAnimation(XAnimation animation)
{

    if (animation != e_AnimationNone && 
        m_bmpControl[0].GetSafeHandle() != NULL && m_bmpControl[1].GetSafeHandle() != NULL)
    {
        StopAnimation();

        m_Animation = animation;
        DWORD type = GetAnimationType();

        if (type != 0)
        {
            CRect rectControl(GetControlRect());

            CPoint ptBegin(0, 0);
            CPoint ptEnd(-1, -1);

            UI_ANIMATION_SECONDS duration = GetAnimationDuration();

            if ((type & e_AnimationTypeFade) == e_AnimationTypeFade)
            {
                m_AnimationValueFade = 0.0;
                m_AnimationValueFade.AddTransition(new CLinearTransition(duration, 1.0));
            }

            if ((type & e_AnimationTypeSlideUp) == e_AnimationTypeSlideUp)
            {
                ptBegin.y = rectControl.Height();
                ptEnd.y = 0;
            }
            else if ((type & e_AnimationTypeSlideDown) == e_AnimationTypeSlideDown)
            {
                ptBegin.y = -rectControl.Height();
                ptEnd.y = 0;
            }

            if ((type & e_AnimationTypeSlideLeft) == e_AnimationTypeSlideLeft)
            {
                ptBegin.x = rectControl.Width();
                ptEnd.x = 0;
            }
            else if ((type & e_AnimationTypeSlideRight) == e_AnimationTypeSlideRight)
            {
                ptBegin.x = -rectControl.Width();
                ptEnd.x = 0;
            }

            if (ptEnd.x != -1 || ptEnd.y != -1)
            {
                CBaseTransition* pTX = NULL;
                if (ptEnd.x != -1)
                {
                    pTX = new CLinearTransition(duration, ptEnd.x);
                }
                CBaseTransition* pTY = NULL;
                if (ptEnd.y != -1)
                {
                    pTY = new CLinearTransition(duration, ptEnd.y);
                }

                m_AnimationValueSlide = ptBegin;
                m_AnimationValueSlide.AddTransition(pTX, pTY);
            }

            if ((type & e_AnimationTypeScale) == e_AnimationTypeScale)
            {
                m_AnimationValueScale = 0.0;
                m_AnimationValueScale.AddTransition(new CLinearTransition(duration, 1.0));
            }
        }
        else
        {
            StopAnimation();
        }

        GetControl(GetCurSel())->ShowWindow(SW_HIDE);

        if (type != 0)
        {
            // illustartes that AnimateGroup and actual Schedule can happen separately. Alternative call is just
            // m_controller.AnimateGroup(0);
            m_AnimationController.AnimateGroup(0, FALSE);
            m_AnimationController.ScheduleGroup(0);
        }
    }
}


void CUIAnimationWnd::StopAnimation()
{
    if (m_Animation != e_AnimationNone)
    {
        m_AnimationController.CleanUpGroup((UINT32)0);

        m_Animation = e_AnimationNone;

        ClearBitmaps();

        CWnd* pWnd = GetControl(GetCurSel());
        pWnd->ShowWindow(SW_SHOW);
        pWnd->SetFocus();
    }
}


void CUIAnimationWnd::SetCurSel(int index)
{
    if (m_Animation == e_AnimationSelect && IsAnimationInProgress())
    {
        return;
    }

    if (index < 0 || GetCount() <= (INT_PTR)index)
    {
        ASSERT(FALSE);
        return;
    }

    int nCurSel = GetCurSel();
    if (nCurSel != index)
    {
        SetHighlighted(-1);
        for (int i = 0; i < m_arAnimationFade_H.GetSize(); i++)
        {
            m_AnimationController.CleanUpGroup((UINT32)i + 1);
            (*m_arAnimationFade_H[i]) = 0.0;
        }

        if (nCurSel != -1)
        {
            PrepareBitmaps(nCurSel, index);
            StartAnimation(e_AnimationSelect);
        }

        m_nCurSel = index;

        if (nCurSel == -1 || m_Animation == e_AnimationNone)
        {
            CWnd* pWnd = GetControl(GetCurSel());
            pWnd->ShowWindow(SW_SHOW);
            pWnd->SetFocus();
        }

        Invalidate();
    }
}


void CUIAnimationWnd::SetHighlighted(int index)
{
    if (GetCount() < 2)
    {
        return;
    }

    int nCurSel = GetCurSel();
    index = (index != nCurSel) ? index : -1;

    if (m_nHighlighted != index)
    {
        CAnimationGroup* pGroup1 = NULL;
        if (m_nHighlighted != -1)
        {
            pGroup1 = m_AnimationController.FindAnimationGroup((UINT32)m_nHighlighted + 1);
            if (pGroup1 != NULL)
            {
                if (pGroup1->m_pStoryboard != NULL)
                {
                    pGroup1->m_pStoryboard->Abandon();
                }
                m_AnimationController.CleanUpGroup((UINT32)m_nHighlighted + 1);
                m_arAnimationFade_H[m_nHighlighted]->AddTransition(new CLinearTransition(0.5, 0.0));
                m_AnimationController.AnimateGroup(pGroup1->GetGroupID(), FALSE);
            }
        }

        m_nHighlighted = index;

        CAnimationGroup* pGroup2 = NULL;
        if (m_nHighlighted != -1)
        {
            pGroup2 = m_AnimationController.FindAnimationGroup((UINT32)m_nHighlighted + 1);
            if (pGroup2 != NULL)
            {
                if (pGroup2->m_pStoryboard != NULL)
                {
                    pGroup2->m_pStoryboard->Abandon();
                }
                m_AnimationController.CleanUpGroup((UINT32)m_nHighlighted + 1);
                m_arAnimationFade_H[m_nHighlighted]->AddTransition(new CLinearTransition(0.5, 1.0));
                m_AnimationController.AnimateGroup(pGroup2->GetGroupID(), FALSE);
            }
        }

        if (pGroup1 != NULL)
        {
            m_AnimationController.ScheduleGroup(pGroup1->GetGroupID());
        }

        if (pGroup2 != NULL)
        {
            m_AnimationController.ScheduleGroup(pGroup2->GetGroupID());
        }

        InvalidateRect(m_rectTabs);
    }
}


int CUIAnimationWnd::HitTest(const CPoint& point) const
{
    int index = -1;

    INT_PTR count = GetCount();
    if (count > 0 && m_rectTabs.PtInRect(point))
    {
        if (m_bTabHorz)
        {
            index = min((int)((point.x - m_rectTabs.left) / ((double)m_rectTabs.Width() / (double)count)), (count - 1));
        }
        else
        {
            index = min((int)((point.y - m_rectTabs.top) / ((double)m_rectTabs.Height() / (double)count)), (count - 1));
        }
    }

    return index;
}


// CUIAnimationWnd message handlers

void CUIAnimationWnd::DoPaintControlD2D(CHwndRenderTarget& renderTarget)
{
    CRect rectBack(GetControlRect());
    DWORD type = GetAnimationType();
    BOOL bBoth = (type & e_AnimationTypeBoth) == e_AnimationTypeBoth;

    float alpha[2] = {1.0f, 1.0f};
    float scale[2] = {1.0f, 1.0f};

    const D2D1::Matrix3x2F matrixI(D2D1::Matrix3x2F::Identity());
    D2D1::Matrix3x2F matrix[2] = {matrixI, matrixI};

    if ((type & e_AnimationTypeFade) == e_AnimationTypeFade)
    {
        alpha[1] = (float)(double)m_AnimationValueFade;
        if (bBoth)
        {
            alpha[0] = 1.0f - alpha[1];
        }
    }

    CPoint pt(m_AnimationValueSlide);

    if ((type & e_AnimationTypeScale) == e_AnimationTypeScale)
    {
        scale[1] = (float)(double)m_AnimationValueScale;
        if (bBoth)
        {
            scale[0] = 1.0f - scale[1];
        }

        if ((type & (e_AnimationTypeSlideUp | e_AnimationTypeSlideDown | e_AnimationTypeSlideLeft | e_AnimationTypeSlideRight)) != 0)
        {
            for (int i = 0; i < 2; i++)
            {
                matrix[i] = matrix[i] * D2D1::Matrix3x2F::Scale
                    (
                        (type & (e_AnimationTypeSlideLeft | e_AnimationTypeSlideRight)) != 0 ? scale[i] : 1.0f, 
                        (type & (e_AnimationTypeSlideUp | e_AnimationTypeSlideDown)) != 0 ? scale[i] : 1.0f
                    );
            }

            if ((type & e_AnimationTypeSlideDown) == e_AnimationTypeSlideDown)
            {
                matrix[0] = matrix[0] * D2D1::Matrix3x2F::Translation(0.0f, bBoth ? (float)(rectBack.Height() + pt.y) : 0.0f);
                matrix[1] = matrix[1] * D2D1::Matrix3x2F::Translation(0.0f, -(float)pt.y);
            }
            if ((type & e_AnimationTypeSlideRight) == e_AnimationTypeSlideRight)
            {
                matrix[0] = matrix[0] * D2D1::Matrix3x2F::Translation(bBoth ? (float)(rectBack.Width() + pt.x) : 0.0f, 0.0f);
                matrix[1] = matrix[1] * D2D1::Matrix3x2F::Translation(-(float)pt.x, 0.0f);
            }
        }
        else
        {
            for (int i = 0; i < 2; i++)
            {
                matrix[i] = matrix[i] * D2D1::Matrix3x2F::Scale(scale[i], scale[i], 
                    D2D1::Point2F(rectBack.Width() / 2.0f, rectBack.Height() / 2.0f));
            }
        }
    }

    if (bBoth)
    {
        CPoint pt0(0, 0);
        if ((type & e_AnimationTypeScale) == 0)
        {
            if ((type & e_AnimationTypeSlideUp) == e_AnimationTypeSlideUp)
            {
                pt0.y = pt.y - rectBack.Height();
            }
            else if ((type & e_AnimationTypeSlideDown) == e_AnimationTypeSlideDown)
            {
                pt0.y = pt.y + rectBack.Height();
            }

            if ((type & e_AnimationTypeSlideLeft) == e_AnimationTypeSlideLeft)
            {
                pt0.x = pt.x - rectBack.Width();
            }
            else if ((type & e_AnimationTypeSlideRight) == e_AnimationTypeSlideRight)
            {
                pt0.x = pt.x + rectBack.Width();
            }
        }

        matrix[0] = matrix[0] * D2D1::Matrix3x2F::Translation((float)pt0.x, (float)pt0.y);
    }
    matrix[1] = matrix[1] * D2D1::Matrix3x2F::Translation((float)pt.x, (float)pt.y);

    CRect rectSrc(rectBack);
    rectSrc.OffsetRect(-rectSrc.TopLeft());
    CRect rectDst(rectBack);

    for (int i = 0; i < 2; i++)
    {
        if (scale[i] > 0.0f && alpha[i] > 0.0f)
        {
            renderTarget.SetTransform(&matrix[i]);
            renderTarget.DrawBitmap(m_bmpD2D[i], rectDst, alpha[i], D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);

            if (scale[i] < 1.0f)
            {
                D2D1_POINT_2F pointLT = matrix[i].TransformPoint(D2D1::Point2F((float)rectDst.left, (float)rectDst.top));
                D2D1_POINT_2F pointRB = matrix[i].TransformPoint(D2D1::Point2F((float)rectDst.right, (float)rectDst.bottom));

                renderTarget.SetTransform(matrixI);
                CD2DSolidColorBrush brush(&renderTarget, clrBorder, (int)(alpha[i] * 255.0f));
                renderTarget.DrawRectangle(CRect((int)pointLT.x, (int)pointLT.y, (int)pointRB.x, (int)pointRB.y), &brush);
            }
        }
    }

    renderTarget.SetTransform(matrixI);
}

void CUIAnimationWnd::DoPaintTabsD2D(CHwndRenderTarget& renderTarget)
{
    CRect rectBack(m_rectTabs);
    CD2DRectF rectBackF(rectBack);

	m_pBrushTab->SetStartPoint(D2D1::Point2F((float)rectBack.left, (float)rectBack.top));
	m_pBrushTab->SetEndPoint(D2D1::Point2F((float)rectBack.left, (float)rectBack.bottom - 0.5f));

    renderTarget.FillRectangle(rectBackF, m_pBrushTab);

    int nSelected = GetCurSel();

    INT_PTR count = GetCount();

    LOGFONT lf;
    afxGlobalData.fontBold.GetLogFont(&lf);
    CD2DTextFormat format(&renderTarget, CString(lf.lfFaceName), (FLOAT)abs(lf.lfHeight), DWRITE_FONT_WEIGHT_BOLD);

    format.Get()->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
    format.Get()->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);

    CSize sizeRound(3, 3);

    const UINT_PTR grCount_H = ARRAYSIZE(gradientTab_H);
    D2D1_GRADIENT_STOP* pGradient_H = new D2D1_GRADIENT_STOP[grCount_H];
    for (UINT_PTR i = 0; i < grCount_H; i++)
    {
        pGradient_H[i] = gradientTab_H[i];
    }

    for (INT_PTR i = 0; i < count; i++)
    {
        CRect rectTabFull(GetTabRect(i));

        CRect rectTab(rectTabFull);
        rectTab.DeflateRect(2, 2);
        rectTab.top--;

        if (i == nSelected)
        {
            rectTab.DeflateRect(1, 1);
            CD2DRectF rectTabF(rectTab);

			m_pBrushSelectedTabBack->SetStartPoint(D2D1::Point2F((float)rectTab.left, (float)rectTab.top));
			m_pBrushSelectedTabBack->SetEndPoint(D2D1::Point2F((float)rectTab.left, (float)rectTab.bottom - 0.5f));

			CD2DRoundedRect rectRounded(rectTabF, sizeRound);

			renderTarget.FillRoundedRectangle(rectRounded, m_pBrushSelectedTabBack);
            renderTarget.DrawRoundedRectangle(rectRounded, m_pBrushWhite);

            rectTab.InflateRect(1, 1);

            renderTarget.DrawRoundedRectangle(CD2DRoundedRect(rectTab, sizeRound), m_pBrushTabBorder);
        }
        else if ((double)(*m_arAnimationFade_H[i]) != 0.0)
        {
            rectTab.DeflateRect(1, 1);
            CD2DRectF rectTabF(rectTab);

            const float alpha = (float)(double)(*m_arAnimationFade_H[i]);
            for (UINT_PTR i = 0; i < grCount_H; i++)
            {
                pGradient_H[i].color.a  = alpha;
            }

			CD2DRoundedRect rectRounded(rectTabF, sizeRound);

            CD2DLinearGradientBrush backBrush(&renderTarget, pGradient_H, grCount_H,
                D2D1::LinearGradientBrushProperties(D2D1::Point2F((float)rectTab.left, (float)rectTab.top), D2D1::Point2F((float)rectTab.left, (float)rectTab.bottom - 0.5f)));
            renderTarget.FillRoundedRectangle(rectRounded, &backBrush);

            CD2DSolidColorBrush brush2(&renderTarget, RGB(255, 255, 255), (int)(alpha * 255));
            renderTarget.DrawRoundedRectangle(rectRounded, &brush2);

            rectTab.InflateRect(1, 1);

            CD2DSolidColorBrush brush1(&renderTarget, clrBorderTab[1], (int)(alpha * 255));
            renderTarget.DrawRoundedRectangle(CD2DRoundedRect (rectTab, sizeRound), &brush1);
        }

        rectTab.DeflateRect(cnMarginX, 0);
        if (rectTab.Width() > 0 && rectTab.Height() > 0)
        {
            renderTarget.DrawText(m_arLabels[i], rectTab, 
                (i == nSelected || i == m_nHighlighted) ? m_pBrushTextBold : m_pBrushTextRegular,
                &format, D2D1_DRAW_TEXT_OPTIONS_CLIP);
        }

        if (count > 1 && i < (count - 1))
        {
            CD2DLinearGradientBrush brush(&renderTarget, gradientBorder, ARRAYSIZE(gradientBorder),
                D2D1::LinearGradientBrushProperties(D2D1::Point2F((float)rectTabFull.left, (float)rectTab.bottom), D2D1::Point2F((float)rectTab.right, (float)rectTab.bottom)));
            renderTarget.DrawLine
                            (
                                CD2DPointF((FLOAT)rectTabFull.left, rectTabFull.bottom - 0.5f), 
                                CD2DPointF((FLOAT)rectTabFull.right, rectTabFull.bottom - 0.5f), 
                                &brush
                            );
        }
    }

    delete [] pGradient_H;
}


void CUIAnimationWnd::OnSize(UINT nType, int cx, int cy) 
{
    CWnd::OnSize(nType, cx, cy);
    RecalcLayout();
}


void CUIAnimationWnd::OnMouseMove(UINT nFlags, CPoint point)
{
    CWnd::OnMouseMove(nFlags, point);

    if (GetCount() < 2)
    {
        return;
    }

    if (!m_bTracked)
    {
        m_bTracked = TRUE;

        TRACKMOUSEEVENT trackmouseevent;
        trackmouseevent.cbSize = sizeof(trackmouseevent);
        trackmouseevent.dwFlags = TME_LEAVE;
        trackmouseevent.hwndTrack = GetSafeHwnd();
        trackmouseevent.dwHoverTime = HOVER_DEFAULT;
        ::AFXTrackMouse(&trackmouseevent);
    }

    SetHighlighted(HitTest(point));
}


void CUIAnimationWnd::OnMouseLeave()
{
    CWnd::OnMouseLeave();

    m_bTracked = FALSE;

    if (GetCount() < 2)
    {
        return;
    }

    SetHighlighted(-1);
}


void CUIAnimationWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
    CWnd::OnLButtonDown(nFlags, point);

    if (GetCount() < 2)
    {
        return;
    }

    m_nHighlighted = -1;
    SetCurSel(HitTest(point));
}


BOOL CUIAnimationWnd::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
    CPoint ptCursor;
    ::GetCursorPos(&ptCursor);
    ScreenToClient(&ptCursor);
    if (HitTest(ptCursor) != -1)
    {
        ::SetCursor(::LoadCursor(NULL, IDC_HAND));
        return TRUE;
    }

    return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


afx_msg LRESULT CUIAnimationWnd::OnDraw2D(WPARAM /*wParam*/, LPARAM lParam)
{
	CHwndRenderTarget* pRenderTarget = (CHwndRenderTarget*)lParam;
	ASSERT_VALID(pRenderTarget);

    if (m_Animation == e_AnimationSelect && !IsAnimationInProgress())
    {
        StopAnimation();
    }

    if (GetCount() > 0)
    {
        CRect rect(GetControlRect());
        rect.InflateRect(1, 1);

        if (m_Animation == e_AnimationSelect)
        {
			m_pBrushFill->SetStartPoint(D2D1::Point2F((float)rect.left, (float)rect.top));
			m_pBrushFill->SetEndPoint(D2D1::Point2F((float)rect.left, (float)rect.bottom - 0.5f));

            pRenderTarget->FillRectangle(rect, m_pBrushFill);

            DoPaintControlD2D(*pRenderTarget);
        }

        pRenderTarget->DrawRectangle(rect, m_pBrushBorder);

        if (!m_rectTabs.IsRectEmpty())
        {
            DoPaintTabsD2D(*pRenderTarget);
        }
    }
    else
    {
        CRect rect;
        GetClientRect(rect);

		m_pBrushFill->SetStartPoint(D2D1::Point2F((float)rect.left, (float)rect.top));
		m_pBrushFill->SetEndPoint(D2D1::Point2F((float)rect.left, (float)rect.bottom - 0.5f));

        pRenderTarget->FillRectangle(rect, m_pBrushFill);
    }

    return TRUE;
}
