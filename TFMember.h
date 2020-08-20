// TFMember.h: interface for the TFMember class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TFMEMBER_H__12D1E741_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
#define AFX_TFMEMBER_H__12D1E741_3F1B_11D4_A2C4_FB1016816218__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define MAX_RESULTS 100
#define MAX_TFMEMBERS 100
class TFMember : public CObject  
{
public:
	BOOL Equal(TFMember& Another);
	CString WhichResult(int index);
	char WhichInputAlphabet();
	CString WhichInputState();
	void Set(CString PState,char input,int RNumber,CString* FStates);
	TFMember();
	virtual ~TFMember();
	int RSNumber;
private:
	CString State;
	char Input;
	CString ResultStates[MAX_RESULTS];
};
#endif // !defined(AFX_TFMEMBER_H__12D1E741_3F1B_11D4_A2C4_FB1016816218__INCLUDED_)
