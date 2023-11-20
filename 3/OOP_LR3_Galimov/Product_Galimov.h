#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>
//#include "framework.h"
#include "pch.h"
#include <atlstr.h>

using namespace std;

class Product_Galimov :public CObject
{
protected:
	CString name ;
	float price = 0, weight = 0, code = 0;
public:
	DECLARE_SERIAL(Product_Galimov)
	Product_Galimov() {}

	virtual void InputProduct();
	virtual void OutputProduct();

	virtual void Serialize(CArchive& ar);
};
