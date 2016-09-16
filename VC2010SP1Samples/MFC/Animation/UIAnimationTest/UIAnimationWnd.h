#pragma once

// CUIAnimationWnd

class CUIAnimationWnd : public CWnd
{
    DECLARE_DYNAMIC(CUIAnimationWnd)

public:
    enum XAnimation
    {
        e_AnimationFirst     = 0,
        e_AnimationNone      = e_AnimationFirst,
        e_AnimationSelect    = 1,
        e_AnimationLast      = e_AnimationSelect
    };

    enum XAnimationType
    {
        e_AnimationTypeFade       = 0x0001,

        e_AnimationTypeSlideUp    = 0x0002,
        e_AnimationTypeSlideDown  = 0x0004,
        e_AnimationTypeSlideLeft  = 0x0008,
        e_AnimationTypeSlideRight = 0x0010,

        e_AnimationTypeScale      = 0x0020,

        e_AnimationTypeBoth       = 0x1000
    };

public:
    CUIAnimationWnd();
    virtual ~CUIAnimationWnd();

    virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);

    BOOL AddControl(CWnd* pWnd, const CString& strLabel);
    INT_PTR GetCount() const { return m_arWindows.GetSize(); }
    BOOL IsEmpty() const { return GetCount() == 0; }
    int GetCurSel() const { return m_nCurSel; }
    void SetCurSel(int index);

    BOOL IsAnimationInProgress() {return m_AnimationController.IsAnimationInProgress();}

    DWORD GetAnimationType(XAnimation animation) const
    {
        if (animation == e_AnimationNone)
        {
            ASSERT(FALSE);
            return 0;
        }

        return animation == e_AnimationSelect ? m_AnimationTypeSelect : 0;
    }
    void SetAnimationType(XAnimation animation, DWORD type)
    {
        if (animation == e_AnimationNone)
        {
            ASSERT(FALSE);
            return;
        }

        if (!IsAnimationInProgress())
        {
            if (animation == e_AnimationSelect)
            {
                m_AnimationTypeSelect = type;
            }
        }
    }

    double GetAnimationDuration(XAnimation animation) const
    {
        if (animation == e_AnimationNone)
        {
            ASSERT(FALSE);
            return 0.0;
        }

        return animation == e_AnimationSelect ? m_AnimationDurationSelect : 0.0;
    }
    void SetAnimationDuration(XAnimation animation, double duration)
    {
        if (animation == e_AnimationNone)
        {
            ASSERT(FALSE);
            return;
        }

        if (!IsAnimationInProgress())
        {
            if (animation == e_AnimationSelect)
            {
                m_AnimationDurationSelect = duration;
            }
        }
    }

protected:
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnMouseLeave();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg LRESULT OnDraw2D(WPARAM wParam, LPARAM lParam);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    DECLARE_MESSAGE_MAP()

    void RecalcLayout();
    CRect GetControlRect() const;
    CRect GetTabRect(int index) const;
    void RepositionControls(CWnd* pWnd = NULL);
    CWnd* GetControl(int index);
    int FindIndex(const CWnd* pWnd) const;
    int HitTest(const CPoint& point) const;
    void SetHighlighted(int index);

    void DoPaintControlD2D(CHwndRenderTarget& renderTarget);
    void DoPaintTabsD2D(CHwndRenderTarget& renderTarget);

    void PrepareBitmaps(int nCurrent, int nNext);
    void ClearBitmaps();

    void StartAnimation(XAnimation animation);
    void StopAnimation();

    DWORD GetAnimationType() const
    {
        return GetAnimationType(m_Animation);
    }
    double GetAnimationDuration() const
    {
        return GetAnimationDuration(m_Animation);
    }

private:
    CRect                m_rectTabs;
    CArray<CWnd*, CWnd*> m_arWindows;
    CStringArray         m_arLabels;
    int                  m_nCurSel;
    int                  m_nHighlighted;
    BOOL                 m_bTracked;

    XAnimation           m_Animation;
    DWORD                m_AnimationTypeSelect;
    double               m_AnimationDurationSelect;

    CAnimationController m_AnimationController;
    CAnimationValue      m_AnimationValueFade;
    CAnimationPoint      m_AnimationValueSlide;
    CAnimationValue      m_AnimationValueScale;

    CArray<CAnimationValue*, CAnimationValue*>
                         m_arAnimationFade_H;

    CBitmap              m_bmpControl[2];
    CD2DBitmap*          m_bmpD2D[2];

    BOOL                 m_bTabHorz;

	CD2DSolidColorBrush*	m_pBrushBorder;
	CD2DSolidColorBrush*	m_pBrushTabBorder;
    CD2DSolidColorBrush*	m_pBrushTextRegular;
    CD2DSolidColorBrush* 	m_pBrushTextBold;
	CD2DSolidColorBrush*	m_pBrushWhite;

	CD2DLinearGradientBrush*	m_pBrushFill;

	CD2DLinearGradientBrush*	m_pBrushTab;
	CD2DLinearGradientBrush*	m_pBrushSelectedTabBack;
};
