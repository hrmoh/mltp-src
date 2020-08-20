// MLTP.h : main header file for the MLTP application
//

#if !defined(AFX_MLTP_H__A5E96FE7_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
#define AFX_MLTP_H__A5E96FE7_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
/////////////////////////////////////////////////////////////////////////////
// CMLTPApp:
// See MLTP.cpp for the implementation of this class
//

class CMLTPApp : public CWinApp
{
public:
	CMLTPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMLTPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMLTPApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MLTP_H__A5E96FE7_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
