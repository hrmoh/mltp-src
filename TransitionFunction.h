// TransitionFunction.h: interface for the TransitionFunction class.
//
//////////////////////////////////////////////////////////////////////
#include "TFMember.H"
#if !defined(AFX_TRANSITIONFUNCTION_H__A5E96FF5_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
#define AFX_TRANSITIONFUNCTION_H__A5E96FF5_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class TransitionFunction:public CObject
{
public:
	BOOL Signed[MAX_TFMEMBERS];
	BOOL NotSigned(CString PState, char input, CString FState);
	void Signify(CString PState, char input, int RNumber, CString *FStates);
	void DeleteTF(CString PState,char input,CString FState);
	BOOL ifExists(CString P,char input,CString F);
	void AddTF(CString PState,char input,int RNumber,CString* FStates);
	TransitionFunction();
    virtual ~TransitionFunction();
	int TFNumber;
	TFMember TFMembers[MAX_TFMEMBERS];
};

#endif // !defined(AFX_TRANSITIONFUNCTION_H__A5E96FF5_3F5B_11D4_A2C4_EBD4A6750110__INCLUDED_)
