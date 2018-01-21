#pragma once
#include <string>
//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>

class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class CMainWindow : public CWnd
{
protected:
	CEdit m_edit;
	CMenu *menu;






public:
	CListBox m_wndShopCart;
	float custTotal = 9.95;


	void FillListBox();

public:
	CMainWindow(

	);

	static int CALLBACK EnumFontFamProc(ENUMLOGFONT* lpelf,
		NEWTEXTMETRIC* lpntm, int nFontType, LPARAM lParam);

protected:
	//virtual void PostNcDestroy();

	afx_msg int OnCreate(LPCREATESTRUCT lpcs);
	afx_msg void OnRemoveCart();
	afx_msg void OnQuit();
	afx_msg void onAddCart();
	afx_msg void onCheckout();

	DECLARE_MESSAGE_MAP()
};
