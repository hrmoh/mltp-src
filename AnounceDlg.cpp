// AnounceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MLTP.h"
#include "AnounceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "MLTPDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CAnounceDlg dialog


CAnounceDlg::CAnounceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnounceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnounceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAnounceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnounceDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAnounceDlg, CDialog)
	//{{AFX_MSG_MAP(CAnounceDlg)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnounceDlg message handlers

BOOL CAnounceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetTimer(ID_TIMER,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAnounceDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime curTime=CTime::GetCurrentTime();
	if(curTime.GetSecond()>=1)
       DestroyWindow();
	CDialog::OnTimer(nIDEvent);
}

void CAnounceDlg::ShowBitmap(CPaintDC *pdc, CWnd *pWnd)
{
 CMLTPDlg *lpWnd=(CMLTPDlg*)pWnd;
 BITMAP bm;
 lpWnd->m_bmpBitmap.GetBitmap(&bm);
 CDC dcMem;
 dcMem.CreateCompatibleDC(pdc);
 CBitmap* pOldBitmap=(CBitmap*)dcMem.SelectObject(lpWnd->m_bmpBitmap);
 CRect IRect;
 IRect.NormalizeRect();
 pdc->StretchBlt(0,0,/*IRect.Width()-20*/300,
	 /*IRect.Height()-20*/225,&dcMem,0,0,
	 bm.bmWidth,bm.bmHeight,SRCCOPY);
 /*pdc->BitBlt(0,0,IRect.Width(),
	 IRect.Height(),&dcMem,
	 0,0,SRCCOPY);*/
}

void CAnounceDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CMLTPDlg *pWnd=(CMLTPDlg*)GetParent();
	ShowBitmap(&dc,pWnd);
	// Do not call CDialog::OnPaint() for painting messages
}
