// RegularGrammar.cpp: implementation of the RegularGrammar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "RegularGrammar.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "MLTPDlg.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RegularGrammar::RegularGrammar()
{
	Grammar::Grammar();
	Linearity=NOT_DETERMINED;
}

RegularGrammar::~RegularGrammar()
{

}

BOOL Check(CString PDefinition,CString& Error,int &ErrorPosition);
BOOL RegularGrammar::AddToProductions(CString newProduction,CString& Error,int& ErrorPosition)
{
  Production Temp;
  if(!Check(newProduction,Error,ErrorPosition))
     return FALSE;
  Temp.Set(newProduction);
  if(Linearity==NOT_DETERMINED&&Temp.Linearity()!=LAMBDA_ENDED)
  {
	  if(Temp.Linearity()==NOT_DETERMINED)
	  {
		  Error="Production should be right linear or left linear";
		  return FALSE;
	  }
	  Linearity=Temp.Linearity();
  }
  //LINEARITY?
  if((Temp.Linearity()!=Linearity)&&(Temp.Linearity()!=LAMBDA_ENDED))
  {
	  Error="Linearity of production does not match with linearity of grammar";
      return FALSE;
  }
  Productions[PNumber++].Set(newProduction);
  return TRUE;
}

//DEL RegularGrammar RegularGrammar::operator =(RegularGrammar &Another)
//DEL {
//DEL  TNumber=Another.TNumber;
//DEL  VNumber=Another.VNumber;
//DEL  PNumber=Another.PNumber;
//DEL  Linearity=Another.Linearity;
//DEL  for(int i=0;i<TNumber;i++)
//DEL 	 Terminals[i]=Another.Terminals[i];
//DEL  for(i=0;i<VNumber;i++)
//DEL 	 Variables[i]=Another.Variables[i];
//DEL  CString Error;
//DEL  int ErrorPosition;
//DEL  for(i=0;i<PNumber;i++)
//DEL 	 AddToProductions(Another.GetProduction(i),Error,ErrorPosition);
//DEL  return *this;
//DEL }

RegularGrammar::RegularGrammar(RegularGrammar &Another)
{
 TNumber=Another.TNumber;
 VNumber=Another.VNumber;
 PNumber=Another.PNumber;
 Linearity=Another.Linearity;
 for(int i=0;i<TNumber;i++)
	 Terminals[i]=Another.Terminals[i];
 for(i=0;i<VNumber;i++)
	 Variables[i]=Another.Variables[i];
 CString Error;
 int ErrorPosition;
 for(i=0;i<PNumber;i++)
	 AddToProductions(Another.GetProduction(i),Error,ErrorPosition);
}

int RegularGrammar::NumberOfVariables()
{
  return VNumber;
}

int RegularGrammar::NumberOfTerminals()
{
  return TNumber;
}

int RegularGrammar::GetLinearity()
{
  return Linearity;
}

int RegularGrammar::NumberOfProductions()
{
  return PNumber;
}

void RegularGrammar::Assign(RegularGrammar Another)
{
 TNumber=Another.TNumber;
 VNumber=Another.VNumber;
 PNumber=Another.PNumber;
 Linearity=Another.Linearity;
 for(int i=0;i<TNumber;i++)
	 Terminals[i]=Another.Terminals[i];
 for(i=0;i<VNumber;i++)
	 Variables[i]=Another.Variables[i];
 CString Error;
 int ErrorPosition;
 for(i=0;i<PNumber;i++)
	 AddToProductions(Another.GetProduction(i),Error,ErrorPosition);
  Start=Another.Start;
}

void RegularGrammar::EquivalentNFA(NFA &ENFA)
{
  //Zigma
  if(Linearity==RIGHT_LINEAR||Linearity==NOT_DETERMINED)
  {
  for(int i=0;i<TNumber;i++)
	  ENFA.AddToZigma(Terminals[i]);
  //States
  for(i=0;i<VNumber;i++)
    ENFA.AddToStates(Variables[i]);

  for(i=0;i<PNumber;i++)
  {
	  if(Productions[i].RightPart()[0]=='@')
	  {
		  ENFA.AddToStates(Productions[i].LeftPart());
		  ENFA.SetFinal(Productions[i].LeftPart());
	  }
	  else
	  if(Productions[i].ConstRight())
	  {
		  ENFA.AddToStates("@");
		  ENFA.SetFinal("@");
		  CString FStates[2];
		  if(Productions[i].RightPart().GetLength()==1)
		  {
		  FStates[0]="@";
		  //Transition Function: Delta(A,a)=@ <=> A->a
		  ENFA.AddToTransitionFunction(Productions[i].LeftPart(),
			                           Productions[i].RightPart()[0],
									   1,
									   FStates
									   );
		  }
		  else
		  {
			  CString ProState=Productions[i].LeftPart();
			  for(int j=1;j<Productions[i].RightPart().GetLength();j++)
			  {
				  CString ProStr="";
                  for(int k=j;k<Productions[i].RightPart().GetLength();k++)
					  ProStr=ProStr+Productions[i].RightPart()[k];
				  CString FS[2];
				  FS[0]=ProStr;
		  
				  ENFA.AddToStates(ProStr);
				  ENFA.AddToTransitionFunction(ProState,
					                           Productions[i].RightPart()[j-1],
											   1,
											   FS
											   );
				  ProState=ProStr;
			  }
			     CString FState[2];
			      FState[0]="@";

             	  ENFA.AddToTransitionFunction(ProState,
					                           Productions[i].RightPart()[Productions[i].RightPart().GetLength()-1],
											   1,
											   FState
											   );
				  
		  }
	  }
  }
   //Final States
  /*
   for(i=0;i<PNumber;i++)
	   if(Productions[i].RightPart()=="@")
		   ENFA.SetFinal(Productions[i].LeftPart());
		   */
   //Start State
   ENFA.SetStart(Start);

   //Delta
   for(i=0;i<PNumber;i++)
   {
	   if(!Productions[i].ConstRight())
	   {
/*
	       CString FStates[2];
	       FStates[0]=Productions[i].RightPart()[1];
			   ENFA.AddToTransitionFunction(
			   Productions[i].LeftPart(),
			   Productions[i].RightPart()[0],
			   1,
               FStates 
			   );
*/			   
			  CString ProState=Productions[i].LeftPart();
			  for(int j=1;j<Productions[i].RightPart().GetLength()-1;j++)
			  {
				  CString ProStr="";
                  for(int k=j;k<Productions[i].RightPart().GetLength();k++)
					  ProStr=ProStr+Productions[i].RightPart()[k];
				  CString FS[2];
				  FS[0]=ProStr;
		  
				  ENFA.AddToStates(ProStr);
				  k--;
				  ENFA.AddToTransitionFunction(ProState,
					                           Productions[i].RightPart()[j-1],
											   1,
											   FS
											   );
				  ProState=ProStr;
			  }
   
			     CString FState[2];
			      FState[0]=Productions[i].RightPart()[Productions[i].RightPart().GetLength()-1];

             	  ENFA.AddToTransitionFunction(ProState,
					                           Productions[i].RightPart()[Productions[i].RightPart().GetLength()-2],
											   1,
											   FState
											   );

	   }
   }
   }//if
   
   
}

BOOL RegularGrammar::ifAccepts(CString Str,int& index,int* indexes,char StartV)
{
  for(int i=0;i<PNumber;i++)
  {
	  if(Productions[i].LeftPart()[0]==StartV)
	  {
	  BOOL complete;
	  //TRUE= complete
	  //FALSE= should continue
	  CString tStr=Str;
	  char next;
	  if(Productions[i].Parses(tStr,complete,next))
	  {
		  if(complete)
		  {      
			  indexes[index]=i;
     		  return TRUE;
		  }
		  else
		  {
          int ti=index+1;
		  if(ifAccepts(tStr,ti,indexes,next))
		  {
		      indexes[index]=i;
			  index=ti;
			  return TRUE;
		  }
		  }
	  }
	  }
  }
  return FALSE;
}

int RegularGrammar::LambdaProductionIndex()
{
 for(int i=0;i<PNumber;i++)
	 if(Productions[i].RightPart()=="@")
		 return i;
 return -1;
}
	/*
   for(int i=0;i<PNumber;i++)
   {
	   CString tStr=Str;
	   char c=Productions[i].ifParses(tStr);
	   if(c==1)
	   {   
		   indexes[index]=i;
		   return TRUE;
	   }
	   if(c=='@')
	   {
		   int j=LambdaProductionIndex();
		   if(j!=-1)
		   {
			   indexes[index++]=i;
			   indexes[index]=j;
			   return TRUE;
		   }
	   }
       else
	   if(c!=0)
	   {
		   CMLTPDlg a;
		   CString s=index+'0';
		   a.MessageBox(Str);
		   a.MessageBox(s);
		   s=c;
		   a.MessageBox(s);		   
		   a.MessageBox(Productions[indexes[index]].GetProduction());
		   int ti=index+1;
		   if(ifAccepts(tStr,ti,indexes))
		   {
			   index=ti;   
			   return TRUE;
		   }
	   }
   }
   return FALSE;
   */

BOOL RegularGrammar::ifAccepts(CString Str, int &index, int *indexes)
{
  return ifAccepts(Str,index,indexes,Start);
}

BOOL RegularGrammar::DeleteProduction(CString pDefintion)
{
	{
	CString tStr=pDefintion;
    for(int i=0;i<pDefintion.GetLength();i++)
		if(pDefintion[i]==' ')
			tStr.Delete(i);
    pDefintion=tStr;
	}
	for(int i=0;i<PNumber;i++)
	   if(Productions[i].GetProduction()==pDefintion)
	   {
		   DeleteProduction(i);
		   return TRUE;
	   }
     return FALSE;
}

void RegularGrammar::DeleteProduction(int index)
{
	PNumber--;
    for(int i=index;i<PNumber;i++)
		Productions[i].Set(Productions[i+1].GetProduction());
}

void RegularGrammar::ResetLinearity()
{
   if(Linearity==NOT_DETERMINED)
	   return;
   int indexes[100];
   int j=0;
   for(int i=0;i<PNumber;i++)
	   if(Productions[i].Linearity()==Linearity)
	      indexes[j++]=i;
	   
   for(i=0;i<j;i++)
	   DeleteProduction(indexes[i]);
   Linearity=NOT_DETERMINED;
}
