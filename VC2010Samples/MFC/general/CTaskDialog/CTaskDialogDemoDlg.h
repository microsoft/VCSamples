// TaskDialogTestDlg.h : header file
//

#pragma once

#include <afxtaskdialog.h>

// CTaskDialogTestDlg dialog
class CTaskDialogTestDlg : public CDialog
{
// Construction
public:
	CTaskDialogTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TASKDIALOGTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	void SetControls(INT_PTR nResult, int nRadioButtonId, BOOL bChecked);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedRadioId();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();	
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	
};


class CProgressBarTaskDialog : public CTaskDialog {
public:
	CProgressBarTaskDialog() : CTaskDialog(_T("A CTaskDialog presents information in a clear and consistent way."),
			_T("How much do you like CTaskDialog?"), 
			_T("Sample Progress Bar"), 
		TDCBF_YES_BUTTON | TDCBF_NO_BUTTON ,
		TDF_ENABLE_HYPERLINKS  | TDF_USE_COMMAND_LINKS | TDF_CALLBACK_TIMER | TDF_SHOW_PROGRESS_BAR, _T("")) 
	{			
			SetProgressBarRange(0, 300);
	}	
protected:
	virtual HRESULT OnTimer(long /*lTick */) {
		static int iCounter = 0;			

		if( iCounter == 260) {
			SetProgressBarState(PBST_NORMAL);	
		}

		if (iCounter > 80 && iCounter < 120) {
			SetProgressBarState(PBST_ERROR);					
		}
		else if (iCounter > 190 && iCounter < 220) {
			SetProgressBarState(PBST_PAUSED);
		}
		else {			
			SetProgressBarPosition(iCounter);			
		}

		if (iCounter >= 300) {
			iCounter = 0;
		}
		else iCounter+=5; 
		
		return S_OK;
	} 
};

class CMargueeTaskDialog : public CTaskDialog {
public:
	CMargueeTaskDialog() : CTaskDialog(_T("A CTaskDialog presents information in a clear and consistent way."),
		_T("How much do you like CTaskDialog?"), _T("Sample Marquee"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON,
		TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS | TDF_CALLBACK_TIMER | TDF_SHOW_PROGRESS_BAR  | TDF_SHOW_MARQUEE_PROGRESS_BAR) 
	{	
		SetExpansionArea(_T("How long do I have to wait?"), _T("Get some additional information."), _T("I don't need this information!"));	
		SetVerificationCheckboxText(_T("Don't show this dialog again!"));
		SetVerificationCheckbox(true);
		SetProgressBarMarquee( TRUE , 2);	
	}	
};

class CNextWizardDialog : public CTaskDialog 
	{
	private:
		CTaskDialog *m_next;
		CTaskDialog *m_prev;
	public:
		CNextWizardDialog() : CTaskDialog(_T("Just in the middle"),
			_T("Where am I?"), _T("Second window!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON,
			TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS | TDF_ALLOW_DIALOG_CANCELLATION)
		{				
			SetMainIcon(TD_INFORMATION_ICON);			
			AddCommandControl(101 ,_T("Is there something more?\nIt's a mistery."));	
		}

		void SetDialog(CTaskDialog *next, CTaskDialog *prev) { m_next = next; m_prev = prev; }
	protected:				
		HRESULT OnCommandControlClick(int iButtonId) {		
			if (iButtonId == 100) {							
				NavigateTo(*m_prev);				
				return S_FALSE;
			}
			else if (iButtonId == 101) {
				NavigateTo(*m_next);
				return S_FALSE;
			}
			
			return S_OK;
		}
};

class CEndWizardDialog : public CTaskDialog 
	{
	private:
		CTaskDialog *m_prev;
	public:
		CEndWizardDialog() : CTaskDialog(_T("There is nothing more to see!"),
			_T("This is the end!"), _T("Third window!"), TDCBF_OK_BUTTON,
			TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS | TDF_ALLOW_DIALOG_CANCELLATION)
		{				
			SetMainIcon(TD_WARNING_ICON);			
		}

		void SetDialog(CTaskDialog *prev) { m_prev = prev; }
};

class CWizardDialog : public CTaskDialog 
{
public:
	CWizardDialog() : CTaskDialog(_T("Introduce the wizard option."),
		_T("Let's begin"), _T("First window!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON,
		TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS | TDF_ALLOW_DIALOG_CANCELLATION)
	{	
		SetExpansionArea(_T("If you click Go! You will be redirected to another CTaskDialog window."), 
				_T("Say more!"), _T("I don't want details!"));

		AddCommandControl(100 , _T("Go next!\nThere is nothing interesting to see."));		
		m_nextWizardDialog.SetDialog(&m_endWizardDialog, this);
		m_endWizardDialog.SetDialog(&m_nextWizardDialog);
	}
protected:
	HRESULT OnCommandControlClick(int iButtonId) {
		if (iButtonId == 100) {			
			NavigateTo(m_nextWizardDialog);
			return S_FALSE;
		}
	
		return S_OK;
	}

private:
	CNextWizardDialog m_nextWizardDialog;
	CEndWizardDialog m_endWizardDialog;
};
