// SAcception.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "SAcception.h"
#include "MLTPDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSAcception dialog


CSAcception::CSAcception(CWnd* pParent /*=NULL*/)
	: CDialog(CSAcception::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSAcception)
	m_Edit = _T("");
	//}}AFX_DATA_INIT
	Valid=FALSE;
	TNumber=0;
}


void CSAcception::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSAcception)
	DDX_Text(pDX, IDC_EDIT1, m_Edit);
	DDV_MaxChars(pDX, m_Edit, 300);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSAcception, CDialog)
	//{{AFX_MSG_MAP(CSAcception)
	ON_BN_CLICKED(IDC_CANCEL, OnSCancel)
	ON_BN_CLICKED(IDC_OK, OnSOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSAcception message handlers

void CSAcception::OnSCancel() 
{
	// TODO: Add your control notification handler code here
	if(Valid)
	  m_Edit=preStr;
	OnCancel();
	
}

void CSAcception::OnSOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int Error=-1;
	for(int i=0;i<m_Edit.GetLength();i++)
		if(!isInTerminals(m_Edit[i]))
		{
			Error=i;
			break;
		}
	if(Error==-1)
	{
	   Valid=TRUE;
	   preStr=m_Edit;
	   OnOK();
	}
	else
	{
		CString ES="Unknown identifier ";
		ES=ES+m_Edit[Error];
		MessageBox(ES,"Error                            ",MB_ICONSTOP|MB_OK);
	}
}

BOOL CSAcception::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	UpdateData(TRUE);
	if(Valid)
		preStr=m_Edit;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CSAcception::isInTerminals(char c)
{
 for(int i=0;i<TNumber;i++)
	 if(Terminals[i]==c)
		 return TRUE;
 return FALSE;
}
