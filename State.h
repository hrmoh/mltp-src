// State.h: interface for the CState class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATE_H__33D06BE1_4495_11D4_A2C4_CD1225C85E02__INCLUDED_)
#define AFX_STATE_H__33D06BE1_4495_11D4_A2C4_CD1225C85E02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CState : public CObject  
{
public:
	int yPos;
	int xPos;
	BOOL isFinal;
	CString Name;
	CState();
	virtual ~CState();

};

#endif // !defined(AFX_STATE_H__33D06BE1_4495_11D4_A2C4_CD1225C85E02__INCLUDED_)
