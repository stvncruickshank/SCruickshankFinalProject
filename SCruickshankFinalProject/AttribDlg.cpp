// AttribDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AttribDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// AttribDlg dialog

IMPLEMENT_DYNAMIC(AttribDlg, CDialogEx)

AttribDlg::AttribDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ATTRIB, pParent)
{

}

AttribDlg::~AttribDlg()
{
}

void AttribDlg::DoDataExchange(CDataExchange* pDX)
{

	//controls data being passed
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ARCHIVE, m_rArchive);
	DDX_Control(pDX, IDC_COMPRESSED, m_rCompress);
	DDX_Control(pDX, IDC_HIDDEN, m_rHidden);
	DDX_Control(pDX, IDC_NORMAL, m_rNormal);
	DDX_Control(pDX, IDC_READONLY, m_rRdOnly);
	DDX_Control(pDX, IDOK, m_bOK);
	DDX_Control(pDX, IDCANCEL, m_bCancel);
	DDX_Control(pDX, IDC_EDIT3, m_ePath);
	DDX_Control(pDX, IDC_INDEXED, m_rIndexed);
	DDX_Control(pDX, IDC_SYSTEM, m_rSystem);
	DDX_Control(pDX, IDC_OFFLINE, m_rOffline);
	DDX_Control(pDX, IDC_TEMP, m_rTemp);
}

//event handlers
BEGIN_MESSAGE_MAP(AttribDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AttribDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AttribDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT3, &AttribDlg::OnEnChangeEdit3)
END_MESSAGE_MAP()


void AttribDlg::OnBnClickedOk()
{
	m_ePath.GetWindowTextA(tempA);

	//Set each radiobutton to its matching ID
	//then sets its checked value to an int
	CButton *m_ctlCheckArchive = (CButton*)GetDlgItem(IDC_ARCHIVE);
	archive = m_ctlCheckArchive->GetCheck();

	CButton *m_ctlCheckCompress = (CButton*)GetDlgItem(IDC_COMPRESSED);
	compress = m_ctlCheckCompress->GetCheck();

	CButton *m_ctlCheckHidden = (CButton*)GetDlgItem(IDC_HIDDEN);
	hidden = m_ctlCheckHidden->GetCheck();

	CButton *m_ctlCheckNormal = (CButton*)GetDlgItem(IDC_NORMAL);
	normal = m_ctlCheckNormal->GetCheck();

	CButton *m_ctlCheckReadOnly = (CButton*)GetDlgItem(IDC_READONLY);
	readonly = m_ctlCheckReadOnly->GetCheck();

	CButton *m_ctlCheckIndexed = (CButton*)GetDlgItem(IDC_INDEXED);
	indexed = m_ctlCheckIndexed->GetCheck();
	
	CButton *m_ctlCheckSystem = (CButton*)GetDlgItem(IDC_SYSTEM);
	system = m_ctlCheckSystem->GetCheck();

	CButton *m_ctlCheckOffline = (CButton*)GetDlgItem(IDC_OFFLINE);
	offline = m_ctlCheckOffline->GetCheck();

	CButton *m_ctlCheckTemp = (CButton*)GetDlgItem(IDC_TEMP);
	temp = m_ctlCheckTemp->GetCheck();

	CDialogEx::OnOK();
}


void AttribDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void AttribDlg::OnEnChangeEdit3()
{

}
