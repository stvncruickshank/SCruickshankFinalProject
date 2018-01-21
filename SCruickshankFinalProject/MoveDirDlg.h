#pragma once
#include "afxwin.h"
#include "resource.h"

// MoveDirDlg dialog

class MoveDirDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MoveDirDlg)

public:
	MoveDirDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MoveDirDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOVEDIR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_dirFrom;
	CEdit m_dirTo;
	CString tempA;
	CString tempB;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
