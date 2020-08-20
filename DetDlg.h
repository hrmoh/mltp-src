#if !defined(AFX_DETDLG_H__A3B8ABC4_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_)
#define AFX_DETDLG_H__A3B8ABC4_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_

#include "Combo.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetDlg dialog

class CDetDlg : public CDialog
{
// Construction
public:
    CString m_Start;
	int m_VNumber;
	CString m_Variables[100];
	CDetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDetDlg)
	enum { IDD = IDD_DETSTART };
	CComboBox	m_Combo;
	CString	m_Choice;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnAok();
	afx_msg void OnAcancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETDLG_H__A3B8ABC4_3FE0_11D4_A2C4_95CDAA6F470E__INCLUDED_)
