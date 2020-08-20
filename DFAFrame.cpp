// DFAFrame.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "DFAFrame.h"
#include "MLTPDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDFAFrame dialog


CDFAFrame::CDFAFrame(CWnd* pParent /*=NULL*/)
	: CDialog(CDFAFrame::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDFAFrame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	Visible=FALSE;
}


void CDFAFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDFAFrame)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDFAFrame, CDialog)
	//{{AFX_MSG_MAP(CDFAFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDFAFrame message handlers

BOOL CDFAFrame::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(Visible)
	{
		CMLTPDlg* p=(CMLTPDlg*)GetParent();
		NFA nfa;
		p->Current.EquivalentNFA(nfa);
		nfa.Show(this);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

