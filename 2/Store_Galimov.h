#pragma once
#include <vector>
#include "Product_Galimov.h"
#include "Discount_product_Galimov.h"
#include <fstream>
#include "pch.h"

using namespace std;

class Store
{
protected:
	vector<shared_ptr<Product_Galimov>> Products_Galimov;
public:
	void AddProduct(shared_ptr<Product_Galimov> ptr);
	//void AddDiscountProduct(shared_ptr<Discount_product_Galimov> dptr);
	void OutputProducts();
	void ToFileProducts();
	void FromFileProducts();
	void ClearProducts();

	~Store();
};

