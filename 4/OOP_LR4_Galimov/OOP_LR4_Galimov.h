
// OOP_LR4_Galimov.h : main header file for the OOP_LR4_Galimov application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COOPLR4GalimovApp:
// See OOP_LR4_Galimov.cpp for the implementation of this class
//

class COOPLR4GalimovApp : public CWinApp
{
public:
	COOPLR4GalimovApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COOPLR4GalimovApp theApp;
