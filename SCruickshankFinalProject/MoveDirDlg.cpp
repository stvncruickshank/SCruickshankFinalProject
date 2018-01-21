// MoveDirDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MoveDirDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// MoveDirDlg dialog

IMPLEMENT_DYNAMIC(MoveDirDlg, CDialogEx)

MoveDirDlg::MoveDirDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MOVEDIR, pParent)
{

}

MoveDirDlg::~MoveDirDlg()
{
}

void MoveDirDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_dirFrom, m_dirFrom);
	DDX_Control(pDX, IDC_dirTo, m_dirTo);
}


BEGIN_MESSAGE_MAP(MoveDirDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MoveDirDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MoveDirDlg::OnBnClickedCancel)
END_MESSAGE_MAP()

void MoveDirDlg::OnBnClickedOk()
{
	m_dirFrom.GetWindowTextA(tempA);
	m_dirTo.GetWindowTextA(tempB);
	CDialogEx::OnOK();
}


void MoveDirDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}
