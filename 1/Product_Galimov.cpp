#include "Product_Galimov.h"
#include <iostream>
#include <fstream>
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
	cout << name << "\n" << price << "\n" << weight << "\n" << code<<"\n";
}

void Product_Galimov::ToFileProduct(ofstream& output) {
	output << name << "\n" << price << "\n" << weight << "\n" << code << "\n";
}

void Product_Galimov::FromFileProduct(ifstream& input)
{
	input >> name >> price >> weight >> code;
}

istream& operator>>(istream& in, Product_Galimov& product)
{
	in >> product.name >> product.price >> product.weight >> product.code;
	return in;
}

ostream& operator<<(ostream& out, const Product_Galimov& product)
{
	out << product.name << "\n" << product.price << "\n" << product.weight << "\n" << product.code<<"\n";
	return out;
}

//Product Product::InputProduct()
//{
//	string n = "";
//	int pr = 0, w = 0, c = 0;
//	cout << "Input Product-Name: ";
//	getline(cin >> ws, n);
//	cout << "Input Product-Price: ";
//	cin >> pr;
//	cout << "Input Product-Weight: ";
//	cin >> w;
//	cout << "Input Product-Code: ";
//	cin >> c;
//	Product p(n, pr, w, c);
//	return p;
//}

//void Product::ToFileProduct()
//{
//	ofstream fout;
//	fout.open("ToFile.txt", ios_base::app);
//	fout <<name << "\n" << price << "\n" << weight << "\n" << code;
//	fout.close();
//}

//void Product::FromFileProduct()
//{
//	string n;
//	int w, pr, c;
//	ifstream fin;
//	fin.open("FromFile.txt");
//	getline(fin >> ws, n);
//	fin >> pr;
//	fin >> w;
//	fin >> c;
//	fin.close();
//	name = n;
//	price = pr;
//	weight = w;
//	code = c;
//}

//string Product::GetName() const
//{
//	return name;
//}
//
//int Product::GetPrice() const
//{
//	return price;
//}
//
//int Product::GetWeight() const
//{
//	return weight;
//}
//
//int Product::GetCode() const
//{
//	return code;
//}
//
//void Product::SetName(string n)
//{
//	name = n;
//}
//
//void Product::SetPrice(int p)
//{
//	price = p;
//}
//
//void Product::SetWeight(int w)
//{
//	weight = w;
//}
//
//void Product::SetCode(int c)
//{
//	code = c;
//}