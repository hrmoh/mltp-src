#if !defined(AFX_NEWGRAMMARDLG_H__0BC5CE21_3F85_11D4_A2C4_DBB721D26A11__INCLUDED_)
#define AFX_NEWGRAMMARDLG_H__0BC5CE21_3F85_11D4_A2C4_DBB721D26A11__INCLUDED_

#include "DetDlg.h"	// Added by ClassView
#include "RegularGrammar.h"	// Added by ClassView
#include "NewVarDlg.h"	// Added by ClassView
#include "NewTerminal.h"	// Added by ClassView
#include "PDlg.h"	// Added by ClassView
#include "RGInfo.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewgrammarDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewgrammarDlg dialog

class CNewgrammarDlg : public CDialog
{
// Construction
public:
	CRGInfo m_RGInfo;
	BOOL SetAsStart;
	RegularGrammar NewRegularGrammar();
	CNewgrammarDlg(CWnd* pParent = NULL);   // standard constructor
	RegularGrammar New;
// Dialog Data
	//{{AFX_DATA(CNewgrammarDlg)
	enum { IDD = IDD_NEWGRAMMAR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewgrammarDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewgrammarDlg)
	afx_msg void OnVariables();
	afx_msg void OnDet();
	afx_msg void OnButton5();
	afx_msg void OnTerminals();
	afx_msg void OnProductions();
	afx_msg void OnAOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CPDlg m_PDlg;
	CNewTerminal m_TerminalDlg;
	CDetDlg m_Det;
	CNewVarDlg m_VarDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWGRAMMARDLG_H__0BC5CE21_3F85_11D4_A2C4_DBB721D26A11__INCLUDED_)
