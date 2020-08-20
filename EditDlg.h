#if !defined(AFX_EDITDLG_H__0E649841_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_)
#define AFX_EDITDLG_H__0E649841_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_

#include "RegularGrammar.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDlg.h : header file
//

#include "PDlg.h"
#include "NewTerminal.h"
#include "DetDlg.h"
#include "NewVarDlg.h"
#include "RGInfo.h"	// Added by ClassView
#include "DeleteProduction.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog
class CEditDlg : public CDialog
{
// Construction
public:
	RegularGrammar EditingGrammar;
	CEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDlg)
	enum { IDD = IDD_EDIT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnVar();
	afx_msg void OnAddToTerminals();
	afx_msg void OnSetAsStart();
	afx_msg void OnAddToProductions();
	afx_msg void OnEditOk();
	afx_msg void OnEditCancel();
	afx_msg void OnDeleteProduction();
	afx_msg void OnResetLinearity();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDeleteProduction m_Delete;
	CRGInfo m_RGInfo;
	CPDlg m_PDlg;
	CNewTerminal m_TerminalDlg;
	CDetDlg m_Det;
	CNewVarDlg m_VarDlg;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__0E649841_4701_11D4_A2C5_F5DBC585CE04__INCLUDED_)
