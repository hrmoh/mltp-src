#if !defined(AFX_PDLG_H__117D6903_4006_11D4_A2C4_F610A022EC0F__INCLUDED_)
#define AFX_PDLG_H__117D6903_4006_11D4_A2C4_F610A022EC0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPDlg dialog

class CPDlg : public CDialog
{
// Construction
public:
	void SetLinearity(int n);
	void SetVariables(int n,char c);
	void SetTerminals(int i,char c);
	void SetTNumber(int n);
	void SetVNumber(int n);
	BOOL Valid;
	CPDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPDlg)
	enum { IDD = IDD_PRO };
	CString	m_Text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	int Linearity;
	char m_Terminals[100];
	char m_Variables[100];
	int m_TNumber;
	int m_VNumber;
protected:

	// Generated message map functions
	//{{AFX_MSG(CPDlg)
	afx_msg void OnAcancel();
	afx_msg void OnAok();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDLG_H__117D6903_4006_11D4_A2C4_F610A022EC0F__INCLUDED_)
