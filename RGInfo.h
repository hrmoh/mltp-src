#if !defined(AFX_RGINFO_H__E55B07C1_4306_11D4_A2C4_BD7EE56B900F__INCLUDED_)
#define AFX_RGINFO_H__E55B07C1_4306_11D4_A2C4_BD7EE56B900F__INCLUDED_

#include "RegularGrammar.h"	// Added by ClassView
#include "PInfo.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RGInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRGInfo dialog

class CRGInfo : public CDialog
{
// Construction
public:
	CPInfo m_PInfo;
	CString m_List[100];
	int m_Number;
	//RegularGrammar RG;
	CRGInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRGInfo)
	enum { IDD = IDD_GRAMMAR_INFO };
//	CComboBox	m_PList;
	CString	m_Variables;
	CString	m_Terminals;
	CString	m_S;
//	CString	m_Head;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRGInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRGInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnProductions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RGINFO_H__E55B07C1_4306_11D4_A2C4_BD7EE56B900F__INCLUDED_)
