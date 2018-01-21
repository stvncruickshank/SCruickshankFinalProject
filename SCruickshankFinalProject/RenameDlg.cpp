// RenameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RenameDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// RenameDlg dialog

IMPLEMENT_DYNAMIC(RenameDlg, CDialogEx)

RenameDlg::RenameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RENAME, pParent)
{

}

RenameDlg::~RenameDlg()
{
}

void RenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_eOldPath);
	DDX_Control(pDX, IDC_EDIT2, m_eNewPath);
}


BEGIN_MESSAGE_MAP(RenameDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &RenameDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RenameDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


void RenameDlg::OnBnClickedOk()
{
	m_eOldPath.GetWindowTextA(tempA);
	m_eNewPath.GetWindowTextA(tempB);
	CDialogEx::OnOK();
}


void RenameDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
