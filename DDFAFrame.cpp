// DDFAFrame.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "DDFAFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "NFA.h"
#include "RegularGrammar.h"
#include "MLTPDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CDDFAFrame dialog


CDDFAFrame::CDDFAFrame(CWnd* pParent /*=NULL*/)
	: CDialog(CDDFAFrame::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDDFAFrame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	Visible=FALSE;
}


void CDDFAFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDDFAFrame)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDDFAFrame, CDialog)
	//{{AFX_MSG_MAP(CDDFAFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDDFAFrame message handlers

BOOL CDDFAFrame::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(Visible)
	{
		CMLTPDlg* MLTParent=(CMLTPDlg*)GetParent();
		NFA nfa;
        MLTParent->Current.EquivalentNFA(nfa);
		DFA dfa;
		nfa.EquivalentDFA(dfa);
		dfa.Show(this);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
