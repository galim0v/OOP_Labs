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

