// Production.h: interface for the Production class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRODUCTION_H__79196E0F_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_)
#define AFX_PRODUCTION_H__79196E0F_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define NOT_DETERMINED 0
#define RIGHT_LINEAR 1
#define LEFT_LINEAR 2
#define LAMBDA_ENDED 3


#define LAMBDA '@'
class Production : public CObject  
{
public:
	BOOL Parses(CString& Str,BOOL& complete,char& NextState);
	BOOL ConstRight();
	Production();
	virtual ~Production();

	void Set(CString Definition);

	CString GetProduction();
	CString LeftPart();
	CString RightPart();

	int Linearity();

private:
	CString Left;
	CString Right;
};

#endif // !defined(AFX_PRODUCTION_H__79196E0F_3E81_11D4_A2C4_DE107A512A1B__INCLUDED_)
