// PInfo.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "PInfo.h"
#include "RGInfo.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPInfo dialog


CPInfo::CPInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CPInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPInfo)
	DDX_Control(pDX, IDC_PRE, m_pre);
	DDX_Control(pDX, IDC_NEXT, m_Next);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPInfo, CDialog)
	//{{AFX_MSG_MAP(CPInfo)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_POK, OnPok)
	ON_BN_CLICKED(IDC_NEXT, OnNext)
	ON_BN_CLICKED(IDC_PRE, OnPre)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPInfo message handlers

BOOL CPInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_index=0;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPInfo::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CRGInfo* Father;
    Father=(CRGInfo *)GetParent();
//	m_Next.EnableWindow(!(Father->m_Number==m_index+1));
//	m_pre.EnableWindow((m_index!=0));
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
	CSize Size=dc.GetTextExtent(Father->m_List[m_index]);
	dc.TextOut(100-Size.cx/2,10,Father->m_List[m_index]);
	// Do not call CDialog::OnPaint() for painting messages
}

void CPInfo::OnPok() 
{
	// TODO: Add your control notification handler code here
    OnOK();	
}

void CPInfo::OnNext() 
{
	// TODO: Add your control notification handler code here
    CRGInfo *Father=(CRGInfo *)GetParent();
    if(Father->m_Number==m_index+1)
		MessageBox("No next production exists!","Productions",MB_ICONINFORMATION);
	else
	{
	m_index++;
	Invalidate();
	}
	
}

void CPInfo::OnPre() 
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
