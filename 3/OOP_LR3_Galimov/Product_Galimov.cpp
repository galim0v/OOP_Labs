#include "pch.h"
#include "Product_Galimov.h"

#include <iostream>
#include <fstream>


IMPLEMENT_SERIAL(Product_Galimov, CObject, 0)

void Product_Galimov::InputProduct() {

	cout << "Input Product-Name: ";
	getline(cin >> ws, name);
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