#if !defined(AFX_NEWTERMINAL_H__117D6902_4006_11D4_A2C4_F610A022EC0F__INCLUDED_)
#define AFX_NEWTERMINAL_H__117D6902_4006_11D4_A2C4_F610A022EC0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewTerminal.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewTerminal dialog

class CNewTerminal : public CDialog
{
// Construction
public:
	char m_Terminal;
	CNewTerminal(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewTerminal)
	enum { IDD = IDD_DIALOG1 };
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTerminal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewTerminal)
	afx_msg void OnAok();
	afx_msg void OnAcancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTERMINAL_H__117D6902_4006_11D4_A2C4_F610A022EC0F__INCLUDED_)
