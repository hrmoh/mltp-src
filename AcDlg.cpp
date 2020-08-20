// AcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "AcDlg.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAcDlg dialog


CAcDlg::CAcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAcDlg)
	DDX_Control(pDX, IDC_PRE, m_Pre);
	DDX_Control(pDX, IDC_NEXT, m_Next);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAcDlg, CDialog)
	//{{AFX_MSG_MAP(CAcDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_EXIT, OnExit)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRE, OnPre)
	ON_BN_CLICKED(IDC_DERIVATION_TREE, OnDerivationTree)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAcDlg message handlers

BOOL CAcDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	i=0;
    return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAcDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

    CBrush BlackBrush(RGB(0,0,0)); 
	dc.SelectObject(&BlackBrush);

	CRect IRect;
	GetClientRect(IRect);
	IRect.NormalizeRect();
	int IiHeight=IRect.Height();
	int IiWidth=IRect.Width();
	CRect IDrawRect;
	IDrawRect.top=IRect.top;
	IDrawRect.left=IRect.left;
    IDrawRect.bottom=IRect.top+IiHeight;
    IDrawRect.right=IRect.left+IiWidth;
	dc.Rectangle(IDrawRect);

	dc.SetBkColor(RGB(0,0,0));
	dc.SetTextColor(RGB(255,255,255));
	CSize Size;
	Size=dc.GetTextExtent(m_Accepted[i]);
	dc.TextOut(110-Size.cx/2,10,m_Accepted[i]);

	// Do not call CDialog::OnPaint() for painting messages
}

void CAcDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
    OnOK();	
}

void CAcDlg::OnNext() 
{
	// TODO: Add your control notification handler code here
	if(i<m_AcceptedNumber-1)
	{
	i++;
	Invalidate();
	}
	else
	{
		MessageBox("No next string exists!","Substrings Accepted",MB_ICONINFORMATION);
	}

}

void CAcDlg::OnPre() 
{
	// TODO: Add your control notification handler code here
	if(i>0)
	{
	i--;
	Invalidate();
	}
	else
	{
		MessageBox("No previous string exists!","Substrings Accepted",MB_ICONINFORMATION);
	}

}

void CAcDlg::OnDerivationTree() 
{
	// TODO: Add your control notification handler code here
    CMLTPDlg* Father=(CMLTPDlg*)GetParent();
	Father->ShowDerivationTree(i);
}
