
// OOP_LR3_Galimov.h : main header file for the OOP_LR3_Galimov application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COOPLR3GalimovApp:
// See OOP_LR3_Galimov.cpp for the implementation of this class
//

class COOPLR3GalimovApp : public CWinApp
{
public:
	COOPLR3GalimovApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COOPLR3GalimovApp theApp;
