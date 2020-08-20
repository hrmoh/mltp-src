#if !defined(AFX_ANOUNCEDLG_H__07FC0CA2_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_)
#define AFX_ANOUNCEDLG_H__07FC0CA2_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnounceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnounceDlg dialog

class CAnounceDlg : public CDialog
{
// Construction
public:
	CAnounceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAnounceDlg)
	enum { IDD = IDD_ANOUNCE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnounceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAnounceDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowBitmap(CPaintDC *pdc,CWnd *pWnd);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANOUNCEDLG_H__07FC0CA2_43FE_11D4_A2C4_F1A07AAC640E__INCLUDED_)
