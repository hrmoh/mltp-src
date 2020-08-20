#if !defined(AFX_ACDLG_H__487F646F_45C1_11D4_A2C5_DDD1004CB709__INCLUDED_)
#define AFX_ACDLG_H__487F646F_45C1_11D4_A2C5_DDD1004CB709__INCLUDED_

#include "DerivationDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AcDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAcDlg dialog

class CAcDlg : public CDialog
{
// Construction
public:
	int i;
	int m_AcceptedNumber;
	CString m_Accepted[200];
	CAcDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAcDlg)
	enum { IDD = IDD_ACCEPTED };
	CButton	m_Pre;
	CButton	m_Next;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnExit();
	afx_msg void OnNext();
	afx_msg void OnPre();
	afx_msg void OnDerivationTree();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACDLG_H__487F646F_45C1_11D4_A2C5_DDD1004CB709__INCLUDED_)
