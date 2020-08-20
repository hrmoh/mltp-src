// NewTerminal.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "NewTerminal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewTerminal dialog


CNewTerminal::CNewTerminal(CWnd* pParent /*=NULL*/)
	: CDialog(CNewTerminal::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewTerminal)
	m_Text = _T("");
	//}}AFX_DATA_INIT
}


void CNewTerminal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewTerminal)
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDV_MaxChars(pDX, m_Text, 2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewTerminal, CDialog)
	//{{AFX_MSG_MAP(CNewTerminal)
	ON_BN_CLICKED(IDAOK, OnAok)
	ON_BN_CLICKED(IDACANCEL, OnAcancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTerminal message handlers

void CNewTerminal::OnAok() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    if(islower(m_Text[0]))
	{
		m_Terminal=m_Text[0];
		OnOK();
    }
	else
		MessageBox("A terminal name should be a small letter","Error",MB_ICONSTOP|MB_OK);
	
}

void CNewTerminal::OnAcancel() 
{
	// TODO: Add your control notification handler code here
	m_Terminal='@';
	OnCancel();
	
}

BOOL CNewTerminal::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CenterWindow(GetParent());
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
