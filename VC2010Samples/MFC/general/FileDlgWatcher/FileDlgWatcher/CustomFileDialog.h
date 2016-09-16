#pragma once

// CCustomFileDialog
// A CCustomFileDialog implements CFileDialog's virtual overrides for event
// handling and displays when those callbacks are triggered.
class CCustomFileDialog : public CFileDialog
{
	DECLARE_DYNAMIC(CCustomFileDialog)

public:
	CCustomFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
					  BOOL bVistaStyle,
					  BOOL bEventPopups,
					  CString &strLog);
	virtual ~CCustomFileDialog();

private:
	// Helper method that logs the given event message as specified by the user
	void LogEvent(LPCWSTR eventMsg);

	BOOL	m_bEventPopups;
	CString	&m_strLog;

protected:
	// virtual event overrides
	DECLARE_MESSAGE_MAP()
	// CFileDialog overrides
	virtual void OnFileNameChange();
	virtual BOOL OnFileNameOK();
	virtual void OnFolderChange();
	virtual void OnInitDone();
	virtual void OnLBSelChangedNotify(UINT nIDBox, UINT iCurSel, UINT nCode);
	virtual UINT OnShareViolation(LPCTSTR lpszPathName);
	virtual void OnTypeChange();
	
	// CDialog overrides
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	virtual void OnSetFont(CFont *pFont);
};
