// demo.h : main header file for the demo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CdemoApp:
// See demo.cpp for the implementation of this class
//

class CdemoApp : public CWinApp
{
public:
	CdemoApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CdemoApp theApp;