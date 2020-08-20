// NFA.h: interface for the NFA class.
//
//////////////////////////////////////////////////////////////////////
#include "TransitionFunction.H"
#if !defined(AFX_NFA_H__12D1E743_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
#define AFX_NFA_H__12D1E743_3F1B_11D4_A2C4_FB1016816218__INCLUDED_

#include "TFMember.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX_STATES 100
#define MAX_ALPHA 100
#include "State.h"
#include "DFA.h"
#include "DFAFrame.h"
class NFA : public CObject  
{
public:
	void Reverse();
	BOOL isNextEqualToItself(char input,int Number,CString* NowStates);
	BOOL NextStates(char input,int &Number,CString* StatesNames);
	BOOL isStart(CString SName);
	BOOL isFinal(CString StateName);
	BOOL ifDelta(CString m_PState,char m_input,CString m_FState);
	void Show(CDFAFrame *DFAFrame);
	void EquivalentDFA(DFA& EDFA);
	BOOL AddToTransitionFunction(CString PState,char input,int RNumber,CString* FStates);
	BOOL SetFinal(CString AState);
	BOOL SetStart(CString AState);
	void AddToZigma(char alpha);
	void AddToStates(CString AState);
	NFA();
	virtual ~NFA();
//private:
	int SNumber;
	CState Q[MAX_STATES];
	int ZNumber;
	char Zigma[MAX_ALPHA];
	TransitionFunction Delta;
	CString Start;
	int FNumber;
	CString F[MAX_STATES];
};

#endif // !defined(AFX_NFA_H__12D1E743_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
