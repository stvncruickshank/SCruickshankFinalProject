// FilePathDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FilePathDlg.h"
#include "afxdialogex.h"
#include "resource.h"

// FilePathDlg dialog

IMPLEMENT_DYNAMIC(FilePathDlg, CDialogEx)

FilePathDlg::FilePathDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILEPATH, pParent)
{

}

FilePathDlg::~FilePathDlg()
{
}

void FilePathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FILEPATH, m_FilePath);
	DDX_Control(pDX, IDOK, m_bOK);
	DDX_Control(pDX, IDCANCEL, m_bCancel);
}


BEGIN_MESSAGE_MAP(FilePathDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &FilePathDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &FilePathDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// FilePathDlg message handlers


void FilePathDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_FilePath.GetWindowTextA(tempCString);
	
	EndDialog(0);
	CDialogEx::OnOK();
}


void FilePathDlg::OnBnClickedCancel()
{
	EndDialog(0);
	CDialogEx::OnCancel();
}
