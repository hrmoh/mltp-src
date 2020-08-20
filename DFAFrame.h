#if !defined(AFX_DFAFRAME_H__07FC0CA1_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_)
#define AFX_DFAFRAME_H__07FC0CA1_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DFAFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDFAFrame dialog

class CDFAFrame : public CDialog
{
// Construction
public:
	BOOL Visible;
	CDFAFrame(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDFAFrame)
	enum { IDD = IDD_DFAFRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDFAFrame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDFAFrame)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DFAFRAME_H__07FC0CA1_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_)
