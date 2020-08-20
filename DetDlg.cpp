// DetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "DetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetDlg dialog


CDetDlg::CDetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetDlg)
	m_Choice = _T("");
	//}}AFX_DATA_INIT
	m_Choice="@";
}


void CDetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetDlg)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_CBString(pDX, IDC_COMBO1, m_Choice);
	DDV_MaxChars(pDX, m_Choice, 2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetDlg, CDialog)
	//{{AFX_MSG_MAP(CDetDlg)
	ON_BN_CLICKED(IDC_AOK, OnAok)
	ON_BN_CLICKED(IDC_ACANCEL, OnAcancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetDlg message handlers


BOOL CDetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_Choice='@';
	m_Start='@';
	CenterWindow(GetParent());
	// TODO: Add extra initialization here
	for(int i=0;i<m_VNumber;i++)
	   m_Combo.AddString(m_Variables[i]);
	UpdateData(TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDetDlg::OnAok() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	BOOL Found=FALSE;
    for(int i=0;i<m_VNumber;i++)
		if(m_Variables[i]==m_Choice)
		{
			Found=TRUE;
			break;
		}
    if(!Found)
		MessageBox("You should select an entered variable!","Error",MB_ICONSTOP);
	else
	{
		UpdateData(TRUE);
        OnOK();
	}


}

void CDetDlg::OnAcancel() 
{
	// TODO: Add your control notification handler code here
	 OnCancel();
}
