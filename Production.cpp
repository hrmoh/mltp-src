// Production.cpp: implementation of the Production class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MLTP.h"
#include "Production.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CString EleminateAdditionalSpaces(CString AString)
{
	char tempStr[256];
	for(int i=0;i<AString.GetLength();i++)
		tempStr[i]=AString[i];
	tempStr[i]='\0';
	int length=AString.GetLength()+1;
	do
	{
    length--;
	for(int i=0;i<length;i++)
		if(tempStr[i]==' ')
			break;
    if(i!=length)
	{	
      for(int j=i;j<length-1;j++)
		  tempStr[j]=tempStr[j+1];
	   tempStr[j]='\0';
	}
	}while(i!=length);
    CString Result=tempStr; 
	return Result;
}


BOOL Check(CString PDefinition,CString& Error,int &ErrorPosition)
{
	EleminateAdditionalSpaces(PDefinition);
    int position=PDefinition.Find("->",0);
	//CHECKING ERRORS:

	if(position<0||position>PDefinition.GetLength()-1)
	{
	//1-Definition does not contain substring "=>"
		Error="Productions should contain '->'";
		return FALSE;
	}
    int p=position;
	p=PDefinition.Find("-",position+2);
	if(p>0&&p<PDefinition.GetLength())
	{
		//2-Additional symbole '-'
		Error="Additional symbole";
		ErrorPosition=p;
		return FALSE;
	}
	p=PDefinition.Find(">",position+2);
	if(p>0&&p<PDefinition.GetLength())
	{
		//3-Additional symbole '>'
		Error="Additional symbole";
		ErrorPosition=p;
		return FALSE;
	}

	for(position=0;
	     (
			isalpha(PDefinition[position])
			||
			PDefinition[position]==' '
			||
			PDefinition[position]=='@'
			||
			PDefinition[position]=='-'
			||
			PDefinition[position]=='>'
		 );
		 position++
	   );
    if(position<PDefinition.GetLength())
	{
    //4-there is character in definition other than Space,Terminals,Variables,'-','>','|'and LAMBDA
    Error="Unknon symbole ["+PDefinition[position]+']';
	ErrorPosition=position;
	return FALSE;
	}
	for(position=0;(PDefinition[position]!='-'&&!isupper(PDefinition[position]))&&position<PDefinition.GetLength();position++);
    if(PDefinition[position]=='-')
	{
	//5-Left(Definition) contains no character other than Space and LAMBDA
    Error="Left of '->' contains no variable or terminal";
	return FALSE;
	}
	
	while(PDefinition[position]!='>')
		position++;
	position++;

	for(;position!=PDefinition.GetLength()&&PDefinition[position]==' ';position++);
   if(position==PDefinition.GetLength())
	{
	//6-Right(Definition) contains no character other than Space
    Error="Right of '->' contains no symbole";
	return FALSE;
	}
	return TRUE;

}


Production::Production()
{

}

Production::~Production()
{

}

void Production::Set(CString Definition)
{
  //entered definition should be checked before, using function Check
  Definition=EleminateAdditionalSpaces(Definition);
  char tempStr[256]; 
  int ti;
  for(int i=0;Definition[i]!='-';i++)
  {
	  tempStr[i]=Definition[i];
	  ti=i;
  }
  tempStr[ti+1]='\0';
  Left=tempStr;
  ti++;
  ti++;
  ti++;
  int tj;
  for(int j=ti;j<Definition.GetLength();j++)
  {
      tempStr[j-ti]=Definition[j];
	  tj=j;
  }
  tempStr[tj-ti+1]='\0';
  Right=tempStr;
}

CString Production::RightPart()
{
 //production should be filled before
 return Right;
}

CString Production::LeftPart()
{
 //production should be filled befor

 return Left;
}


int Production::Linearity()
{
  if(Left.GetLength()!=1)
	  return NOT_DETERMINED;
  if(Right[0]=='@')
    if(Right.GetLength()==1)
	  return LAMBDA_ENDED;
	else
	  return NOT_DETERMINED;
  if(Right.GetLength()==1&&isupper(Right[0]))
	  return NOT_DETERMINED;
  if(isupper(Right[0]))
  {
	  for(int i=1;i<Right.GetLength();i++)
		  if(!islower(Right[i]))
			  return NOT_DETERMINED;
      return LEFT_LINEAR;
  }
  for(int i=1;i<Right.GetLength()-1;i++)
	  if(!islower(Right[i]))
		  return NOT_DETERMINED;
  if(!isupper(Right[Right.GetLength()-1]))
	  return LAMBDA_ENDED;
  return RIGHT_LINEAR;
}

BOOL Production::ConstRight()
{
  for(int i=0;i<Right.GetLength();i++)
	  if(isupper(Right[i]))
         return FALSE;
	  return TRUE;
}

CString Production::GetProduction()
{
	return Left+"->"+Right;
}


BOOL Production::Parses(CString &Str, BOOL &complete,char& NextState)
{
  if(!Str.GetLength())
	  if(Right=="@")
	  {
		  complete=TRUE;
		  return TRUE;
	  }
	  else
		  return FALSE;

  if(Right==Str)
  {
	  complete=TRUE;
	  return TRUE;
  }
  for(int i=0;i<Right.GetLength();i++)
     if(isupper(Right[i]))
		 NextState=Right[i];
  if(isupper(Right[0]))
  {
  int j=Str.GetLength()-1;
  for(i=Right.GetLength()-1;i>=0&&j>=0;i--)
	  if(Right[i]!=Str[j])
		  break;
	  else
		  j--;
  if(j==-1)
	  if(i==-1)
	    return TRUE;
	  else
	  {
      if(!isupper(Right[i]))
	     return FALSE;
	  Str="";

	  complete=FALSE;
	  return TRUE;
	  }
  if(!isupper(Right[i]))
     return FALSE;
  char s[50];
  for(i=0;i<=j;i++)
      s[i]=Str[i];
  s[i]='\0';
  Str=s;
  complete=FALSE;
  return TRUE;
  }
  else
  {
  int j=0;
  for(int i=0;i<Right.GetLength()-1&&j<Str.GetLength();i++,j++)
	  if(Right[i]!=Str[j])
          break;
  if(!isupper(Right[i]))
     return FALSE;
  char s[50];
  for(i=j;i<Str.GetLength();i++)
      s[i-j]=Str[i];
  s[i-j]='\0';
  Str=s;
  complete=FALSE;
  return TRUE;
  }
  return FALSE;
}
