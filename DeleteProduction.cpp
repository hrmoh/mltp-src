// DeleteProduction.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "DeleteProduction.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteProduction dialog


CDeleteProduction::CDeleteProduction(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteProduction::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteProduction)
	//}}AFX_DATA_INIT
}


void CDeleteProduction::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteProduction)
	DDX_Control(pDX, IDC_PRE, m_Pre);
	DDX_Control(pDX, IDC_NEXT, m_Next);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteProduction, CDialog)
	//{{AFX_MSG_MAP(CDeleteProduction)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_PRE, OnPre)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_DCANCEL, OnDcancel)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteProduction message handlers

BOOL CDeleteProduction::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_index=0;	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeleteProduction::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CEditDlg* Father;
    Father=(CEditDlg *)GetParent();
	CBrush BlackBrush(RGB(0,0,0)); 
    CBrush WhiteBrush(RGB(255,255,255));
	dc.SelectObject(&BlackBrush);
    dc.SetBkColor(RGB(0,0,0));
	dc.SetTextColor(RGB(255,255,255));
	CRect IRect;
	GetClientRect(IRect);
	IRect.NormalizeRect();
	int IiHeight=IRect.Height();
	int IiWidth=IRect.Width();
	CRect IDrawRect;
	IDrawRect.top=IRect.top;
	IDrawRect.left=IRect.left-40;
    IDrawRect.bottom=IRect.top+IiHeight;
    IDrawRect.right=IRect.left+IiWidth-40;
	dc.Rectangle(IDrawRect);
	CSize Size=dc.GetTextExtent(Father->EditingGrammar.GetProduction(m_index));
	dc.TextOut(100-Size.cx/2,10,Father->EditingGrammar.GetProduction(m_index));

	
	// Do not call CDialog::OnPaint() for painting messages
}

void CDeleteProduction::OnPre() 
{
	// TODO: Add your control notification handler code here
	if(!m_index)
		MessageBox("No previous production exists!","Productions",MB_ICONINFORMATION);
	else
	{
    m_index--;
	Invalidate();
	}
}

void CDeleteProduction::OnNext() 
{
	// TODO: Add your control notification handler code here
	CEditDlg* Father=(CEditDlg *)GetParent();
    if(Father->EditingGrammar.PNumber==m_index+1)
		MessageBox("No next production exists!","Productions",MB_ICONINFORMATION);
	else
	{
    m_index++;
	Invalidate();
	}
}

void CDeleteProduction::OnDcancel() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDeleteProduction::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CEditDlg* parent=(CEditDlg*)GetParent();
	parent->EditingGrammar.DeleteProduction(parent->EditingGrammar.GetProduction(m_index));
    OnOK();	
}
