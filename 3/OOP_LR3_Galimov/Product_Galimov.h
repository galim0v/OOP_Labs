#pragma once
#include "pch.h"

class Product_Galimov :public CObject
{
protected:
	CString name ;
	float price = 0, weight = 0, code = 0;
public:
	DECLARE_SERIAL(Product_Galimov)
	virtual void Serialize(CArchive& ar);
	Product_Galimov() {}
	virtual void GetLength(CDC* pDC, int* aLen);
	virtual void CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight);
	virtual void InputProduct();
	virtual void OutputProduct();
	virtual ~Product_Galimov() {}
};
