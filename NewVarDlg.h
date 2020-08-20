#if !defined(AFX_NEWVARDLG_H__A3B8ABC2_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_)
#define AFX_NEWVARDLG_H__A3B8ABC2_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_

#include "SetAsStartDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewVarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewVarDlg dialog

class CNewVarDlg : public CDialog
{
// Construction
public:
	char m_CurrentStart;
	char m_Variable;
	CNewVarDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CNewVarDlg)
	enum { IDD = IDD_NEWVAR };
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewVarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewVarDlg)
	afx_msg void OnAok();
	afx_msg void OnAcancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWVARDLG_H__A3B8ABC2_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_)
