// PDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "PDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Production.H"

/////////////////////////////////////////////////////////////////////////////
// CPDlg dialog
CString CEleminateAdditionalSpaces(CString AString)
{
	char tempStr[256];
	for(int i=0;i<AString.GetLength();i++)
		tempStr[i]=AString[i];
	tempStr[i]='\0';
	int length=AString.GetLength()+1;
	do
	{
    length--;
	for(int i=0;i<length;i++)
		if(tempStr[i]==' ')
			break;
    if(i!=length)
	{	
      for(int j=i;j<length-1;j++)
		  tempStr[j]=tempStr[j+1];
	   tempStr[j]='\0';
	}
	}while(i!=length);
    CString Result=tempStr; 
	return Result;
}

BOOL CheckCopy(CString PDefinition,CString& Error,int &ErrorPosition)
{
	CEleminateAdditionalSpaces(PDefinition);
    int position=PDefinition.Find("->",0);
	//CHECKING ERRORS:

	if(position<0||position>PDefinition.GetLength()-1)
	{
	//1-Definition does not contain substring "=>"
		Error="Productions should contain '->'";
		return FALSE;
	}
	int p=PDefinition.Find("-",0);
	if(p>=0&&p<PDefinition.GetLength()&&(p!=position))
	{
		//2-Additional symbole '-'
		Error="Additional symbole '-'.";
		ErrorPosition=p;
		return FALSE;
	}
	p=PDefinition.Find("-",position+2);
	if(p>=0&&p<PDefinition.GetLength())
	{
		//2-Additional symbole '-'
		Error="Additional symbole '-'.";
		ErrorPosition=p;
		return FALSE;
	}
	p=PDefinition.Find(">",0);
	if(p>=0&&p<PDefinition.GetLength()&&(p!=position+1))
	{
		//2-Additional symbole '-'
		Error="Additional symbole '>'.";
		ErrorPosition=p;
		return FALSE;
	}
	p=PDefinition.Find(">",position+2);
	if(p>0&&p<PDefinition.GetLength())
	{
		//2-Additional symbole '-'
		Error="Additional symbole '>'.";
		ErrorPosition=p;
		return FALSE;
	}

	for(position=0;
	     (
			isalpha(PDefinition[position])
			||
			PDefinition[position]==' '
			||
			PDefinition[position]=='@'
			||
			PDefinition[position]=='-'
			||
			PDefinition[position]=='>'
		 );
		 position++
	   );
    if(position<PDefinition.GetLength())
	{
    //4-there is character in definition other than Space,Terminals,Variables,'-','>','|'and LAMBDA
    Error="Unknon symbole ["+PDefinition[position]+']';
	ErrorPosition=position;
	return FALSE;
	}
	for(position=0;(PDefinition[position]!='-'&&!isupper(PDefinition[position]))&&position<PDefinition.GetLength();position++);
    if(PDefinition[position]=='-')
	{
	//5-Left(Definition) contains no character other than Space and LAMBDA
    Error="Left of '->' contains no variable or terminal";
	return FALSE;
	}
	
	while(PDefinition[position]!='>')
		position++;
	position++;

	for(;position!=PDefinition.GetLength()&&PDefinition[position]==' ';position++);
   if(position==PDefinition.GetLength())
	{
	//6-Right(Definition) contains no character other than Space
    Error="Right of '->' contains no symbole";
	return FALSE;
	}
	return TRUE;
}

CPDlg::CPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPDlg)
	m_Text = _T("");
	//}}AFX_DATA_INIT
	Valid=FALSE;
}


void CPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDV_MaxChars(pDX, m_Text, 256);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPDlg, CDialog)
	//{{AFX_MSG_MAP(CPDlg)
	ON_BN_CLICKED(IDC_ACANCEL, OnAcancel)
	ON_BN_CLICKED(IDC_AOK, OnAok)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPDlg message handlers

void CPDlg::OnAcancel() 
{
	// TODO: Add your control notification handler code here
	Valid=FALSE;
	OnOK();
}

void CPDlg::OnAok() 
{
	// TODO: Add your control notification handler code here
	Valid=TRUE;
	int ErrorPosition=0;
	UpdateData(TRUE);
	for(int i=0;i<m_Text.GetLength();i++)
	{
        if(m_Text[i]!=' '&&m_Text[i]!='@'&&m_Text[i]!='-'&&m_Text[i]!='>')
		{
		BOOL AValidVariable=FALSE;
		for(int j=0;j<m_VNumber;j++)
			if(m_Variables[j]==m_Text[i])
				AValidVariable=TRUE;
        BOOL AValidTerminal=FALSE;
        if(!AValidVariable)
			for(j=0;j<m_TNumber;j++)
				if(m_Terminals[j]==m_Text[i])
				   AValidTerminal=TRUE;
          if(!(AValidVariable||AValidTerminal))
		  {
			  Valid=FALSE;
			  ErrorPosition=i;
			  break;
		  }

		}//IF
	}//FOR
	CString Error;
	char ch[2];
	ch[0]=m_Text[ErrorPosition];
	ch[1]='\0';
    Error="Unknown identifier '";
	Error=Error+ch;
	Error=Error+"'.";
	if(!Valid)
	  MessageBox(Error,"Error                   ",MB_ICONSTOP|MB_OK);
	else
	{
		if(!CheckCopy(m_Text,Error,ErrorPosition))
		{
			Valid=FALSE;
			MessageBox(Error,"Error                        ",MB_ICONSTOP);
        }
		else
		{
           Production Temp;
		   Temp.Set(m_Text);
		   if(Temp.Linearity()==NOT_DETERMINED)
				   {
				   Valid=FALSE;
				   MessageBox("This production is not linear.        ","Error",MB_ICONSTOP);
				   }
		   else
		   if(Linearity!=NOT_DETERMINED)
		   {		   
               if(Temp.Linearity()!=Linearity&&Temp.Linearity()!=LAMBDA_ENDED)
			   {
				   Valid=FALSE;
				   MessageBox("Linearity of production does not mach with grammar's        ","Error",MB_ICONSTOP);
               }//if t
		   }//if l
		   else 
			   if(Temp.Linearity()==RIGHT_LINEAR)
				   MessageBox("Grammar will be right linear because of recent production","Linearity of grammar",MB_ICONINFORMATION);
           else 
			   if(Temp.Linearity()==LEFT_LINEAR)
				   MessageBox("Grammar will be left linear because of recent production","Linearity of grammar",MB_ICONINFORMATION);


		}//if c
	}//if v
	if(Valid)
	  OnOK();
}

void CPDlg::SetVNumber(int n)
{
  m_VNumber=n;
}

void CPDlg::SetTNumber(int n)
{
  m_TNumber=n;
}

void CPDlg::SetTerminals(int i, char c)
{
  m_Terminals[i]=c;
}

void CPDlg::SetVariables(int n, char c)
{
  m_Variables[n]=c;
}

void CPDlg::SetLinearity(int n)
{
  Linearity=n;
}

BOOL CPDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CenterWindow(GetParent());	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
