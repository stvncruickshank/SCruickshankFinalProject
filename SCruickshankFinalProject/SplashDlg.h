#pragma once
#include "afxwin.h"


// SplashDlg dialog

class SplashDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SplashDlg)

public:
	SplashDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~SplashDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLASH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton ID_ENTER;
	CButton OnQuit;
	afx_msg void EnterWindows();
};
