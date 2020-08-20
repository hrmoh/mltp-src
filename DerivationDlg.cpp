// DerivationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "DerivationDlg.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDerivationDlg dialog


CDerivationDlg::CDerivationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDerivationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDerivationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDerivationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDerivationDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDerivationDlg, CDialog)
	//{{AFX_MSG_MAP(CDerivationDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDerivationDlg message handlers

void CDerivationDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here

	CBrush Brush(RGB(0,0,0));
	CRect IDrawRect;
	IDrawRect.top=0;
	IDrawRect.left=0;
    IDrawRect.bottom=600;
    IDrawRect.right=800;
 
	dc.SelectObject(&Brush);
	dc.Rectangle(IDrawRect);

	CPen Pen(PS_SOLID,3,RGB(255,255,255));
	dc.SelectObject(&Pen);
    dc.SetTextColor(RGB(255,255,255));
	dc.SetBkColor(RGB(0,0,0));
	int	varposition=400;
    for(int i=0;i<=m_Number[index];i++)
		ShowProduction(varposition,i,&dc);
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CDerivationDlg::ShowProduction(int& varposition,int i, CPaintDC *pdc)
{
    CString Str=m_Derivations[index][i][0];
    pdc->SetTextColor(RGB(255,255,255));
	CMLTPDlg* Father=(CMLTPDlg*)GetParent();
	if(Father->Current.Linearity==LEFT_LINEAR
		||
       Father->Current.Linearity==NOT_DETERMINED)
    pdc->TextOut(varposition-6,50+i*50-25,Str);
	else
    pdc->TextOut(varposition+6,50+i*50-25,Str);
	int x1=varposition;
	int y1=50+i*50;
	int Width=(m_Derivations[index][i].GetLength()-3)*40;
	varposition=varposition-Width/2;
	for(int j=3;j<m_Derivations[index][i].GetLength();j++)
	{
     Str=m_Derivations[index][i][j];
	 pdc->MoveTo(x1,y1-3);
	 if(isupper(m_Derivations[index][i][j]))
		 pdc->SetTextColor(RGB(255,255,255));
	 else
		 pdc->SetTextColor(RGB(255,0,0));
	 if(m_Derivations[index][i].GetLength()-4)
	 {
	 pdc->LineTo(varposition+(j-3)*Width/(m_Derivations[index][i].GetLength()-4),50+(i+1)*50-5);
	 if((j==3||j==m_Derivations[index][i].GetLength()-1)&&isupper(m_Derivations[index][i][j]))
     if(j==3)
     pdc->TextOut(varposition+(j-3)*Width/(m_Derivations[index][i].GetLength()-4)-6,
	             50+(i+1)*50-25,
	             Str);
	 else
     pdc->TextOut(varposition+(j-3)*Width/(m_Derivations[index][i].GetLength()-4)+6,
	             50+(i+1)*50-25,
	             Str);

	 else
     pdc->TextOut(varposition+(j-3)*Width/(m_Derivations[index][i].GetLength()-4),50+(i+1)*50,Str);
	 }
	 else
	 {
	 pdc->LineTo(varposition,50+(i+1)*50-5);
     pdc->TextOut(varposition,50+(i+1)*50,Str);
	 }
	}

	if(isupper(m_Derivations[index][i][m_Derivations[index][i].GetLength()-1]))
		 varposition=varposition+Width;

}
