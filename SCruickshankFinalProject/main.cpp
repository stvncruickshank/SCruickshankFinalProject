//Advanced C++ Final Project - "Windows Mania"
//May 12, 2016
//Steven Cruickshank
//A program which mimics the commands offered by a traditional windows OS, only in GUI form
///////////////////////
////////////////////////



#include <afxwin.h> //
#include <afxdlgs.h> //
#include <windows.h> //
#include <fstream>
#include <iostream>
#include <strstream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <tchar.h>
#include <shellapi.h>
#include <strsafe.h>
#include <stdio.h>
#include "FilePathDlg.h"
#include "MoveDirDlg.h"
#include "AttribDlg.h"
#include "RenameDlg.h"
#include "SplashDlg.h"
#include "AboutDlg.h"

#pragma comment(lib, "User32.lib")

#define IDC_EDIT 500
#define IDD_SPLASH                      115
#define IDD_DIALOG1                     123

#define IDR_MENU1                       101
#define IDD_RENAME                      108
#define ID_FILE_QUIT                    40004
#define ID_EDIT_CLEAR                   40014
#define ID_EDIT_CUT                     40005
#define ID_DIRECTORYTOOLS_MAKEDIRECTORY 40008
#define ID_DIRECTORYTOOLS_REMOVEDIRECTORY 40009
#define ID_DIRECTORYTOOLS_LISTFILESINDIRECTORY 40019
#define ID_FILE_SAVE                    40002
#define ID_ABOUT_DATE                   40013
#define ID_ABOUT_ABOUT                  40012
#define ID_DIRECTORYTOOLS_SETCURRENTDIR 40015
#define ID_DIRECTORYTOOLS_GETCURRENTDIR 40016
#define IDD_FILEPATH                    102
#define ID_DIRECTORYTOOLS_COPYDIRECTORY 40017
#define ID_DIRECTORYTOOLS_RENAMEDIRECTORY 40018
#define ID_DIRECTORYTOOLS_CHANGEFILEATTRIBS 40020
#define ID_DIRECTORYTOOLS_DIR           40021
#define ID_DIRECTORYTOOLS_COPYDIRECTORY40022 40022
#define IDR_ACC1                        110
#define ID_EDIT_DELETE                  40054
#define ID_EDIT_UNDO                    40055



const char fileDialogFilter[] ="C++ Files (*.cpp) | *.cpp|Header Files\(.*h)|*.h|Resource Files (*.rc)|*.rc|Text Files(*.txt)|*.txt| All Files(*.*) | *> * || ";
const char fileDialogExt[] = "cpp";

CString findString;
CString printBuffer;
CString printPath;
CRect rect;


void RecursiveDelete(CString);



//App Obj
class CApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CWindow : public CFrameWnd
{
private:	
	static UINT findMessage;
	CMenu *menu;
	CEdit m_edit;

public:
	CWindow();

	afx_msg void HandleClear();
	afx_msg void HandleQuit();
	afx_msg void HandleCut();
	afx_msg void HandleMkDir();
	afx_msg void HandleSave();
	afx_msg void HandleDateTime();
	afx_msg void HandleAbout();
	afx_msg void OnRemoveDirectory();
	afx_msg void SetDirectory();
	afx_msg void GetDirectory();
	afx_msg void OnMoveDir();
	afx_msg void renameDir();
	afx_msg void OnListFiles();
	afx_msg void OnAttribChange();
	afx_msg void OnGamesHenway();
	afx_msg void OnGamesOfficemadness();
	afx_msg void OnFilesInDir();
	afx_msg void OnFileOpen();
	afx_msg void OnCopyDir();
	afx_msg void OnPrint();
	afx_msg void OnEditDelete();
	afx_msg void OnEditUndo();
	afx_msg void OnEditPaste();
	afx_msg void OnEditCopy();


	DECLARE_MESSAGE_MAP()
	
	
	
};

//instance of the App Obj
CApp App;



CWindow::CWindow()
{
	//splash screen
	SplashDlg dlg;
	if (dlg.DoModal() == IDCANCEL) 
	{
		
	}
	

		Create(NULL, "~*WINDOWS MANIA*~", WS_OVERLAPPED | WS_SYSMENU, rectDefault);
		menu = new CMenu();
		menu->LoadMenu(IDR_MENU1);
		SetMenu(menu);
		DrawMenuBar();
		GetClientRect(&rect);
		m_edit.Create(WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_NOHIDESEL, rect, this, IDC_EDIT);
		m_edit.SetFocus();
		LoadAccelTable(MAKEINTRESOURCE(IDR_ACC1));
	
}

BOOL CApp::InitInstance()
{
	//initinstance
	
	m_pMainWnd = new CWindow();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	
	return (TRUE);	

}

UINT CWindow::findMessage = ::RegisterWindowMessage(FINDMSGSTRING);
CFindReplaceDialog *findReplaceDialog = NULL;


BEGIN_MESSAGE_MAP(CWindow, CFrameWnd)
	ON_COMMAND (ID_EDIT_CLEAR, HandleClear)
	ON_COMMAND (ID_FILE_QUIT, HandleQuit)
	ON_COMMAND(ID_EDIT_CUT, HandleCut)
	ON_COMMAND(ID_DIRECTORYTOOLS_MAKEDIRECTORY, HandleMkDir)
	ON_COMMAND(ID_FILE_SAVE, HandleSave)
	ON_COMMAND(ID_ABOUT_DATE, &CWindow::HandleDateTime)
	ON_COMMAND(ID_ABOUT_ABOUT, &CWindow::HandleAbout)
	ON_COMMAND(ID_DIRECTORYTOOLS_REMOVEDIRECTORY, &CWindow::OnRemoveDirectory)
	ON_COMMAND(ID_DIRECTORYTOOLS_SETCURRENTDIR, &CWindow::SetDirectory)
	ON_COMMAND(ID_DIRECTORYTOOLS_GETCURRENTDIR, &CWindow::GetDirectory)
	ON_COMMAND(ID_DIRECTORYTOOLS_COPYDIRECTORY, &CWindow::OnMoveDir)
	ON_COMMAND(ID_DIRECTORYTOOLS_RENAMEDIRECTORY, &CWindow::renameDir)
	ON_COMMAND(ID_DIRECTORYTOOLS_LISTFILESINDIRECTORY, &CWindow::OnListFiles)
	ON_COMMAND(ID_DIRECTORYTOOLS_CHANGEFILEATTRIBS, &CWindow::OnAttribChange)
	ON_COMMAND(ID_GAMES_HENWAY, &CWindow::OnGamesHenway)
	ON_COMMAND(ID_GAMES_OFFICEMADNESS, &CWindow::OnGamesOfficemadness)
	ON_COMMAND(ID_DIRECTORYTOOLS_DIR, &CWindow::OnFilesInDir)
	ON_COMMAND(ID_FILE_OPEN, &CWindow::OnFileOpen)
	ON_COMMAND(ID_DIRECTORYTOOLS_COPYDIRECTORY40022, &CWindow::OnCopyDir)
	ON_COMMAND(ID_FILE_PRINT, &CWindow::OnPrint)
	ON_COMMAND(ID_EDIT_DELETE, &CWindow::OnEditDelete)
	ON_COMMAND(ID_EDIT_UNDO, &CWindow::OnEditUndo)
	ON_COMMAND(ID_EDIT_PASTE, &CWindow::OnEditPaste)
	ON_COMMAND(ID_EDIT_COPY, &CWindow::OnEditCopy)
END_MESSAGE_MAP()


void CWindow::HandleClear() //WORKS PERF
{
	UINT length = m_edit.GetWindowTextLengthA();
	if (length > 0)
	{
		int result = MessageBox("Warning: Data Loss!! \n Proceed", "caution", MB_ICONQUESTION | MB_YESNO);
		if (result == IDYES)
		{
			m_edit.SetWindowTextA("");
			printBuffer = ' ';
		}
		m_edit.SetFocus();
	}
}

void CWindow::HandleQuit() //WORKS PERF
{
	const int result = MessageBox("WARNING!!\nAre you sure you want to quit?", "CAUTION", MB_ICONQUESTION|MB_YESNO);
	if (result == IDYES)
		DestroyWindow();
	else 
		m_edit.SetFocus();

}


void CWindow::HandleCut() //PERF
{
	m_edit.Cut();
	m_edit.SetFocus();

}


void CWindow::HandleMkDir() //WORKS PERF!!!
{
	FilePathDlg dlg;
	CString to;
	

	if (dlg.DoModal() == ID_DIRECTORYTOOLS_MAKEDIRECTORY)
	{
		
	}
	to = dlg.tempCString;
	to = to + _T('\0') + _T('\0');
	m_edit.SetWindowTextA(to);
	if (strlen(to) > 1) {
		if (CreateDirectory(to, NULL) ||
			ERROR_ALREADY_EXISTS == GetLastError())
		{
			// CopyFile(...)
			MessageBox("Directory Created!", "Success!", MB_ICONINFORMATION | MB_OK);

		}
		else
		{
			// Failed to create directory.
			MessageBox("Failed!!", "Failed!!", MB_ICONERROR | MB_OK);

		}
	}
	m_edit.SetFocus();

}


void CWindow::HandleSave() //WORKS PERF!!!
{
	CFile file;
	static CString filePathName;
	CFileDialog fileDialog(FALSE, fileDialogExt,
		filePathName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, fileDialogFilter);

	if (fileDialog.DoModal() == IDOK)
	{
		CString oldPathName(filePathName);
		filePathName = fileDialog.GetPathName();
	}

	char buffer[65535];
	UINT length = m_edit.GetWindowTextLengthA();
	
	if (length == 0)
	{
		MessageBox("Nothing to save", "Warning!", MB_OK);
		m_edit.SetFocus();
		return;
	}
	if (!file.Open(filePathName, CFile::modeCreate | CFile::modeWrite))
	{
		CString msg("Can't open " + filePathName + "\nCheck the name.");
		MessageBox(msg, "File Save Error", MB_ICONEXCLAMATION);
		return;
	}

	char info[100];
	sprintf(info, "Saving %d Lines", m_edit.GetLineCount());
	MessageBox(info, "File Save", MB_ICONINFORMATION | MB_OK);
	m_edit.FmtLines(TRUE);
	m_edit.GetWindowText((LPSTR)buffer, length + 1);
	file.Write(buffer, length + 1);

	file.Close();
	m_edit.SetFocus();
}


void CWindow::HandleDateTime() //WORKS PERF
{
	CTime t;
	t =CTime::GetCurrentTime();
	CString s = t.Format("Current date and time: %c");
	MessageBox(s, "Date\Time", MB_OK);
	m_edit.SetFocus();

}


void CWindow::HandleAbout() //WORKS PERF
{
	AboutDlg dlg;
	if (dlg.DoModal() == ID_ABOUT_ABOUT) {};
	m_edit.SetFocus();
}

void CWindow::OnRemoveDirectory() //WORKS PERF
{
	CFile file;
	FilePathDlg dlg;
	

	if (dlg.DoModal() == IDOK)
	{
		
	}

	CString filePathName = dlg.tempCString;
	filePathName = filePathName + _T('\0') + _T('\0');
	if (strlen(filePathName) > 1) {
		RecursiveDelete(filePathName);
		MessageBox("Directory and all subfolders deleted!", "Success", MB_ICONINFORMATION | MB_OK);

	}
	m_edit.SetFocus();


}

void RecursiveDelete(CString szPath)
{
	CFileFind ff;
	CString path = szPath;
	CString dirPath;

	if (path.Right(1) != "\\")
		path += "\\";
	dirPath = path;
	path += "*.*";


	BOOL res = ff.FindFile(path);

	while (res)
	{
		res = ff.FindNextFile();
		if (ff.IsDots())
			continue;

		if (ff.IsDirectory())
		{
			path = ff.GetFilePath();
			RecursiveDelete(path);
			//RemoveDirectory(path);
		}
		else
			DeleteFile(ff.GetFilePath());
	}
	ff.Close();
	RemoveDirectory(dirPath);
	//m_edit.SetFocus();

}

void CWindow::SetDirectory() //WORKS PERF
{
	FilePathDlg dlg;
	if (dlg.DoModal()==ID_DIRECTORYTOOLS_SETCURRENTDIR)
	{
		
	}
	CString filePathName = dlg.tempCString;
	filePathName = filePathName + _T('\0') + _T('\0');
	
	if (strlen(filePathName) > 1)
	{
		SetCurrentDirectory(filePathName);
		MessageBox("Directory set!", "Success", MB_ICONINFORMATION | MB_OK);

	}
	m_edit.SetFocus();

}


void CWindow::GetDirectory() //WORKS PERF
{
	CString curDir; 
	GetCurrentDirectory(MAX_PATH, curDir.GetBufferSetLength(MAX_PATH)); 
	m_edit.SetWindowTextA(curDir);
	curDir.ReleaseBuffer();
	m_edit.SetFocus();

}





void CWindow::OnMoveDir() //WORKS PERF
{
	MoveDirDlg dlg;
	if (dlg.DoModal() == ID_DIRECTORYTOOLS_COPYDIRECTORY)
	{

	}

	int retval1 = PathFileExists(dlg.tempA);
	int retval2 = PathFileExists(dlg.tempB);
	dlg.tempA.Remove(' ');
	dlg.tempB.Remove(' ');
	CString to = dlg.tempB;
	to = to + _T('\0') + _T('\0');
	CString from = dlg.tempA;
	from = from + _T('\0') + _T('\0');

	if (strlen(to) > 1 && strlen(from) > 1) {
		if (retval1 == 0) {
			m_edit.SetWindowTextA(dlg.tempA + " FAILED");
			MessageBox("Root directory doesnt exist!", "Directory not found!", MB_ICONERROR | MB_OK);

		}
		else if (retval2 == 0) {
			m_edit.SetWindowTextA(dlg.tempB + " FAILED");
			MessageBox("Destination directory doesn't exist!", "Directory not found!", MB_ICONERROR | MB_OK);

		}
		else
		{
			SHFILEOPSTRUCT fos = { 0 };

			fos.wFunc = FO_MOVE;
			fos.pFrom = from;
			fos.pTo = to;

			::SHFileOperation(&fos);

			MessageBox("Directory successfully moved!", "Directory Moved!", MB_ICONINFORMATION | MB_OK);

		}
	}
	m_edit.SetFocus();

	}


void CWindow::renameDir() //WORKS PERF
{

	RenameDlg dlg;
	if (dlg.DoModal() == ID_DIRECTORYTOOLS_COPYDIRECTORY)
	{

	}

	CString from = dlg.tempA;
	CString to = dlg.tempB;

	from = from + _T('\0') + _T('\0');
	to = to + _T('\0') + _T('\0');

	int retval1 = PathFileExists(dlg.tempA);
	if (strlen(from) > 1 && strlen(to) > 1)
	{
		if (retval1 == 0)
		{
			MessageBox("ERROR: Invalid path", "ERROR", MB_ICONERROR | MB_OK);
			m_edit.SetWindowTextA("Error! invalid path.");
		}
		else
		{
			//m_edit.SetWindowTextA(dlg.tempA);
			MessageBox("Successfully renamed!", "Success!", MB_ICONINFORMATION | MB_OK);
			MoveFile(from, to);
		}
	}
	m_edit.SetFocus();

}

void CWindow::OnListFiles() // WORKS PERF
{
	// TODO: Add your command handler code here
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;

	CStringArray files;
	CString str;
	CString fileString;
	CString dirTemp = "\nDIRECTORIES: \r\n\n";
	CString fileTemp = "\nFILES: \r\n\n";
	FilePathDlg dlg;
	if (dlg.DoModal() == ID_DIRECTORYTOOLS_LISTFILESINDIRECTORY)
	{
		
	}
	
	CString folderPath = dlg.tempCString;
	size_t length = strlen(folderPath);
	
	StringCchLength(folderPath, MAX_PATH, &length);

	if (length > (MAX_PATH - 3))
	{
		MessageBox("Too long! try again!", "Directory too long!", MB_ICONERROR | MB_OK);

	}

	StringCchCopy(szDir, MAX_PATH, folderPath);
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	hFind = FindFirstFile(szDir, &ffd);

	if (INVALID_HANDLE_VALUE == hFind)
	{
		MessageBox("Root directory doesnt exist!", "Directory not found!", MB_ICONERROR | MB_OK);
	}

	//list all files in the direct!
	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			
			CString temp = ffd.cFileName;
			CString bytes;
			int tempSize = filesize.QuadPart;
			bytes.Format(_T("%d"), filesize.QuadPart);
			dirTemp += temp + _T("\t\t\t") + _T("\r\n");

		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;

			CString temp = ffd.cFileName;
			CString bytes;
			int tempSize = filesize.QuadPart;
			bytes.Format(_T("%d"), filesize.QuadPart);
			fileTemp += temp + _T("\t\t\t") + bytes + _T(" bytes \r\n");
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	dwError = GetLastError();
	
	FindClose(hFind);
	m_edit.SetFocus();

}


//WORKS PERF
void CWindow::OnAttribChange()
{
	// TODO: Add your command handler code here
	AttribDlg dlg;

	if (dlg.DoModal() == IDD_ATTRIB)
	{
	}
	CString pathName = dlg.tempA;
	pathName.Remove(' ');
	pathName = pathName +_T('\0') + _T('\0');

	int result = 0;

	//READ ONLY

	if (strlen(pathName) > 1) {
		if (dlg.readonly == BST_CHECKED && dlg.normal == BST_UNCHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_READONLY);
			m_edit.SetFocus();

		}

		//ARCHIVE
		else if (dlg.archive == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_ARCHIVE);
			m_edit.SetFocus();

		}

		//NORMAL
		else if (dlg.normal == BST_CHECKED)
		{

			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_NORMAL);
			m_edit.SetFocus();

		}

		//offline
		else if (dlg.offline == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_OFFLINE);
			m_edit.SetFocus();

		}

		//SYSTEM
		else if (dlg.system == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_SYSTEM);
			m_edit.SetFocus();

		}

		//TEMPORARY
		else if (dlg.temp == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_TEMPORARY);
			m_edit.SetFocus();

		}

		//NON INDEXED
		else if (dlg.indexed == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_NOT_CONTENT_INDEXED);
			m_edit.SetFocus();

		}


		//COMPRESS
		else if (dlg.compress == BST_CHECKED)
		{
			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_COMPRESSED);
			m_edit.SetFocus();

		}
		//HIDDEN
		else if (dlg.hidden == BST_CHECKED)
		{

			//m_edit.SetWindowTextA(_T("Checked"));
			SetFileAttributes(pathName, FILE_ATTRIBUTE_HIDDEN);
			m_edit.SetFocus();

		}
	}
}


void CWindow::OnGamesHenway() //WORKS PERF
{
	// TODO: Add your command handler code here
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!
		CreateProcess
		(
			TEXT("Henway.exe"),
			NULL, 
			NULL, 
			NULL, 
			FALSE,
			CREATE_NEW_CONSOLE,
			NULL, 
			NULL,
			&si,
			&pi
		)
		)
	{
		m_edit.SetWindowTextA("ERROR: File note located");
	}


}


void CWindow::OnGamesOfficemadness() //WORKS PERF
{
	// TODO: Add your command handler code here
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!
		CreateProcess
		(
			TEXT("BattleOffice.exe"),
			NULL,
			NULL,
			NULL,
			FALSE,
			CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&si,
			&pi
		)
		)
	{
		m_edit.SetWindowTextA("ERROR: File note located");
	}
}




void CWindow::OnFilesInDir() //WORKS PERF
{
	// TODO: Add your command handler code here
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if (!
		CreateProcess
		(
			TEXT("WinDir.exe"),
			NULL,
			NULL,
			NULL,
			FALSE,
			CREATE_NEW_CONSOLE,
			NULL,
			NULL,
			&si,
			&pi
		)
		)
	{
		m_edit.SetWindowTextA("ERROR: File note located");
	}
}


void CWindow::OnFileOpen()//WORKS PERF
{
	// TODO: Add your command handler code here
	char s[200];
	CFile filePath;
	static CString filePathName;
	CFileDialog FileDialog(TRUE, NULL, NULL, OFN_HIDEREADONLY, fileDialogFilter);

	if (FileDialog.DoModal() == IDOK)
	{
		
	}
	CString oldPathName(filePathName);
		filePathName = FileDialog.GetPathName();
		printPath = FileDialog.GetPathName();


	CStdioFile file;
	file.Open(filePathName, CFile::modeRead | CFile::typeText);

	CString buffer;
	CString text;

	if (strlen(filePathName) > 1) {
		while (file.ReadString(text))
		{
			buffer += text;
			buffer += "\r\n";
			printBuffer += text;
			printBuffer += "\r\n";
		}

		file.Close();
		m_edit.SetWindowText(buffer);
	}
	m_edit.SetFocus();



}


void CWindow::OnCopyDir() //WORKS PERF
{
	// TODO: Add your command handler code here
	MoveDirDlg dlg;
	if (dlg.DoModal() == ID_DIRECTORYTOOLS_COPYDIRECTORY40022)
	{

	}

	int retval1 = PathFileExists(dlg.tempA);
	int retval2 = PathFileExists(dlg.tempB);
	dlg.tempA.Remove(' ');
	dlg.tempB.Remove(' ');
	CString to = dlg.tempB;
	to = to + _T('\0') + _T('\0');
	CString from = dlg.tempA;
	from = from + _T('\0') + _T('\0');


	if (retval1 == 0) {
		m_edit.SetWindowTextA(dlg.tempA + " FAILED");
		MessageBox("Root directory doesnt exist!", "Directory not found!", MB_ICONERROR | MB_OK);

	}
	else if (retval2 == 0) {
		m_edit.SetWindowTextA(dlg.tempB + " FAILED");
		MessageBox("Destination directory doesn't exist!", "Directory not found!", MB_ICONERROR | MB_OK);

	}
	else
	{
		SHFILEOPSTRUCT fos = { 0 };

		fos.wFunc = FO_COPY;
		fos.pFrom = from;
		fos.pTo = to;

		::SHFileOperation(&fos);
		
		MessageBox("Directory successfully copied!", "Directory Copied!", MB_ICONINFORMATION | MB_OK);

	}
	m_edit.SetFocus();

}


void CWindow::OnPrint()
{
	std::ofstream printer("\\\\cts-fp.bhcc.dom\\D119");

	#define COMPRESS "\x1b(s16.5H"
	#define LANDSCAPE "\x1b&l1O" //\x1b&l1O ONLY LOOK AT &l1O portion 
	#define PORTRAIT "\x1b&l0O"
	#define DUPLEX "\x1b&l1S"
	#define GREYSCALE "\x1b*c2P"
	

	CPrintDialog dlg(FALSE);
	
	if (dlg.DoModal() == ID_FILE_PRINT)
	{
		
	}
	
	//access portrait
	DEVMODE* pDev = dlg.GetDevMode();
	if (pDev->dmOrientation == DMORIENT_PORTRAIT)
	{
		//m_edit.SetWindowTextA("portrait!");
		if (printer)
		{
			printer << PORTRAIT << printBuffer << std::endl;
		}
	}

	//access landscape
	if (pDev->dmOrientation == DMORIENT_LANDSCAPE)
	{
		//m_edit.SetWindowTextA("landscape!");
		if (printer)
		{
			printer << LANDSCAPE << printBuffer << std::endl;
		}
	}

	//DUPLEX checked
	if (pDev->dmDuplex == DM_DUPLEX)
	{
		if (printer)
		{
			printer << DUPLEX << printBuffer << std::endl;
		}
		//m_edit.SetWindowTextA("DUPLEX");
	}
	::GlobalUnlock(dlg.m_pd.hDevMode);

	if (pDev->dmDitherType == DMDITHER_GRAYSCALE)
	{ 
		if (printer)
		{
			printer << GREYSCALE << printBuffer << std::endl;
		}
	}

	m_edit.SetFocus();

}


void CWindow::OnEditDelete()
{
	m_edit.ReplaceSel("");
	m_edit.SetFocus();
}


void CWindow::OnEditUndo()
{
	m_edit.Undo();
	m_edit.SetFocus();
}


void CWindow::OnEditPaste()
{
	m_edit.Paste();
	m_edit.SetFocus();

}


void CWindow::OnEditCopy()
{
	m_edit.Copy();
	m_edit.SetFocus();

}


