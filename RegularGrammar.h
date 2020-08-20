// RegularGrammar.h: interface for the RegularGrammar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGULARGRAMMAR_H__A5E96FE2_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
#define AFX_REGULARGRAMMAR_H__A5E96FE2_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Grammar.h"
#include "NFA.H"
class RegularGrammar : public Grammar  
{
public:
	void ResetLinearity();
	void DeleteProduction(int index);
	BOOL DeleteProduction(CString pDefintion);
	BOOL ifAccepts(CString Str,int& index,int* indexes);
	int LambdaProductionIndex();
	BOOL ifAccepts(CString Str,int& index,int *indexes,char StartV);
	int Linearity;
	void EquivalentNFA(NFA &ENFA);
	void Assign(RegularGrammar Another);
	int NumberOfProductions();
	int GetLinearity();
	int NumberOfTerminals();
	int NumberOfVariables();
	RegularGrammar(RegularGrammar& Another);
	BOOL AddToProductions(CString newProduction,CString& Error,int& ErrorPosition);
	RegularGrammar();
	virtual ~RegularGrammar();
};

#endif // !defined(AFX_REGULARGRAMMAR_H__A5E96FE2_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
