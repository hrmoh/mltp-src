// TFMember.cpp: implementation of the TFMember class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "TFMember.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TFMember::TFMember()
{
 RSNumber=0;
}

TFMember::~TFMember()
{

}

void TFMember::Set(CString PState, char input, int RNumber, CString *FStates)
{
 //assumed that input parameters ate correct
 //input can be a small letter + LAMBDA
 State=PState;
 Input=input;
 RSNumber=RNumber;
 for(int i=0;i<RNumber;i++)
   ResultStates[i]=FStates[i];
}

CString TFMember::WhichInputState()
{
 return State;
}

char TFMember::WhichInputAlphabet()
{
 return Input;
}

CString TFMember::WhichResult(int index)
{
 //assumed that index is a valid number
 return ResultStates[index];
}


BOOL TFMember::Equal(TFMember& Another)
{
 if(Another.State!=State)
	 return FALSE;
 if(Another.Input!=Input)
	 return FALSE;
 if(Another.RSNumber!=RSNumber)
	 return FALSE;
 for(int i=0;i<RSNumber;i++)
 {
	 for(int j=0;j<RSNumber;j++)
		 if(Another.ResultStates[j]==ResultStates[i])
			 break;
     if(j=RSNumber)
		 return FALSE;
 }
  return TRUE;
}
