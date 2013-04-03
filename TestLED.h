// TestLED.h : main header file for the TESTLED application
//

#if !defined(AFX_TESTLED_H__37AACB42_6C47_40BA_A4AB_B926E7101BA1__INCLUDED_)
#define AFX_TESTLED_H__37AACB42_6C47_40BA_A4AB_B926E7101BA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestLEDApp:
// See TestLED.cpp for the implementation of this class
//

class CTestLEDApp : public CWinApp
{
public:
	CTestLEDApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLEDApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestLEDApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLED_H__37AACB42_6C47_40BA_A4AB_B926E7101BA1__INCLUDED_)
