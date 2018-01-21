// SplashDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SplashDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// SplashDlg dialog

IMPLEMENT_DYNAMIC(SplashDlg, CDialogEx)

SplashDlg::SplashDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SPLASH, pParent)
{

}

SplashDlg::~SplashDlg()
{
}

void SplashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, ID_ENTER);
	
}


BEGIN_MESSAGE_MAP(SplashDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SplashDlg::EnterWindows)
	
END_MESSAGE_MAP()


// SplashDlg message handlers


void SplashDlg::EnterWindows()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


