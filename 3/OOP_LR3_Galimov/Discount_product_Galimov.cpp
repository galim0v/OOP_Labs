#include "pch.h"
#include "Discount_product_Galimov.h"

IMPLEMENT_SERIAL(Discount_product_Galimov, Product_Galimov, VERSIONABLE_SCHEMA | 0)

void Discount_product_Galimov::InputProduct()
{
	Product_Galimov::InputProduct();
	cout << "Input discount: ";
	cin >> discount;
	cout << "Input quantity: ";
	cin >> quantity;
}

void Discount_product_Galimov::OutputProduct()
{
	Product_Galimov::OutputProduct();
	cout << discount << "\n"
		<< quantity << "\n";
}

void Discount_product_Galimov::Serialize(CArchive& ar)
{
	Product_Galimov::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << discount;
		ar << quantity;
	}
	else
	{
		ar >> discount;
		ar >> quantity;
	}
}

void Discount_product_Galimov::GetLength(CDC* pDC, int* aLen)
{
	Product_Galimov::GetLength(pDC, aLen);
	aLen[4] = pDC->GetTextExtent(CString(to_wstring(discount).c_str())).cx;
	aLen[5] = pDC->GetTextExtent(CString(to_wstring(quantity).c_str())).cx;
}

void Discount_product_Galimov::CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight)
{
	pDC->TextOutA(aLeft[4], top, to_string(discount).c_str());
	pDC->TextOutA(aLeft[5], top, to_string(quantity).c_str());
	Product_Galimov::CDCDrow(pDC, aLeft, aLen, top, lineHeight);
}

