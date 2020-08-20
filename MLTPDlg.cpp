// MLTPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//RegularGrammar Current;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
    
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMLTPDlg dialog

CMLTPDlg::CMLTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMLTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMLTPDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CenterWindow();
    AnounceName=TRUE;
	CurrentString="";
    SubStringsNumber=0;
	CurrentUpdate=FALSE;
}

void CMLTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMLTPDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMLTPDlg, CDialog)
	//{{AFX_MSG_MAP(CMLTPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_GRAMMAR_EXIT, OnGrammarExit)
	ON_COMMAND(ID_GRAMMAR_NEW, OnGrammarNew)
	ON_COMMAND(ID_GRAMMAR_SUMMARYINFO, OnGrammarSummaryinfo)
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_COMMAND(ID_DFA_SHOW, OnNfaShow)
	ON_COMMAND(ID_NFA_HIDE, OnNfaHide)
	ON_COMMAND(ID_STRING_ACCEPT, OnStringAccept)
	ON_COMMAND(ID_DDFA_SHOW, OnDdfaShow)
	ON_COMMAND(ID_DFA_HIDE, OnDfaHide)
	ON_COMMAND(ID_STRING_SUBSTRINGSACCEPTED, OnStringSubstringsaccepted)
	ON_COMMAND(ID_GRAMMAR_EDIT, OnGrammarEdit)
	ON_COMMAND(ID_DFA_MINIMIZE, OnDfaMinimize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMLTPDlg message handlers

BOOL CMLTPDlg::OnInitDialog()
{

	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	if(AnounceName)
	{
		CString BitmapPath="THEORY.BMP";
		HBITMAP hBitmap=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			BitmapPath,IMAGE_BITMAP,0,0,
			LR_LOADFROMFILE|LR_CREATEDIBSECTION);
		if(hBitmap)
			m_bmpBitmap.Attach(hBitmap);
		m_Anounce.Create(IDD_ANOUNCE,this);
		m_Anounce.ShowWindow(SW_SHOW);
		AnounceName=FALSE;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMLTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMLTPDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMLTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMLTPDlg::OnGrammarExit() 
{
	// TODO: Add your command handler code here
    OnOK();	
}

void CMLTPDlg::OnGrammarNew() 
{
	// TODO: Add your command handler code here
    m_NewDialog.Create(IDD_NEWGRAMMAR,this);
	m_NewDialog.ShowWindow(SW_SHOW);
}



void CMLTPDlg::OnGrammarSummaryinfo() 
{
	// TODO: Add your command handler code here
	    UpdateCurrent();
		if(Current.NumberOfProductions())
		{
		m_RGInfo.m_Variables="V={ ";
      	for(int i=0;i<Current.NumberOfVariables()-1;i++)
		{
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+Current.GetVariable(i);
		 m_RGInfo.m_Variables=m_RGInfo.m_Variables+" , ";
		}
		
      	m_RGInfo.m_Variables=m_RGInfo.m_Variables+Current.GetVariable(Current.NumberOfVariables()-1);
	    m_RGInfo.m_Variables=m_RGInfo.m_Variables+" }";

		m_RGInfo.m_Terminals="T={ ";
      	for(i=0;i<Current.NumberOfTerminals()-1;i++)
		{
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+Current.GetTerminal(i);
		 m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" , ";
		}
		if(Current .NumberOfTerminals())
      	   m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+Current.GetTerminal(Current.NumberOfTerminals()-1);
	    m_RGInfo.m_Terminals=m_RGInfo.m_Terminals+" }";
        m_RGInfo.m_S="S= ";
		m_RGInfo.m_S=m_RGInfo.m_S+Current.GetStart();
		for(i=0;i<Current.PNumber;i++)
			m_RGInfo.m_List[i]=Current.GetProduction(i);
        m_RGInfo.m_Number=Current.PNumber; 
        m_RGInfo.Create(IDD_GRAMMAR_INFO,this);
	    m_RGInfo.ShowWindow(SW_SHOW);
		}
		else
			MessageBox("You should first enter a grammar.","Invalid Operation",MB_ICONSTOP);
		
}



void CMLTPDlg::OnHelpAbout() 
{
	// TODO: Add your command handler code here
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
}

void CMLTPDlg::OnNfaShow() 
{
	// TODO: Add your command handler code here
	if(m_Frame.IsWindowVisible())
		m_Frame.DestroyWindow();
	UpdateCurrent();
	if(Current.Linearity==LEFT_LINEAR)
	{
		MessageBox("This operation can not be done for left linear grammars.");
		return;
	}
		m_SAccept.TNumber=Current.TNumber;
		for(int i=0;i<Current.TNumber;i++)
			m_SAccept.Terminals[i]=Current.Terminals[i];
	if(Current.PNumber)
	{
		NFA ENFA;
		Current.EquivalentNFA(ENFA);
		m_Frame.Visible=TRUE;
		m_Frame.Create(IDD_DFAFRAME,this);
		m_Frame.ShowWindow(SW_SHOW);
		ENFA.Show(&m_Frame);
	}
		else
			MessageBox("You should first enter a grammar.","Invalid Operation",MB_ICONSTOP);
}



void CMLTPDlg::OnNfaHide() 
{
	// TODO: Add your command handler code here
	if(m_Frame.IsWindowVisible())
		m_Frame.DestroyWindow();
}

void CMLTPDlg::OnStringAccept() 
{
	// TODO: Add your command handler code here
	    UpdateCurrent();
		m_SAccept.TNumber=Current.TNumber;
		for(int i=0;i<Current.TNumber;i++)
			m_SAccept.Terminals[i]=Current.Terminals[i];
        m_SAccept.Create(IDD_STRING_ACCEPTION,this);
	    m_SAccept.ShowWindow(SW_SHOW);
}

BOOL CMLTPDlg::isValid(CString AString)
{
 for(int i=0;i<AString.GetLength();i++)
 {
	 BOOL Found=FALSE;
	 int ErrorPosition;
	 for(int j=0;j<Current.NumberOfTerminals();j++)
		 if(Current.GetTerminal(j)==AString[i])
		 {
		     ErrorPosition=j;
			 Found=TRUE;
		 }
	 if(!Found)
		 return FALSE;
 }
 return TRUE;
}

void CMLTPDlg::OnDdfaShow() 
{
	// TODO: Add your command handler code here
	if(m_DDFrame.IsWindowVisible())
		m_DDFrame.DestroyWindow();
    UpdateCurrent();
	if(Current.Linearity==LEFT_LINEAR)
	{
		MessageBox("This operation can not be done for left linear grammars.");
		return;
	}
		m_SAccept.TNumber=Current.TNumber;
		for(int i=0;i<Current.TNumber;i++)
			m_SAccept.Terminals[i]=Current.Terminals[i];

	if(Current.PNumber)
	{
		NFA nfa;
		Current.EquivalentNFA(nfa);
        m_DDFrame.Visible=TRUE;
		m_DDFrame.Create(IDD_DDFAFRAME,this);
		m_DDFrame.ShowWindow(SW_SHOW);
		DFA dfa;
		nfa.EquivalentDFA(dfa);
		dfa.Show(&m_DDFrame);
	}
		else
			MessageBox("You should first enter a grammar.","Invalid Operation",MB_ICONSTOP);
}

void CMLTPDlg::OnDfaHide() 
{
	// TODO: Add your command handler code here
	if(m_DDFrame.IsWindowVisible())
        m_DDFrame.DestroyWindow();	
}


void CMLTPDlg::GenerateAllSubstrings(CString Str)
{
  if(Str.GetLength()==1)
	  AddToSubstrings(Str);
  else
  {
    for(int i=0;i<Str.GetLength();i++)
	{
	CString tStr=Str;
	tStr.Delete(i,1);
	if(Str.Find(tStr,0)>=0&&Str.Find(tStr,0)<Str.GetLength())
	     AddToSubstrings(tStr);
	GenerateAllSubstrings(tStr);
	}
  }
  
}

void CMLTPDlg::AddToSubstrings(CString Str)
{
 for(int i=0;i<SubStringsNumber;i++)
	 if(Str==SubStrings[i])
		 return;
 SubStrings[SubStringsNumber++]=Str;
}

void CMLTPDlg::OnStringSubstringsaccepted() 
{
	// TODO: Add your command handler code here

	UpdateCurrent();
	if(Current.PNumber&&m_SAccept.Valid)
	{
/*
    using DFA:


    if(Current.Linearity==RIGHT_LINEAR
		||
	   Current.Linearity==NOT_DETERMINED
	   )
	{   
	NFA nfa;
	Current.EquivalentNFA(nfa);
	DFA dfa;
	nfa.EquivalentDFA(dfa);
	CurrentString=m_SAccept.m_Edit;
	SubStringsNumber=0;
	BeginWaitCursor();
	GenerateAllSubstrings(CurrentString);
	EndWaitCursor();
    m_AccDlg.m_AcceptedNumber=0;
	if(dfa.Accepts("@"))
       	m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]="@";
    if(dfa.Accepts(m_SAccept.m_Edit))
        m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]=m_SAccept.m_Edit;
	for(int i=0;i<SubStringsNumber;i++)
	{
		if(dfa.Accepts(SubStrings[i]))
		{
			BOOL Found=FALSE;
			for(int j=0;j<m_AccDlg.m_AcceptedNumber;j++)
				if(m_AccDlg.m_Accepted[j]==SubStrings[i])
					Found=TRUE;
            if(!Found)
                m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]=SubStrings[i];
		}
	}
    if(m_AccDlg.m_AcceptedNumber==0)
		MessageBox("No substring accepted!");
	else
	{
    m_AccDlg.Create(IDD_ACCEPTED,this);
	m_AccDlg.ShowWindow(SW_SHOW);
	}
	}
	else
*/	
	{
//using Grammar:
		
	CurrentString=m_SAccept.m_Edit;
	SubStringsNumber=0;
	BeginWaitCursor();
	GenerateAllSubstrings(CurrentString);
	EndWaitCursor();
    m_AccDlg.m_AcceptedNumber=0;

	CString Str="@";
	{
	int index=0;
	int indexes[20];
	if(Current.ifAccepts(Str,index,indexes))
	{
       	m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]="@";
        m_Derivation.m_Number[m_AccDlg.m_AcceptedNumber-1]=index;
		for(int i=0;i<=index;i++)
		    m_Derivation.m_Derivations[0][i]=Current.Productions[indexes[i]].GetProduction();
	}
    }

	Str=m_SAccept.m_Edit;
	{
	int index=0;
	int indexes[20];
    if(Current.ifAccepts(Str,index,indexes))
	{
        m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]=m_SAccept.m_Edit;
        m_Derivation.m_Number[m_AccDlg.m_AcceptedNumber-1]=index;
		for(int i=0;i<=index;i++)
		    m_Derivation.m_Derivations[m_AccDlg.m_AcceptedNumber-1][i]=Current.Productions[indexes[i]].GetProduction();
	}
	}
	
	for(int i=0;i<SubStringsNumber;i++)
	{
		Str=SubStrings[i];
	    int index=0;
		int indexes[20];
		if(Current.ifAccepts(Str,index,indexes))
		{
			BOOL Found=FALSE;
			for(int j=0;j<m_AccDlg.m_AcceptedNumber;j++)
				if(m_AccDlg.m_Accepted[j]==SubStrings[i])
					Found=TRUE;
            if(!Found)
			{
                m_AccDlg.m_Accepted[m_AccDlg.m_AcceptedNumber++]=SubStrings[i];
                m_Derivation.m_Number[m_AccDlg.m_AcceptedNumber-1]=index;
		        for(int i=0;i<=index;i++)
		             m_Derivation.m_Derivations[m_AccDlg.m_AcceptedNumber-1][i]=Current.Productions[indexes[i]].GetProduction();

			}
		}

		
	}

	
    if(m_AccDlg.m_AcceptedNumber==0)
		MessageBox("No substring accepted!");
	else
	{
    m_AccDlg.Create(IDD_ACCEPTED,this);
	m_AccDlg.ShowWindow(SW_SHOW);
	}

	}
	}
		else
			MessageBox("You should first enter both a grammar and a string.","Invalid Operation",MB_ICONSTOP);
}

void CMLTPDlg::UpdateCurrent()
{
 if(CurrentUpdate)
 {
		Current.Assign(m_NewDialog.New);
		Current.Start=m_NewDialog.New.Start;
		Current.PNumber=m_NewDialog.New.PNumber;
		for(int i=0;i<Current.PNumber;i++)
         Current.Productions[i].Set(m_NewDialog.New.GetProduction(i));
		CurrentUpdate=FALSE;
 }
}

void CMLTPDlg::OnNew() 
{
	// TODO: Add your control notification handler code here
	
}




void CMLTPDlg::ShowDerivationTree(int index)
{
  if(m_Derivation.IsWindowVisible())
	  m_Derivation.DestroyWindow();
  m_Derivation.index=index;
  m_Derivation.Create(IDD_DERIVATION,this);
  m_Derivation.ShowWindow(SW_SHOW);
}

void CMLTPDlg::OnGrammarEdit() 
{
	// TODO: Add your command handler code here
  UpdateCurrent();
  if(Current.PNumber)
  {
  m_EditDlg.Create(IDD_EDIT,this);
  m_EditDlg.ShowWindow(SW_SHOW);
  }
  else
  MessageBox("You should enter a grammar first!","Invalid operation",MB_ICONSTOP);
}



void CMLTPDlg::OnDfaMinimize() 
{
	// TODO: Add your command handler code here
	if(m_DDFrame.IsWindowVisible())
		m_DDFrame.DestroyWindow();
    UpdateCurrent();
	if(Current.Linearity==LEFT_LINEAR)
	{
		MessageBox("This operation can not be done for left linear grammars.");
		return;
	}
		m_SAccept.TNumber=Current.TNumber;
		for(int i=0;i<Current.TNumber;i++)
			m_SAccept.Terminals[i]=Current.Terminals[i];

	if(Current.PNumber)
	{
		NFA nfa;
		Current.EquivalentNFA(nfa);
		DFA dfa;
		nfa.EquivalentDFA(dfa);
		dfa.Minimize();
        m_DDFrame.Visible=TRUE;
		m_DDFrame.Create(IDD_DDFAFRAME,this);
		m_DDFrame.ShowWindow(SW_SHOW);
		dfa.Show(&m_DDFrame);

	}
		else
			MessageBox("You should first enter a grammar.","Invalid Operation",MB_ICONSTOP);

	
}
