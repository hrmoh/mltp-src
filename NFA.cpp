// NFA.cpp: implementation of the NFA class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "NFA.h"
#include "MLTPDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

class Point:public CObject
{
public:
	int x;
	int y;
    char Labels[100];
	int LNumber;
	int Color[100];
};
class StateSet:public CObject
{
public:
CString Name;

int PSNumber;
CString PS[100];

BOOL isEqual(int SN,CString* Strings);
};

BOOL StateSet::isEqual(int SN,CString* Strings)
{
	for(int i=0;i<PSNumber;i++)
	{
	    BOOL Found=FALSE;
		for(int j=0;j<SN;j++)
            if(PS[i]==Strings[j])
				Found=TRUE;
		if(!Found)
				return FALSE;
	}
	
	for(i=0;i<SN;i++)
	{
	    BOOL Found=FALSE;
		for(int j=0;j<PSNumber;j++)
            if(PS[j]==Strings[i])
				Found=TRUE;
		if(!Found)
				return FALSE;
	}
	
	return TRUE;
}
class SSS
{
public:
	CString Find(int Number,CString* Names);
CString FindName(int index,CString* Names);
SSS();
void AddToStates(CString NewName,int PSN,CString* PreStates);
BOOL isInStates(int PSN,CString*PreStates);
void Found(int index,int &Number,CString* States,CString& PreName); 
private:
	int SSNumber;
	StateSet States[100];
};
SSS::SSS()
{
	SSNumber=0;
}
void SSS::AddToStates(CString NewName,int PSN,CString* PreStates)
{
	States[SSNumber].Name=NewName;
	States[SSNumber].PSNumber=PSN;
	for(int i=0;i<PSN;i++)
		States[SSNumber].PS[i]=PreStates[i];
	SSNumber++;
}
BOOL SSS::isInStates(int PSN,CString* PreStates)
{
	if(PSN==0)
		return TRUE;
	for(int i=0;i<SSNumber;i++)
		if(States[i].isEqual(PSN,PreStates))
			return TRUE;
    return FALSE; 

}
CString SSS::FindName(int index, CString *Names)
{
	for(int i=0;i<SSNumber;i++)
		if(States[i].isEqual(index,Names))
			return States[i].Name;

     return "";
}

void SSS::Found(int index,int &Number,CString* PStates,CString& PreName)
{
	Number=States[index].PSNumber;
	for(int i=0;i<Number;i++)
		PStates[i]=States[index].PS[i];
	PreName=States[index].Name;
}
NFA::NFA()
{
 SNumber=0;
 ZNumber=0;
 FNumber=0;
}

NFA::~NFA()
{

}

void NFA::AddToStates(CString AState)
{
 for(int i=0;i<SNumber;i++)
	 if(AState==Q[i].Name)
		 return;

 Q[SNumber++].Name=AState;
}

void NFA::AddToZigma(char alpha)
{
 for(int i=0;i<ZNumber;i++)
	 if(alpha==Zigma[i])
		 return;
  Zigma[ZNumber++]=alpha;
}

BOOL NFA::SetStart(CString AState)
{
 for(int i=0;i<SNumber;i++)
	 if(AState==Q[i].Name )
		 break;
 if(i<SNumber)
 {
	 Start=Q[i].Name;
	 return TRUE;
 }
 return FALSE;
}

BOOL NFA::SetFinal(CString AState)
{
 BOOL Found=FALSE;
 for(int i=0;i<SNumber;i++)
	 if(Q[i].Name==AState)
	 {
		 Q[i].isFinal=TRUE;
		 Found=TRUE;
		 break;
	 }
 if(Found)
 {
	 for(i=0;i<FNumber;i++)
		 if(F[i]==AState)
			 return TRUE;  
      F[FNumber++]=AState;
	  return TRUE;
 }
 return FALSE;
}

BOOL NFA::AddToTransitionFunction(CString PState, char input, int RNumber, CString *FStates)
{
  for(int i=0;i<SNumber;i++)
	  if(Q[i].Name==PState)
		  break;
  if(i==SNumber)
	  return FALSE;
  for(i=0;i<ZNumber;i++)
	  if(input==Zigma[i])
		  break;
   /*
   for(i=0;i<RNumber;i++)
   {
	   for(int j=0;j<FNumber;j++)
		   if(FStates[i]==F[j])
			   break;
       if(j==FNumber)
	   {
      CDFAFrame a;
	  a.MessageBox(FStates[j]);

		   return FALSE;
	   }
   }
   */
   Delta.AddTF(PState,input,RNumber,FStates);

  
   return TRUE;
}
void NFA::EquivalentDFA(DFA &EDFA)
{

	SSS FoundStates;
	int FSNumber=1;//FoundStatesNumber

    //constructing Zigma for DFA
    EDFA.ZNumber=ZNumber;
    for(int i=0;i<ZNumber;i++)
		EDFA.Zigma[i]=Zigma[i];

	//construcing Start State of DFA
	EDFA.SNumber=1;
	EDFA.Q[0].Name=EDFA.GenerateNewName();

	EDFA.Start=EDFA.Q[0].Name;
	if(isFinal(Start))
		EDFA.Q[0].isFinal=TRUE;

	//adding it to found states:
	CString PreStates[100];
	PreStates[0]=Start;
    FoundStates.AddToStates(EDFA.Q[0].Name,1,PreStates);

	//finding another DFA States
	BOOL done=FALSE;
	do{//do
       for(int i=0;i<FSNumber;i++)
	   {//for i
		  CString NowState[100];
		  int Number;
		  CString PreName;
		  CString s[2];
		  for(int j=0;j<ZNumber;j++)
		  {//for j
		  FoundStates.Found(i,Number,NowState,PreName);
		  BOOL isF=NextStates(Zigma[j],Number,NowState);   
		  if(!FoundStates.isInStates(Number,NowState))
		  {//if
			  EDFA.Q[EDFA.SNumber].Name=EDFA.GenerateNewName();
			  EDFA.Q[EDFA.SNumber].isFinal=isF;
			  if(isF)
				  EDFA.F[FNumber++]=EDFA.Q[EDFA.SNumber].Name;
			  FoundStates.AddToStates(EDFA.Q[EDFA.SNumber].Name,
				                      Number,
									  NowState);
			  s[0]=EDFA.Q[EDFA.SNumber].Name;
			  EDFA.SNumber++;
			  EDFA.Delta.AddTF(PreName,
				               Zigma[j],
							   1,
							   s
                               );
			  done=TRUE;
		  }//if
		  /*
		  else
		  {//else
		  FoundStates.Found(i,Number,NowState,PreName);
			  if(
				  isNextEqualToItself(Zigma[j],Number,NowState)
				  &&
				  (!EDFA.Delta.ifExists(PreName,Zigma[j],PreName))
				  )
			  {//if
			  s[0]=PreName;
			  EDFA.Delta.AddTF(PreName,
				               Zigma[j],
							   1,
							   s
                               );
			  //done=TRUE;
  			  }//if

			  else //else2
                  if(!EDFA.Delta.ifExists(PreName,Zigma[j],FoundStates.FindName(Number,NowState)))
				  {
					  s[0]=FoundStates.FindName(Number,NowState);
			          EDFA.Delta.AddTF(PreName,
				               Zigma[j],
							   1,
							   s
                               );

				      //done=TRUE;
				  }
			  //else2
		  
		  }//else
          */  
		  if(done)
			  break;
		  }//for j
		  if(done)
			  break;
	   }//for i

	   if(done)
		   FSNumber++;
	   done=!done;
	}while(!done);//do
	for(i=0;i<EDFA.SNumber;i++)
	{
		for(int j=0;j<ZNumber;j++)
		{
          CString PreName;
          CString PostName;
		  int Number;
		  CString NowState[100];
		  FoundStates.Found(i,Number,NowState,PreName);
		  NextStates(Zigma[j],Number,NowState);
		  if(Number!=0)
		  {
		  PostName=FoundStates.Find(Number,NowState);
		  if(PostName!="none")
		  {
           CString s[2];
		   s[0]=PostName;
           EDFA.Delta.AddTF(PreName,
			                Zigma[j],
							1,
							s
							);
		  }
		  }
		}
	}
}

void NFA::Show(CDFAFrame *Frame)
{
	Point LP[100];
	int PN=0;

	CPaintDC dc(Frame);

	CBrush Brush(RGB(0,125,255));

	dc.SetBkColor(RGB(0,125,255));

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
                   if(LP[i].Color[j]!=-1)
                     dc.SetTextColor(RGB(LP[i].Color[j],LP[i].Color[j]+20,LP[i].Color[j]+10));
				   else
                     dc.SetTextColor(RGB(0,0,0));
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
	   if(isFinal(Q[i].Name))
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
			if(isStart(Q[i].Name))
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

BOOL NFA::ifDelta(CString m_PState, char m_input, CString m_FState)
{
 if(Delta.ifExists(m_PState,m_input,m_FState))
	 return TRUE;
 return FALSE;
}

BOOL NFA::isFinal(CString StateName)
{
for(int i=0;i<FNumber;i++)
    if(F[i]==StateName)
		return TRUE;
return FALSE; 

}

BOOL NFA::isStart(CString SName)
{
  if(SName==Start)
	  return TRUE;
  return FALSE;
}

BOOL NFA::NextStates(char input, int &Number, CString *StatesNames)
{ 
	int NNumber=0;
	CString NSN[100];
	BOOL isF=FALSE;
    
	for(int i=0;i<Number;i++)
	for(int j=0;j<SNumber;j++)
		if(ifDelta(StatesNames[i],input,Q[j].Name))
		{
			NSN[NNumber++]=Q[j].Name;
			if(Q[j].isFinal)
				isF=TRUE;
		}
    Number=NNumber;
	for(i=0;i<Number;i++)
		StatesNames[i]=NSN[i];
    return isF;		
}

BOOL NFA::isNextEqualToItself(char input, int Number, CString *NowStates)
{
	int NNumber=0;
	CString NSN[100];
    
	for(int i=0;i<Number;i++)
      for(int j=0;j<SNumber;j++)
		if(ifDelta(NowStates[i],input,Q[j].Name))
			NSN[NNumber++]=Q[j].Name;

     for(i=0;i<Number;i++)
	 {
		 BOOL Found=FALSE;
		 for(int j=0;j<NNumber;j++)
			 if(NowStates[i]==NSN[j])
			 {
				 Found=TRUE;
				 break;
			 }
		  if(!Found)
			  return FALSE;
	 }
	 for(int j=0;j<NNumber;j++)
	 {
		 BOOL Found=FALSE;
          for(int i=0;i<Number;i++)
			 if(NowStates[i]==NSN[j])
			 {
				 Found=TRUE;
				 break;
			 }
		  if(!Found)
			  return FALSE;
	 }
	 return TRUE;
}


CString SSS::Find(int Number, CString *Names)
{
	for(int i=0;i<SSNumber;i++)
		if(States[i].isEqual(Number,Names))
			return States[i].Name;
     return "none";
}

void NFA::Reverse()
{
	FNumber=0;
    for(int i=0;i<SNumber;i++)
	{
		if(Q[i].isFinal)
			Q[i].isFinal=FALSE;
		else
		{
		    Q[i].isFinal=TRUE;
			F[FNumber++]=Q[i].Name;
		}
	}

}
