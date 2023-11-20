#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Product_Galimov
{
protected:
	string name = "";
	float price = 0, weight = 0, code = 0;
public:
	Product_Galimov() = default;
	//Product_Galimov(string n, float p, float w, float c);


	virtual void InputProduct();
	virtual void OutputProduct();

	virtual void ToFileProduct(ofstream& output);
	virtual void FromFileProduct(ifstream& input);
	

	friend istream& operator>>(istream& in, Product_Galimov& product);
	friend ostream& operator<<(ostream& out, const Product_Galimov& product);
};

//Product InputProduct();
//void ToFileProduct();
//void FromFileProduct();

	//string GetName() const;
	//int GetPrice() const;
	//int GetWeight() const;
	//int GetCode() const;

	//void SetName(string n);
	//void SetPrice(int p);
	//void SetWeight(int w);
	//void SetCode(int c);