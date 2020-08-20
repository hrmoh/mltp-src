// SetAsStartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "SetAsStartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetAsStartDlg dialog


CSetAsStartDlg::CSetAsStartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetAsStartDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetAsStartDlg)
	m_Text = _T("");
	//}}AFX_DATA_INIT
	Set=FALSE;
}


void CSetAsStartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetAsStartDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	//}}AFX_DATA_MAP
	m_Text=m_CurrentStart;
}


BEGIN_MESSAGE_MAP(CSetAsStartDlg, CDialog)
	//{{AFX_MSG_MAP(CSetAsStartDlg)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetAsStartDlg message handlers

void CSetAsStartDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	Set=TRUE;
	UpdateData(TRUE);
	OnOK();
}

void CSetAsStartDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
