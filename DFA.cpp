// DFA.cpp: implementation of the DFA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "DFA.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "MLTPDlg.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void DFA::DIST(int i,int j,int D[30][30],Set S[30][30])
{
   D[i][j]=1;
   for(int k=0;k<S[i][j].Number;k++)
	   DIST(S[i][j].Members[k].m,S[i][j].Members[k].n,D,S);
}


class DPoint:public CObject
{
public:
	int x;
	int y;
    char Labels[100];
	int LNumber;
	int Color[100];
};

DFA::DFA()
{
 SNumber=0;
 FNumber=0;
 ZNumber=0;
 first=0;
 second=0;
}

DFA::~DFA()
{

}


CString DFA::GenerateNewName()
{
  char fchar=char(first+'0');
  char schar=' ';
  if(second)
	  schar=char(second+'0');
  CString NewName="q";
  if(second)
  	  NewName=NewName+schar;
  NewName=NewName+fchar;
  if(first==9)
  {
	  first=0;
	  second++;
  }
  else
	  first++;
  return NewName;	  
}

void DFA::Show(CDDFAFrame *Frame)
{
	DPoint LP[100];
	int PN=0;

	CPaintDC dc(Frame);
	CBrush Brush(RGB(125,125,255));
	dc.SetBkColor(RGB(125,125,255));
	CBrush RedBrush(RGB(255,0,0));
	CBrush YellowBrush(RGB(255,255,0));
	CBrush GreenBrush(RGB(0,255,0));
	CPen WhitePen(PS_SOLID,1,RGB(255,255,255));
	CPen Pen(PS_SOLID,1,RGB(0,0,0));
	CPen BPen(PS_SOLID,3,RGB(0,0,0));
	CPen RPen(PS_SOLID,2,RGB(255,0,0));
    
	CRect IRect;
	Frame->GetClientRect(IRect);
	IRect.NormalizeRect();
	int IiHeight=IRect.Height();
	int IiWidth=IRect.Width();
	CRect IDrawRect;
	IDrawRect.top=IRect.top;
	IDrawRect.left=IRect.left;
    IDrawRect.bottom=IRect.top+IiHeight;
    IDrawRect.right=IRect.left+IiWidth;

    
	dc.SelectObject(&Brush);
	dc.Rectangle(IDrawRect);
	for(int i=0;i<SNumber;i++)
	{
	   int Sign=-1;
	   if(i>SNumber/2)
		   Sign=1;
		Q[i].xPos=420+Sign*int(abs(SNumber/2-i))*70;
		Q[i].yPos=130;
	}
    int Color=0;
	for(i=0;i<SNumber;i++)
		for(int j=0;j<SNumber;j++)
			for(int k=0;k<ZNumber;k++)
			   if(ifDelta(Q[i].Name,Zigma[k],Q[j].Name))
			   {
				   if(i!=j)
				   {
                       if(i<j)
					   {
	                   dc.SelectObject(&BPen);
	                   BPen.CreatePen(PS_SOLID,3,RGB(Color,Color+20,Color+10));
					   Color=Color+50;
					   dc.MoveTo(Q[i].xPos,Q[i].yPos);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2,Q[i].yPos-50);
					   dc.LineTo(Q[j].xPos,Q[j].yPos);
                       
					   //dc.TextOut((Q[i].xPos+Q[j].xPos)/2-3,Q[i].yPos-50-25,Zigma[k]);
					   int index=-1;
					   for(int l=0;l<PN;l++)
						   for(int m=0;m<LP[l].LNumber;m++)
							   if(LP[l].x==(Q[i].xPos+Q[j].xPos)/2-3&&LP[l].y==Q[i].yPos-50-25)
								   index=l;
                        if(index==-1)
						{
							LP[PN].x=(Q[i].xPos+Q[j].xPos)/2-3;
							LP[PN].y=Q[i].yPos-50-25;
							LP[PN].LNumber=1;
							LP[PN].Color[0]=Color-50;
							LP[PN++].Labels[0]=Zigma[k];
						}
						else
						{
							LP[index].Color[LP[index].LNumber]=Color-20;
						    LP[index].Labels[LP[index].LNumber++]=Zigma[k];
						}

					   dc.SelectObject(&RPen);
                       dc.MoveTo((Q[i].xPos+Q[j].xPos)/2-5,Q[i].yPos-50-5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2+5,Q[i].yPos-50-5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2+3,Q[i].yPos-55-5);
                       dc.MoveTo((Q[i].xPos+Q[j].xPos)/2+5,Q[i].yPos-50-5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2+3,Q[i].yPos-45-5);
					   }
					   else
					   {
	                   BPen.CreatePen(PS_SOLID,3,RGB(Color,Color+20,Color+10));
					   Color=Color+50;
					   dc.SelectObject(&BPen);
					   dc.MoveTo(Q[i].xPos,Q[i].yPos);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2,Q[i].yPos+50);
					   dc.LineTo(Q[j].xPos,Q[j].yPos);

					   //dc.TextOut((Q[i].xPos+Q[j].xPos)/2-3,Q[i].yPos+50+25,Zigma[k]);
					   int index=-1;
					   for(int l=0;l<PN;l++)
						   for(int m=0;m<LP[l].LNumber;m++)
							   if(LP[l].x==(Q[i].xPos+Q[j].xPos)/2-3&&LP[l].y==Q[i].yPos+50+25)
								   index=l;
                        if(index==-1)
						{
							LP[PN].x=(Q[i].xPos+Q[j].xPos)/2+3;
							LP[PN].y=Q[i].yPos+50+5;
							LP[PN].LNumber=1;
							LP[PN].Color[0]=Color-50;
							LP[PN++].Labels[0]=Zigma[k];
						}
						else
						{
							LP[index].Color[LP[index].LNumber]=Color-20;
						    LP[index].Labels[LP[index].LNumber++]=Zigma[k];
						}
                       
					   dc.SelectObject(&RPen);
                       dc.MoveTo((Q[i].xPos+Q[j].xPos)/2+5,Q[i].yPos+50+5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2-5,Q[i].yPos+50+5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2-3,Q[i].yPos+55+5);
                       dc.MoveTo((Q[i].xPos+Q[j].xPos)/2-5,Q[i].yPos+50+5);
                       dc.LineTo((Q[i].xPos+Q[j].xPos)/2-3,Q[i].yPos+45+5);
					   }
				   }
				   else
				   {
					   CPen Red3Pen(PS_SOLID,3,RGB(255,0,0));

					   dc.SelectObject(&Red3Pen);
					   dc.MoveTo(Q[i].xPos,Q[i].yPos);
					   dc.LineTo(Q[i].xPos-10,Q[i].yPos-20);
					   dc.LineTo(Q[i].xPos,Q[i].yPos-30);
					   dc.LineTo(Q[i].xPos+10,Q[i].yPos-20);
					   dc.LineTo(Q[i].xPos,Q[i].yPos);

					   int index=-1;
					   for(int l=0;l<PN;l++)
						   for(int m=0;m<LP[l].LNumber;m++)
							   if(LP[l].x==Q[i].xPos-3&&LP[l].y==Q[i].yPos-30-17)
								   index=l;
                        if(index==-1)
						{
							LP[PN].x=Q[i].xPos-3;
							LP[PN].y=Q[i].yPos-30-17;
							LP[PN].LNumber=1;
							LP[PN].Color[0]=-1;
							LP[PN++].Labels[0]=Zigma[k];
						}
						else
						{
							LP[index].Color[LP[index].LNumber]=-1;
						    LP[index].Labels[LP[index].LNumber++]=Zigma[k];
						}

				   }

			   }
			   for(i=0;i<PN;i++)
			   {
				   CString TStr;
				   char c[2];
				   c[0]=LP[i].Labels[0];
				   c[1]='\0';
				   TStr=c;
				   for(int j=1;j<LP[i].LNumber;j++)
				   {
				     TStr=TStr+",";
					 c[0]=LP[i].Labels[j];
					 TStr=TStr+c;
				   }
				   CSize Size=dc.GetTextExtent(TStr);
				   CSize ChSize=dc.GetTextExtent("a");
				   for(j=0;j<LP[i].LNumber;j++)
				   {
                   dc.SetTextColor(RGB(LP[i].Color[j],LP[i].Color[j]+20,LP[i].Color[j]+10));
                   dc.TextOut(LP[i].x-Size.cx/2+j*int(1.5*ChSize.cx),LP[i].y,LP[i].Labels[j]);
				   if(LP[i].LNumber>1&&j!=LP[i].LNumber-1)
				   {
                   dc.SetTextColor(RGB(0,0,0));
                   dc.TextOut(LP[i].x-Size.cx/2+j*int(1.5*ChSize.cx)+ChSize.cx,LP[i].y,",");
				   }
				   //dc.TextOut(LP[i].x-Size.cx/2,LP[i].y,TStr);
				   }
                   dc.SetTextColor(RGB(0,0,0));
			   }

/*    
    dc.SelectObject(&Brush);
	for(i=0;i<SNumber;i++)
		for(int j=0;j<SNumber;j++)
			for(int k=0;k<ZNumber;k++)
			   if(ifDelta(Q[i].Name,Zigma[k],Q[j].Name))
			   {
				   if(i!=j)
				   {
	                   dc.SelectObject(&BPen);
					   dc.Ellipse(Q[i].xPos,Q[i].yPos-50,
						   Q[j].xPos,Q[j].yPos+50);
                       if(i<j)
					   {
					   dc.SelectObject(&WhitePen);
					   dc.Rectangle(Q[i].xPos,Q[i].yPos,
						   Q[j].xPos,Q[j].yPos+55);
					   dc.SelectObject(&RPen);
					   dc.MoveTo((Q[i].xPos+Q[j].xPos)/2+2,Q[i].yPos-50);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2-5,Q[i].yPos-54);
					   dc.MoveTo((Q[i].xPos+Q[j].xPos)/2+2,Q[i].yPos-50);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2-5,Q[i].yPos-44);
					   }
					   else
					   {
					   dc.SelectObject(&WhitePen);
					   dc.Rectangle(Q[i].xPos,Q[i].yPos-55,
						   Q[j].xPos,Q[j].yPos);
					   dc.SelectObject(&RPen);
					   dc.MoveTo((Q[i].xPos+Q[j].xPos)/2-2,Q[i].yPos+50);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2+5,Q[i].yPos+54);
					   dc.MoveTo((Q[i].xPos+Q[j].xPos)/2-2,Q[i].yPos+50);
					   dc.LineTo((Q[i].xPos+Q[j].xPos)/2+5,Q[i].yPos+44);
					   }

				   }
			   }
*/
    for(i=0;i<SNumber;i++)
	{
	   if(Q[i].isFinal)
	   {
		   dc.SelectObject(&YellowBrush);
	       dc.Ellipse(
			Q[i].xPos-15,
			Q[i].yPos-15,
			Q[i].xPos+15,
			Q[i].yPos+15
			   );
			dc.SelectObject(&Pen);
			dc.Ellipse(
				Q[i].xPos-15,
				Q[i].yPos-15,
				Q[i].xPos+15,
				Q[i].yPos+15
			   );

	   }
	   dc.SelectObject(&RedBrush);
	   dc.SetBkColor(RGB(255,0,0));
			if(Q[i].Name==Start)
			{
				dc.SelectObject(&GreenBrush);
	            dc.SetBkColor(RGB(0,255,0));
			}
	   CSize Size;
	   Size=dc.GetTextExtent(Q[i].Name);
	   dc.Ellipse(
		   Q[i].xPos-10-Size.cx/2,
		   Q[i].yPos-10,
		   Q[i].xPos+10+-Size.cx/2,
		   Q[i].yPos+10
		   );
	   dc.SelectObject(&Pen);
	   dc.Ellipse(
		   Q[i].xPos-10-Size.cx/2,
		   Q[i].yPos-10,
		   Q[i].xPos+10+Size.cx/2,
		   Q[i].yPos+10
		   );
/*
	   dc.Ellipse(
		   Q[i].xPos-10,
		   Q[i].yPos-10,
		   Q[i].xPos+10,
		   Q[i].yPos+10
		   );
	   dc.SelectObject(&Pen);
	   dc.Ellipse(
		   Q[i].xPos-10,
		   Q[i].yPos-10,
		   Q[i].xPos+10,
		   Q[i].yPos+10
		   );
*/
	   dc.TextOut(Q[i].xPos-6,Q[i].yPos-8,Q[i].Name);
    }

}

BOOL DFA::ifDelta(CString m_PState, char m_input, CString m_FState)
{
 if(Delta.ifExists(m_PState,m_input,m_FState))
	 return TRUE;
 return FALSE;
}

BOOL DFA::Accepts(CString Str)
{
 if(Str=="@")
	 return Q[0].isFinal;
 int StateIndex=0;
 for(int i=0;i<Str.GetLength();i++)
 {
	 StateIndex=Next(StateIndex,Str[i]);
	 if(StateIndex==-1)
		 return FALSE;
 }
 if(!Q[StateIndex].isFinal)
	 return FALSE;
 return TRUE;
}

int DFA::Next(int index, char input)
{
 for(int i=0;i<SNumber;i++)
	 if(Delta.ifExists(Q[index].Name,input,Q[i].Name))
		 return i;
 return -1;
}
void DFA::Minimize()
{
   int D[30][30];
   Set S[30][30];

   for(int j=0;j<SNumber;j++)
	   for(int i=0;i<SNumber;i++)
	   {
		   D[i][j]=0;
		   S[i][j].Number=0;
	   }
   for(j=0;j<SNumber;j++)
	   for(int i=0;i<SNumber;i++)
	      if((Q[i].isFinal&&!Q[j].isFinal)||(!Q[i].isFinal&&Q[j].isFinal))
			  D[i][j]=1;

   for(j=0;j<SNumber;j++)
	   for(int i=0;i<SNumber;i++)
         if(D[i][j]==0&&i!=j)
		 {
          BOOL shouldbemerged=TRUE;
		  for(int k=0;k<ZNumber;k++)
		  {
			  if(
				  D[
				    Next(i,Zigma[k])
					]
					[
					Next(j,Zigma[k])
					]==1
					||
				  D[
				    Next(j,Zigma[k])
					]
					[
					Next(i,Zigma[k])
					]==1
					)
                  DIST(i,j,D,S);
			    else
				{
					int m=Next(i,Zigma[k]);
					int n=Next(j,Zigma[k]);
					if(i!=n||j!=m)
						shouldbemerged=FALSE;
					if(shouldbemerged)
           		  	    Merge(i,j);
			        if(i>=(SNumber-1)||j>=i)
				            return;
                    if(m<n&&(i!=m&&j!=n))
					{
						S[m][n].Members[S[m][n].Number].m=i;
						S[m][n].Members[S[m][n].Number].n=j;
                        ++S[m][n].Number;
					}
					else
						if(m>n&&(i!=n&&j!=m))
						{
						S[n][m].Members[S[n][m].Number].m=i;
						S[n][m].Members[S[n][m].Number].n=j;
                        ++S[n][m].Number;
						}
                  
				}
				
				}
          for(int i=0;i<SNumber;i++)
			  for(int j=0;j<SNumber;j++)
			  {
				  if(i!=j&&D[i][j]==0)
           		  	 Merge(i,j);
			 if(i>=(SNumber-1)||j>=i)
				 return;
			  }
		  }
/*
   int merged[100];
   int k=0;
   int i=0;
   j=0;
   while(i<SNumber)
   {
     while(j<SNumber)
	 {
       for(int l=0;l<k;l++)
		   if(merged[l]==i||merged[l]==j)
			   break;
       if(l==k)
		 if(D[i][j]==0)
		 {
			 Merge(i,j);
			 merged[k++]=i;
			 merged[k++]=j;
		 }
		 j++;
	 }
	 i++;
   }
*/   
}


void DFA::Merge(int m, int n)
{
   Q[SNumber].Name=Q[m].Name+"+";
   Q[SNumber].Name=Q[SNumber].Name+Q[n].Name;
   if(Q[m].isFinal)
	   Q[SNumber].isFinal=TRUE;
   else
	   Q[SNumber].isFinal=FALSE;
   SNumber++;
   for(int i=0;i<SNumber-1;i++)
	   for(int j=0;j<ZNumber;j++)
	   {
	      if(ifDelta(Q[i].Name,Zigma[j],Q[m].Name))
		  {
			  CString s[2];
              s[0]=Q[SNumber-1].Name;
			  if(i!=m&&i!=n)
			  {
				  Delta.DeleteTF(Q[i].Name,Zigma[j],Q[m].Name);
				  Delta.AddTF(Q[i].Name,Zigma[j],1,s);
			  }
			  else
			  {
				  Delta.DeleteTF(Q[i].Name,Zigma[j],Q[m].Name);
				  Delta.AddTF(s[0],Zigma[j],1,s);
			  }
			      
		  }
	      if(ifDelta(Q[i].Name,Zigma[j],Q[n].Name))
		  {
			  CString s[2];
              s[0]=Q[SNumber-1].Name;
			  if(i!=m&&i!=n)
			  {
				  Delta.DeleteTF(Q[i].Name,Zigma[j],Q[n].Name);
				  Delta.AddTF(Q[i].Name,Zigma[j],1,s);
			  }
			  else
			  {
				  Delta.DeleteTF(Q[i].Name,Zigma[j],Q[n].Name);
				  Delta.AddTF(s[0],Zigma[j],1,s);
			  }
			      
		  }
	   }
   for(i=0;i<SNumber-1;i++)
	   for(int j=0;j<ZNumber;j++)
	   {
	      if(ifDelta(Q[m].Name,Zigma[j],Q[i].Name))
		  {
			  CString s[2];
              s[0]=Q[i].Name;
			  if(i!=m&&i!=n)
			  {
				  Delta.DeleteTF(Q[m].Name,Zigma[j],Q[i].Name);
				  Delta.AddTF(Q[SNumber-1].Name,Zigma[j],1,s);
			  }
			  else
			  {
				  Delta.DeleteTF(Q[m].Name,Zigma[j],Q[i].Name);
				  Delta.AddTF(s[0],Zigma[j],1,s);
			  }
			      
		  }
	      if(ifDelta(Q[n].Name,Zigma[j],Q[i].Name))
		  {
			  CString s[2];
              s[0]=Q[i].Name;
			  if(i!=m&&i!=n)
			  {
				  Delta.DeleteTF(Q[n].Name,Zigma[j],Q[i].Name);
				  Delta.AddTF(Q[SNumber-1].Name,Zigma[j],1,s);
			  }
			  else
			  {
				  Delta.DeleteTF(Q[n].Name,Zigma[j],Q[i].Name);
				  Delta.AddTF(s[0],Zigma[j],1,s);
			  }
			      
		  }
	   }
    DeleteState(m);
	DeleteState(n); 
}

void DFA::DeleteState(int index)
{
  for(int i=index;i<SNumber-1;i++)
  {
	  Q[i].Name=Q[i+1].Name;
	  Q[i].isFinal=Q[i+1].isFinal;
  }
  for(i=0;i<SNumber-1;i++)
	  for(int j=0;j<SNumber-1;j++)
	  {
             if(i>=index)
			 {
				 if(ifDelta(Q[i].Name,ZNumber,Q[j].Name)&&Delta.NotSigned(Q[i].Name,ZNumber,Q[j].Name))
				 {
					 if(j>=index)
					 {
						 Delta.DeleteTF(Q[i].Name,ZNumber,Q[j].Name);
						 CString s[2];
						 s[0]=Q[j-1].Name;
						 Delta.AddTF(Q[i-1].Name,ZNumber,1,s);
						 Delta.Signify(Q[i-1].Name,ZNumber,1,s);
					 }
					 else
					 {
						 Delta.DeleteTF(Q[i].Name,ZNumber,Q[j].Name);
						 CString s[2];
						 s[0]=Q[j].Name;
						 Delta.AddTF(Q[i-1].Name,ZNumber,1,s);
						 Delta.Signify(Q[i-1].Name,ZNumber,1,s);
					 }
				 }
			 }
			 else
             if(j>=index)
			 {
				 if(ifDelta(Q[j].Name,ZNumber,Q[i].Name)&&Delta.NotSigned(Q[j].Name,ZNumber,Q[i].Name))
				 {
					 if(i>=index)
					 {
						 Delta.DeleteTF(Q[j].Name,ZNumber,Q[i].Name);
						 CString s[2];
						 s[0]=Q[i-1].Name;
						 Delta.AddTF(Q[j-1].Name,ZNumber,1,s);
						 Delta.Signify(Q[j-1].Name,ZNumber,1,s);
					 }
					 else
					 {
						 Delta.DeleteTF(Q[j].Name,ZNumber,Q[i].Name);
						 CString s[2];
						 s[0]=Q[i].Name;
						 Delta.AddTF(Q[j-1].Name,ZNumber,1,s);
						 Delta.Signify(Q[j-1].Name,ZNumber,1,s);
					 }
				 }
			 }

	  }
    SNumber--;
  

}
