// DFA.h: interface for the DFA class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DFA_H__12D1E742_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
#define AFX_DFA_H__12D1E742_3F1B_11D4_A2C4_FB1016816218__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX_STATES 100
#define MAX_ALPHA 100
#include "State.h"
#include "TransitionFunction.h"
#include "DDFAFrame.h"

struct coupleint
{
	int m;
	int n;
};

   struct Set{
	   int Number;
	   coupleint Members[30];
    
};

class DFA : public CObject  
{
public:
	void DeleteState(int index);
	void Merge(int m,int n);
	void DIST(int i,int j,int D[30][30],Set S[30][30]);
	void Minimize();
	int Next(int index,char input);
	BOOL Accepts(CString Str);
	int second;
	int first;
	BOOL ifDelta(CString m_PState, char m_input, CString m_FState);
	void Show(CDDFAFrame *Frame);
	CString GenerateNewName();
	DFA();
	virtual ~DFA();
	int SNumber;
	CState Q[MAX_STATES];
	int ZNumber;
	char Zigma[MAX_ALPHA];
	TransitionFunction Delta;
	CString Start;
	int FNumber;
	CString F[MAX_STATES];
};

#endif // !defined(AFX_DFA_H__12D1E742_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
