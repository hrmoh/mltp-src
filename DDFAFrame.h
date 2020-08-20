#if !defined(AFX_DDFAFRAME_H__9EBF6841_4588_11D4_A2C4_AC6F8E1F740D__INCLUDED_)
#define AFX_DDFAFRAME_H__9EBF6841_4588_11D4_A2C4_AC6F8E1F740D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DDFAFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDDFAFrame dialog

class CDDFAFrame : public CDialog
{
// Construction
public:
	BOOL Visible;
	CDDFAFrame(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDDFAFrame)
	enum { IDD = IDD_DDFAFRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDDFAFrame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDDFAFrame)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DDFAFRAME_H__9EBF6841_4588_11D4_A2C4_AC6F8E1F740D__INCLUDED_)
