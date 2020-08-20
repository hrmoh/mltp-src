// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "MLTPDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_BN_CLICKED(IDC_VAR, OnVar)
	ON_BN_CLICKED(IDC_ADD_TO_TERMINALS, OnAddToTerminals)
	ON_BN_CLICKED(IDC_SET_AS_START, OnSetAsStart)
	ON_BN_CLICKED(IDC_ADD_TO_PRODUCTIONS, OnAddToProductions)
	ON_BN_CLICKED(IDC_EDIT_OK, OnEditOk)
	ON_BN_CLICKED(IDC_EDIT_CANCEL, OnEditCancel)
	ON_BN_CLICKED(IDC_DELETE_PRODUCTION, OnDeleteProduction)
	ON_BN_CLICKED(IDC_RESET_LINEARITY, OnResetLinearity)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers

BOOL CEditDlg::OnInitDialog() 
{
	// TODO: Add extra initialization here
	CDialog::OnInitDialog();
	CMLTPDlg* parent=(CMLTPDlg*)GetParent();
	EditingGrammar.Assign(parent->Current);
	EditingGrammar.Start=parent->Current.Start;
	EditingGrammar.PNumber=parent->Current.PNumber;
    for(int i=0;i<EditingGrammar.PNumber;i++)
       EditingGrammar.Productions[i].Set(parent->Current.GetProduction(i));
	EditingGrammar.Linearity=parent->Current.Linearity;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditDlg::OnVar() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	EditingGrammar.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	m_VarDlg.m_CurrentStart=EditingGrammar.GetStart();
	m_VarDlg.Create(IDD_NEWVAR,this);
	m_VarDlg.ShowWindow(SW_SHOW);
}

void CEditDlg::OnAddToTerminals() 
{
	// TODO: Add your control notification handler code here
	if(m_TerminalDlg.m_Terminal!='@')
	{
	EditingGrammar.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}

	m_TerminalDlg.Create(IDD_DIALOG1,this);
	m_TerminalDlg.ShowWindow(SW_SHOW);
}

void CEditDlg::OnSetAsStart() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	EditingGrammar.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	if(m_Det.m_Choice!="@")
		EditingGrammar.SetAsStart(m_Det.m_Choice[0]);
    m_Det.m_VNumber=EditingGrammar.NumberOfVariables();
    for(int i=0;i<EditingGrammar.NumberOfVariables();i++)
	   {
       char ch2[2];
	   ch2[0]=EditingGrammar.GetVariable(i);
	   ch2[1]='\0';
	   m_Det.m_Variables[i]=ch2;
	   }
	m_Det.Create(IDD_DETSTART,this);
	m_Det.ShowWindow(SW_SHOW);
}

void CEditDlg::OnAddToProductions() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	EditingGrammar.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	if(m_TerminalDlg.m_Terminal!='@')
	{
	EditingGrammar.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}
	//
	CString Error=" ";
	int ErrorPosition=0;
	if(m_PDlg.Valid)
	{
		EditingGrammar.AddToProductions(m_PDlg.m_Text,Error,ErrorPosition);
		m_PDlg.Valid=FALSE;
	}
	m_PDlg.SetTNumber(EditingGrammar.NumberOfTerminals());
	for(int i=0;i<EditingGrammar.NumberOfTerminals();i++)
		m_PDlg.SetTerminals(i,EditingGrammar.GetTerminal(i));
	m_PDlg.SetVNumber(EditingGrammar.NumberOfVariables());
	for(i=0;i<EditingGrammar.NumberOfVariables();i++)
        m_PDlg.SetVariables(i,EditingGrammar.GetVariable(i));
	m_PDlg.SetLinearity(EditingGrammar.GetLinearity());
	m_PDlg.Create(IDD_PRO,this);
	m_PDlg.ShowWindow(SW_SHOW);
	
}

void CEditDlg::OnEditOk() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	EditingGrammar.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	for(int i=0;i<EditingGrammar.VNumber;i++)
    if(m_Det.m_Choice[0]==EditingGrammar.Variables[i])
	{
		EditingGrammar.SetAsStart(m_Det.m_Choice[0]);
	}
	if(m_TerminalDlg.m_Terminal!='@')
	{
	EditingGrammar.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}
	//
	CString Error=" ";
	int ErrorPosition=0;
	if(m_PDlg.Valid)
	{
		EditingGrammar.AddToProductions(m_PDlg.m_Text,Error,ErrorPosition);
		m_PDlg.Valid=FALSE;
	}
	if(EditingGrammar.GetStart()=='@')
		MessageBox("A valid start variable has not been determined!","Error   ",MB_ICONSTOP);
	else
       if(!EditingGrammar.NumberOfProductions())
		   MessageBox("You have not entered a production yet!","Error    ",MB_ICONSTOP);
	   else
	   {
		m_RGInfo.m_Variables="V={ ";
      	for(int i=0;i<EditingGrammar.NumberOfVariables()-1;i++)
		{
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+EditingGrammar.GetVariable(i);
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+" , ";
		}
		
      	m_RGInfo.m_Variables=m_RGInfo.m_Variables+EditingGrammar.GetVariable(EditingGrammar.NumberOfVariables()-1);
	    m_RGInfo.m_Variables=m_RGInfo.m_Variables+" }";

		m_RGInfo.m_Terminals="T={ ";
      	for(i=0;i<EditingGrammar.NumberOfTerminals()-1;i++)
		{
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+EditingGrammar.GetTerminal(i);
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" , ";
		}
		if(EditingGrammar .NumberOfTerminals())
      	   m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+EditingGrammar.GetTerminal(EditingGrammar.NumberOfTerminals()-1);
	    m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" }";
        m_RGInfo.m_S="S= ";
		m_RGInfo.m_S=m_RGInfo.m_S+EditingGrammar.GetStart();
		for(i=0;i<EditingGrammar.PNumber;i++)
			m_RGInfo.m_List[i]=EditingGrammar.GetProduction(i);
        m_RGInfo.m_Number=EditingGrammar.PNumber; 
        m_RGInfo.Create(IDD_GRAMMAR_INFO,this);
	    m_RGInfo.ShowWindow(SW_SHOW);
		CMLTPDlg *Father=(CMLTPDlg *)GetParent();
		Father->Current.Assign(EditingGrammar);
	    Father->Current.Start=EditingGrammar.Start;
	    Father->Current.PNumber=EditingGrammar.PNumber;
	    for(i=0;i<EditingGrammar.PNumber;i++)
           Father->Current.Productions[i].Set(EditingGrammar.GetProduction(i));
		OnOK();
	   }
	
}

void CEditDlg::OnEditCancel() 
{
	// TODO: Add your control notification handler code here
	EditingGrammar.PNumber=0;
	EditingGrammar.VNumber=0;
	EditingGrammar.TNumber=0;
	OnOK();
	
}

void CEditDlg::OnDeleteProduction() 
{
	// TODO: Add your control notification handler code here
	if(m_VarDlg.m_Variable!='@')
	{
	EditingGrammar.AddToVariables(m_VarDlg.m_Variable);
    m_VarDlg.m_Variable='@';
	}
	for(int i=0;i<EditingGrammar.VNumber;i++)
    if(m_Det.m_Choice[0]==EditingGrammar.Variables[i])
	{
		EditingGrammar.SetAsStart(m_Det.m_Choice[0]);
	}
	if(m_TerminalDlg.m_Terminal!='@')
	{
	EditingGrammar.AddToTerminals(m_TerminalDlg.m_Terminal);
    m_TerminalDlg.m_Terminal='@';
	}
	//
	CString Error=" ";
	int ErrorPosition=0;
	if(m_PDlg.Valid)
	{
		EditingGrammar.AddToProductions(m_PDlg.m_Text,Error,ErrorPosition);
		m_PDlg.Valid=FALSE;
	}

    if(EditingGrammar.PNumber)
	{
		m_Delete.Create(IDD_DELETE_PRODUCTION,this);
		m_Delete.ShowWindow(SW_SHOW);
	}
	else
	   MessageBox("This grammar has'nt any production to bd deleted!","Invalid Operation");
}

void CEditDlg::OnResetLinearity() 
{
	// TODO: Add your control notification handler code here
	if(
		MessageBox("This operation will end in deleting linear productions.\n Do you want to continue?","Warning",MB_OKCANCEL|MB_ICONEXCLAMATION)
		==
		IDOK
		)
	{
        EditingGrammar.ResetLinearity();
	}
		
}
