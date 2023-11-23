#include "pch.h"
#include "Store_Galimov.h"

void Store::AddProduct(shared_ptr<Product_Galimov> ptr)
{
	if (ptr)
		Products_Galimov.push_back(ptr);
}

void Store::OutputProducts()
{
	for (auto i : Products_Galimov)
		(*i).OutputProduct();
}

void Store::ToFileProducts(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&f, CArchive::store);*/
	ar << (int)Products_Galimov.size();
	for (auto o : Products_Galimov)
	{
		auto* rawPtr = o.get();
		ar << rawPtr;
	}
}

void Store::FromFileProducts(CArchive& ar)
{
	/*CFile f("f.dat", CFile::modeRead);
	CArchive ar(&f, CArchive::load);*/
	int n;
	ar >> n;
	for (int i = 0; i < n; ++i)
	{
		Product_Galimov* ptr3;
		ar >> ptr3;
		shared_ptr<Product_Galimov> ptr2(ptr3);
		Products_Galimov.push_back(ptr2);
	}
}

void Store::ClearProducts()
{
	Products_Galimov.clear();
}

void Store::AddProductWithPointer()
{
	shared_ptr<Product_Galimov> ptr = make_shared<Product_Galimov>();
	ptr->InputProduct();
	this->AddProduct(ptr);
}

CSize Store::DrawTable(CDC* pDC)
{
	const int indent = 5;
	const int HorSpace = 15;
	const int LineHeight = 30;


	CString name;
	float price = 0, weight = 0, code = 0;
	float discount = 0, quantity = 0;

	CString aHead[6];
	aHead[0] = "Name";
	aHead[1] = "Price";
	aHead[2] = "Weight";
	aHead[3] = "Code";
	aHead[4] = "Discount";
	aHead[5] = "Quantity";


	int aLen[6];
	for (int i = 0; i < 6; ++i)
		aLen[i] = pDC->GetTextExtent(aHead[i]).cx;


	for (auto prod : Products_Galimov)
	{
		int memLen[6];
		prod->GetLength(pDC, memLen);
		for (int i = 0; i < 6; ++i)
			if (memLen[i] > aLen[i])
				aLen[i] = memLen[i];
	}


	aLen[0] += indent;
	for (int i = 1; i < 6; ++i)
	{
		aLen[i - 1] += HorSpace;
		aLen[i] += aLen[i - 1];
	}

	int aLeft[6];
	aLeft[0] = indent;
	for (int i = 1; i < 6; ++i)
		aLeft[i] = aLen[i - 1];


	int top = indent;
	for (int i = 0; i < 6; ++i)
	{
		pDC->TextOutA(aLeft[i], top, aHead[i]);
	}
	top += LineHeight;


	for_each(Products_Galimov.begin(), Products_Galimov.end(), bind(&Product_Galimov::CDCDrow, placeholders::_1, pDC, aLeft, aLen, ref(top), LineHeight));

	POINT sizeAll;
	sizeAll.x = aLen[5] + indent;
	sizeAll.y = top;

	pDC->MoveTo(0, 0);
	pDC->LineTo(sizeAll.x, 0);
	pDC->LineTo(sizeAll);
	pDC->LineTo(0, sizeAll.y);
	pDC->LineTo(0, 0);

	for (int i = 1; i < 6; ++i)
	{
		pDC->MoveTo(aLeft[i] - HorSpace / 2, 0);
		pDC->LineTo(aLeft[i] - HorSpace / 2, sizeAll.y);
	}
	pDC->MoveTo(0, indent + LineHeight - 5);
	pDC->LineTo(sizeAll.x, indent + LineHeight - 5);

	return sizeAll;
}

Store::~Store()
{
	ClearProducts();
}
