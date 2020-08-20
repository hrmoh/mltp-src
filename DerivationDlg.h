#if !defined(AFX_DERIVATIONDLG_H__88562D81_4689_11D4_A2C5_BDC6DDDB030B__INCLUDED_)
#define AFX_DERIVATIONDLG_H__88562D81_4689_11D4_A2C5_BDC6DDDB030B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DerivationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDerivationDlg dialog

class CDerivationDlg : public CDialog
{
// Construction
public:
	int INT;
	int m_Number[100];
	int index;
	CString m_Derivations[50][5];
	CDerivationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDerivationDlg)
	enum { IDD = IDD_DERIVATION };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDerivationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDerivationDlg)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowProduction(int& varposition,int i,CPaintDC* pdc);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DERIVATIONDLG_H__88562D81_4689_11D4_A2C5_BDC6DDDB030B__INCLUDED_)
