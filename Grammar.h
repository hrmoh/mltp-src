// Grammar.h: interface for the Grammar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAMMAR_H__F976A6E1_3EC1_11D4_A2C4_81DF15DC3218__INCLUDED_)
#define AFX_GRAMMAR_H__F976A6E1_3EC1_11D4_A2C4_81DF15DC3218__INCLUDED_

#include "Production.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX_TERMINALS 100
#define MAX_VARIABLES 100
#define MAX_PRODUCTIONS 100
class Grammar : public CObject  
{
public:
	CString GetLeft(int i);
	Grammar();
	virtual ~Grammar();
	BOOL AddToTerminals(char ATerminal);
	BOOL SetAsStart(char AVariable);
	BOOL AddToVariables(char nVariable);
	CString GetProduction(int index);
	char GetTerminal(int index);
	char GetVariable(int index);
	char GetStart();

	int VNumber;
	char Variables[MAX_VARIABLES];
	int TNumber;
	char Terminals[MAX_TERMINALS];
	char Start;
	int PNumber;
	Production Productions[MAX_PRODUCTIONS];
};

#endif // !defined(AFX_GRAMMAR_H__F976A6E1_3EC1_11D4_A2C4_81DF15DC3218__INCLUDED_)
