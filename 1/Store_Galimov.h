#pragma once
#include <vector>
#include "Product_Galimov.h"
#include "Discount_product_Galimov.h"
#include <fstream>

class Store
{
protected:
	//vector<Product_Galimov*> Products_Galimov;
	vector<shared_ptr<Product_Galimov>> Products_Galimov;
public:
	void AddProduct(const shared_ptr<Product_Galimov>& ptr);
	//void AddDiscountProduct(Discount_product_Galimov* dp);
	void OutputProducts();
	void ToFileProducts();
	void FromFileProducts();
	void ClearProducts();

	~Store();
};

