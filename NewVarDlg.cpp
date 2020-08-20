// NewVarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "NewVarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CNewVarDlg dialog


CNewVarDlg::CNewVarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewVarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewVarDlg)
	m_Text = _T("");
	//}}AFX_DATA_INIT
	m_Variable='@';
}


void CNewVarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewVarDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDV_MaxChars(pDX, m_Text, 1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewVarDlg, CDialog)
	//{{AFX_MSG_MAP(CNewVarDlg)
	ON_BN_CLICKED(IDC_AOK, OnAok)
	ON_BN_CLICKED(IDC_ACANCEL, OnAcancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewVarDlg message handlers

void CNewVarDlg::OnAok() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if(isupper(m_Text[0]))
	{
		m_Variable=m_Text[0];
		OnOK();
    }
	else
		MessageBox("A variable name should be a capital letter","Error",MB_ICONSTOP|MB_OK);
}

void CNewVarDlg::OnAcancel() 
{
	// TODO: Add your control notification handler code here
	m_Variable='@';
	OnCancel();
}


BOOL CNewVarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CenterWindow(GetParent());	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
