// NewgrammarDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "NewgrammarDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "NewVarDlg.h"
#include "MLTPDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CNewgrammarDlg dialog


CNewgrammarDlg::CNewgrammarDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewgrammarDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewgrammarDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	SetAsStart=FALSE;
}


void CNewgrammarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewgrammarDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewgrammarDlg, CDialog)
	//{{AFX_MSG_MAP(CNewgrammarDlg)
	ON_BN_CLICKED(IDC_VARIABLES, OnVariables)
	ON_BN_CLICKED(IDC_DET, OnDet)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_TERMINALS, OnTerminals)
	ON_BN_CLICKED(IDC_PRODUCTIONS, OnProductions)
	ON_BN_CLICKED(IDC_OK, OnAOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

RegularGrammar CNewgrammarDlg::NewRegularGrammar()
{
  return New;
}

void CNewgrammarDlg::OnVariables() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	New.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}

	m_VarDlg.m_CurrentStart=New.GetStart();
	m_VarDlg.Create(IDD_NEWVAR,this);
	m_VarDlg.ShowWindow(SW_SHOW);
}

void CNewgrammarDlg::OnDet() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	New.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	if(m_Det.m_Choice!="@")
		New.SetAsStart(m_Det.m_Choice[0]);
    m_Det.m_VNumber=New.NumberOfVariables();
    for(int i=0;i<New.NumberOfVariables();i++)
	   {
       char ch2[2];
	   ch2[0]=New.GetVariable(i);
	   ch2[1]='\0';
	   m_Det.m_Variables[i]=ch2;
	   }
	m_Det.Create(IDD_DETSTART,this);
	m_Det.ShowWindow(SW_SHOW);
}


void CNewgrammarDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	New.PNumber=0;
	New.VNumber=0;
	New.TNumber=0;
	CMLTPDlg *Father=(CMLTPDlg *)GetParent();
	Father->CurrentUpdate=FALSE;
	OnOK();
}

void CNewgrammarDlg::OnTerminals() 
{
	// TODO: Add your control notification handler code here
	if(m_TerminalDlg.m_Terminal!='@')
	{
	New.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}

	m_TerminalDlg.Create(IDD_DIALOG1,this);
	m_TerminalDlg.ShowWindow(SW_SHOW);
	
}

void CNewgrammarDlg::OnProductions() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	New.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	if(m_TerminalDlg.m_Terminal!='@')
	{
	New.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}
	//
	CString Error=" ";
	int ErrorPosition=0;
	if(m_PDlg.Valid)
	{
		New.AddToProductions(m_PDlg.m_Text,Error,ErrorPosition);
		m_PDlg.Valid=FALSE;
	}
	m_PDlg.SetTNumber(New.NumberOfTerminals());
	for(int i=0;i<New.NumberOfTerminals();i++)
		m_PDlg.SetTerminals(i,New.GetTerminal(i));
	m_PDlg.SetVNumber(New.NumberOfVariables());
	for(i=0;i<New.NumberOfVariables();i++)
        m_PDlg.SetVariables(i,New.GetVariable(i));
	m_PDlg.SetLinearity(New.GetLinearity());
	m_PDlg.Create(IDD_PRO,this);
	m_PDlg.ShowWindow(SW_SHOW);
}

void CNewgrammarDlg::OnAOk() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	New.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	for(int i=0;i<New.VNumber;i++)
    if(m_Det.m_Choice[0]==New.Variables[i])
	{
		New.SetAsStart(m_Det.m_Choice[0]);
	}
	if(m_TerminalDlg.m_Terminal!='@')
	{
	New.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}
	//
	CString Error=" ";
	int ErrorPosition=0;
	if(m_PDlg.Valid)
	{
		New.AddToProductions(m_PDlg.m_Text,Error,ErrorPosition);
		m_PDlg.Valid=FALSE;
	}
	if(New.GetStart()=='@')
		MessageBox("A valid start variable has not been determined!","Error   ",MB_ICONSTOP);
	else
       if(!New.NumberOfProductions())
		   MessageBox("You have not entered a production yet!","Error    ",MB_ICONSTOP);
	   else
	   {
		m_RGInfo.m_Variables="V={ ";
      	for(int i=0;i<New.NumberOfVariables()-1;i++)
		{
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+New.GetVariable(i);
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+" , ";
		}
		
      	m_RGInfo.m_Variables=m_RGInfo.m_Variables+New.GetVariable(New.NumberOfVariables()-1);
	    m_RGInfo.m_Variables=m_RGInfo.m_Variables+" }";

		m_RGInfo.m_Terminals="T={ ";
      	for(i=0;i<New.NumberOfTerminals()-1;i++)
		{
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+New.GetTerminal(i);
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" , ";
		}
		if(New .NumberOfTerminals())
      	   m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+New.GetTerminal(New.NumberOfTerminals()-1);
	    m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" }";
        m_RGInfo.m_S="S= ";
		m_RGInfo.m_S=m_RGInfo.m_S+New.GetStart();
		for(i=0;i<New.PNumber;i++)
			m_RGInfo.m_List[i]=New.GetProduction(i);
		//m_RGInfo.m_List[New.PNumber]="end";
        m_RGInfo.m_Number=New.PNumber; 
        m_RGInfo.Create(IDD_GRAMMAR_INFO,this);
	    m_RGInfo.ShowWindow(SW_SHOW);
		CMLTPDlg *Father=(CMLTPDlg *)GetParent();
		Father->CurrentUpdate=TRUE;
    	OnOK();
	   }
}

BOOL CNewgrammarDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	New.Start='@';
	New.TNumber=0;
	New.VNumber=0;
	New.PNumber=0;
	New.Linearity=NOT_DETERMINED;
	CenterWindow(GetParent());
	UpdateData(TRUE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
