#pragma once
#include "afxwin.h"


// AttribDlg dialog

class AttribDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AttribDlg)

public:
	AttribDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~AttribDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ATTRIB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_rArchive;
	CButton m_rCompress;
	CButton m_rEncrypt;
	CButton m_rHidden;
	CButton m_rNormal;
	CButton m_rRdOnly;
	CButton m_bOK;
	CButton m_bCancel;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit3();
	CEdit m_ePath;
	CString tempA;
	CString tempB;
	int archive;
	int compress;
	int encrypt;
	int hidden;
	int normal;
	int readonly;
	int indexed;
	int system;
	int offline;
	int temp;
	int vrt;
	CButton m_rIndexed;
	CButton m_rSystem;
	CButton m_rOffline;
	CButton m_rTemp;
	CButton m_rVirtual;
};
