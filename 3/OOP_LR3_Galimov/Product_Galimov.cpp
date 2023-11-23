#include "pch.h"
#include "Product_Galimov.h"
#include <string>
#include <iostream>
#include <fstream>


IMPLEMENT_SERIAL(Product_Galimov, CObject, 0)

void Product_Galimov::InputProduct() 
{
	cout << "Input Product-Name: ";
	string tempName;
	getline(cin >> ws, tempName);
	name = CString(tempName.c_str());
	CString cStringName(name);
	cout << "Input Product-Price: ";
	cin >> price;
	cout << "Input Product-Weight: ";
	cin >> weight;
	cout << "Input Product-Code: ";
	cin >> code;
}

void Product_Galimov::OutputProduct()
{
	cout << name << "\n" << price << "\n" << weight << "\n" << code << "\n";
}

void Product_Galimov::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << name<< price<< weight << code;
	}
	else
	{
		ar >> name >> price >> weight >> code;
	}
}

void Product_Galimov::GetLength(CDC* pDC, int* aLen)
{
	aLen[0] = pDC->GetTextExtent(name).cx;
	aLen[1] = pDC->GetTextExtent(CString(to_wstring(price).c_str())).cx;
	aLen[2] = pDC->GetTextExtent(CString(to_wstring(weight).c_str())).cx;
	aLen[3] = pDC->GetTextExtent(CString(to_wstring(code).c_str())).cx;
	aLen[4] = 0;
	aLen[5] = 0;
}

void Product_Galimov::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{
	pDC->TextOutA(aLeft[0], top, name);
	pDC->TextOutA(aLeft[1], top, to_string(price).c_str());
	pDC->TextOutA(aLeft[2], top, to_string(weight).c_str());
	pDC->TextOutA(aLeft[3], top, to_string(code).c_str());
	top += lineHeight;
	pDC->MoveTo(0, top - 5);
	pDC->LineTo(aLen[5] + 5, top - 5);
}
