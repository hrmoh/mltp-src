// MLTPDlg.h : header file
//

#if !defined(AFX_MLTPDLG_H__79196E07_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_)
#define AFX_MLTPDLG_H__79196E07_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_

#include "AcDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "RegularGrammar.H"
#include "NewgrammarDlg.H"
#include "RGInfo.h"	// Added by ClassView
#include "DFAFrame.h"	// Added by ClassView
#include "AnounceDlg.h"	// Added by ClassView
#include "SAcception.h"	// Added by ClassView
#include "MLTPDlg.h"
#include "DDFAFrame.h"	// Added by ClassView
#include "SAccepted.h"	// Added by ClassView
#include "Toolbar.h"
#include "DerivationDlg.h"	// Added by ClassView
#include "EditDlg.h"	// Added by ClassView
/////////////////////////////////////////////////////////////////////////////
// CMLTPDlg dialog
class CMLTPDlg : public CDialog
{
// Construction
public:
	CEditDlg m_EditDlg;
	void ShowDerivationTree(int index);
	CDerivationDlg m_Derivation;
	BOOL CurrentUpdate;
	void UpdateCurrent();
	CAcDlg m_AccDlg;
	int SubStringsNumber;
	CString SubStrings[300];
	void AddToSubstrings(CString Str);
	void GenerateAllSubstrings(CString Str);
	CSAcception m_SAccept;
	RegularGrammar Current;
	CDDFAFrame m_DDFrame;
	BOOL isValid(CString AString);
	CString CurrentString;
	CBitmap m_bmpBitmap;
	CAnounceDlg m_Anounce;
	BOOL AnounceName;
	CDFAFrame m_Frame;
	CMLTPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMLTPDlg)
	enum { IDD = IDD_MLTP_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMLTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMLTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGrammarExit();
	afx_msg void OnGrammarNew();
	afx_msg void OnGrammarSummaryinfo();
	afx_msg void OnHelpAbout();
	afx_msg void OnNfaShow();
	afx_msg void OnNfaHide();
	afx_msg void OnStringAccept();
	afx_msg void OnDdfaShow();
	afx_msg void OnDfaHide();
	afx_msg void OnStringSubstringsaccepted();
	afx_msg void OnNew();
	afx_msg void OnGrammarEdit();
	afx_msg void OnDfaMinimize();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CRGInfo m_RGInfo;
	CNewgrammarDlg m_NewDialog;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MLTPDLG_H__79196E07_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_)
