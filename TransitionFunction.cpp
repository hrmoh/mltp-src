// TransitionFunction.cpp: implementation of the TransitionFunction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "TransitionFunction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TransitionFunction::TransitionFunction()
{
 TFNumber=0;
 for(int i=0;i<MAX_TFMEMBERS;i++)
	 Signed[i]=FALSE;
}
TransitionFunction::~TransitionFunction()
{

}

void TransitionFunction::AddTF(CString PState, char input, int RNumber, CString *FStates)
{
  TFMember Temp;
  Temp.Set(PState,input,RNumber,FStates);
  for(int i=0;i<TFNumber;i++)
	  if(Temp.Equal(TFMembers[i]))
		  break;
  if(i<TFNumber)
	  return;
  TFMembers[TFNumber++].Set(PState,input,RNumber,FStates);
}


BOOL TransitionFunction::ifExists(CString P, char input, CString F)
{
  for(int i=0;i<TFNumber;i++)
  {
	  if(TFMembers[i].WhichInputAlphabet()==input
          &&
         TFMembers[i].WhichInputState()==P)
		 for(int j=0;j<TFMembers[i].RSNumber;j++)
			 if(TFMembers[i].WhichResult(j)==F)
				 return TRUE;
  }
  return FALSE;
}

void TransitionFunction::DeleteTF(CString PState, char input, CString FState)
{
  TFMember Temp;
  CString FStates[2];
  FStates[0]=FState;
  Temp.Set(PState,input,1,FStates);
  for(int i=0;i<TFNumber;i++)
	  if(Temp.Equal(TFMembers[i]))
		  break;
  if(i<TFNumber)
  {
  TFNumber--;
  for(int j=i;j<TFNumber;j++)
  {
  FStates[0]=TFMembers[i+1].WhichResult(0);
  TFMembers[i].Set(TFMembers[i+1].WhichInputState(),TFMembers[i+1].WhichInputAlphabet(),1,FStates);
  }
  }

}

void TransitionFunction::Signify(CString PState, char input, int RNumber, CString *FStates)
{
  TFMember Temp;
  Temp.Set(PState,input,RNumber,FStates);
  for(int i=0;i<TFNumber;i++)
	  if(Temp.Equal(TFMembers[i]))
		  break;
  if(i<TFNumber)
	  Signed[i]=TRUE;

}

BOOL TransitionFunction::NotSigned(CString PState, char input, CString FState)
{
  TFMember Temp;
  CString FStates[2];
  FStates[0]=FState;
  Temp.Set(PState,input,1,FStates);
  for(int i=0;i<TFNumber;i++)
	  if(Temp.Equal(TFMembers[i]))
		  break;
  if(i<TFNumber)
  {
    return !Signed[i];
  }
  return FALSE;
}
