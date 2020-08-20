#if !defined(AFX_PINFO_H__48A135E1_4611_11D4_A2C5_8A81BA6D5B0B__INCLUDED_)
#define AFX_PINFO_H__48A135E1_4611_11D4_A2C5_8A81BA6D5B0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPInfo dialog

class CPInfo : public CDialog
{
// Construction
public:
	int m_index;
	CPInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPInfo)
	enum { IDD = IDD_PRODUCTIONS };
	CButton	m_pre;
	CButton	m_Next;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPInfo)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnPok();
	afx_msg void OnNext();
	afx_msg void OnPre();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PINFO_H__48A135E1_4611_11D4_A2C5_8A81BA6D5B0B__INCLUDED_)
