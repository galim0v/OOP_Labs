#include "pch.h"
#include "Product_Galimov.h"

#include <iostream>
#include <fstream>


IMPLEMENT_SERIAL(Product_Galimov, CObject, 0)

//
//Product_Galimov::Product_Galimov(string n, float p, float w, float c)
//{
//	name = n;
//	price = p;
//	weight = w;
//	code = c;
//}

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
		ar << CString(name.c_str());
		ar << price;
		ar << weight;
		ar << code;
	}
	else
	{
		CString temp;
		ar >> temp; 
		name = CT2A(temp.GetBuffer()); // Преобразование CString в std::string
		ar >> price;
		ar >> weight;
		ar >> code;
	}
}