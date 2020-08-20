// RGInfo.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "RGInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRGInfo dialog


CRGInfo::CRGInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CRGInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRGInfo)
	m_Variables = _T("");
	m_Terminals = _T("");
	m_S = _T("");
//	m_Head = _T("");
	//}}AFX_DATA_INIT
}


void CRGInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRGInfo)
//	DDX_Control(pDX, IDC_COMBO1, m_PList);
	DDX_Text(pDX, IDC_VARIABLES, m_Variables);
	DDV_MaxChars(pDX, m_Variables, 256);
	DDX_Text(pDX, IDC_TERMINALS, m_Terminals);
	DDV_MaxChars(pDX, m_Terminals, 300);
	DDX_Text(pDX, IDC_S, m_S);
	DDV_MaxChars(pDX, m_S, 4);
//	DDX_CBString(pDX, IDC_COMBO1, m_Head);
//	DDV_MaxChars(pDX, m_Head, 300);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRGInfo, CDialog)
	//{{AFX_MSG_MAP(CRGInfo)
	ON_BN_CLICKED(IDC_PRODUCTIONS, OnProductions)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRGInfo message handlers

BOOL CRGInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//m_PList.Clear();
	//for(int i=0;m_List[i]!="end";i++)
	//	m_PList.AddString(m_List[i]);
	//m_Head=m_List[0];
    //m_PList.SelectString(10,m_Head);
	CenterWindow(GetParent());
	UpdateData(TRUE);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRGInfo::OnProductions() 
{
	// TODO: Add your control notification handler code here
	m_PInfo.Create(IDD_PRODUCTIONS,this);
	m_PInfo.ShowWindow(SW_SHOW);
}
