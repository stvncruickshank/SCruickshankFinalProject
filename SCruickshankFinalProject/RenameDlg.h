#pragma once
#include "afxwin.h"
#include "resource.h"

// RenameDlg dialog

class RenameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RenameDlg)

public:
	RenameDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~RenameDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RENAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_eOldPath;
	CEdit m_eNewPath;
	CString tempA;
	CString tempB;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
