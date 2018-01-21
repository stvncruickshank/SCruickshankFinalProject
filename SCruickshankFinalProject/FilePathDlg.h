#pragma once
#include "afxwin.h"
#include "resource.h"
#include "afxdialogex.h"

// FilePathDlg dialog

class FilePathDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FilePathDlg)

public:
	FilePathDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~FilePathDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILEPATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString tempCString;
	CEdit m_FilePath;
	CButton m_bOK;
	CButton m_bCancel;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
