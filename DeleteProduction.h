#if !defined(AFX_DELETEPRODUCTION_H__0E649842_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_)
#define AFX_DELETEPRODUCTION_H__0E649842_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteProduction.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteProduction dialog

class CDeleteProduction : public CDialog
{
// Construction
public:
	int m_index;
	CDeleteProduction(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteProduction)
	enum { IDD = IDD_DELETE_PRODUCTION };
	CButton	m_Pre;
	CButton	m_Next;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteProduction)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteProduction)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnPre();
	afx_msg void OnNext();
	afx_msg void OnDcancel();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEPRODUCTION_H__0E649842_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_)
