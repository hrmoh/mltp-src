#if !defined(AFX_SACCEPTION_H__9EFF0DC1_44E2_11D4_A2C4_85569E37EA0A__INCLUDED_)
#define AFX_SACCEPTION_H__9EFF0DC1_44E2_11D4_A2C4_85569E37EA0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SAcception.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSAcception dialog

class CSAcception : public CDialog
{
// Construction
public:
	int TNumber;
	BOOL isInTerminals(char c);
	CString preStr;
	BOOL Valid;
	char Terminals[100];
	CSAcception(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSAcception)
	enum { IDD = IDD_STRING_ACCEPTION };
	CString	m_Edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSAcception)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSAcception)
	afx_msg void OnSCancel();
	afx_msg void OnSOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SACCEPTION_H__9EFF0DC1_44E2_11D4_A2C4_85569E37EA0A__INCLUDED_)
