// Grammar.cpp: implementation of the Grammar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "Grammar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Grammar::Grammar()
{
  VNumber=0; 
  TNumber=0;
  PNumber=0;
  Start='@';
}

Grammar::~Grammar()
{

}

BOOL Grammar::AddToVariables(char nVariable)
{
  if(isupper(nVariable))
  {
	  BOOL Found=FALSE;
	  for(int i=0;i<VNumber;i++)
		  if(nVariable==Variables[i])
		  {
			  Found=TRUE;;
			  break;
		  }
      if(!Found)
          Variables[VNumber++]=nVariable;
	  return TRUE;
  }
  return FALSE;
}

BOOL Grammar::SetAsStart(char AVariable)
{
  BOOL Found=FALSE;
  for(int i=0;i<VNumber;i++)
	  if(AVariable==Variables[i])
	  {
		  Found=TRUE;
		  break;
	  }
  if(Found)
  {
	  Start=AVariable;
	  return TRUE;
  }
  return FALSE;
}

BOOL Grammar::AddToTerminals(char ATerminal)
{
	if(islower(ATerminal))
	{
		//check for repeatation
		BOOL Found=FALSE;
		for(int i=0;i<TNumber;i++)
			if(ATerminal==Terminals[i])
			{
				Found=TRUE;
				break;
			}
        //if not repeated
        if(!Found)
		    Terminals[TNumber++]=ATerminal;
		return TRUE;
	}
	return FALSE;
}

char Grammar::GetStart()
{
    return Start;
}

char Grammar::GetVariable(int index)
{
  //assumed that index is valid
  return Variables[index];
}

char Grammar::GetTerminal(int index)
{
  //assumed that index is valid
  return Terminals[index];
}

CString Grammar::GetProduction(int index)
{
  //assumed that index is valid
  return Productions[index].GetProduction();
} 

CString Grammar::GetLeft(int i)
{
  return Productions[i].LeftPart();
}
