#pragma once
#include "Product_Galimov.h"
#include "Discount_product_Galimov.h"
#include "pch.h"

class Store
{
protected:
	vector<shared_ptr<Product_Galimov>> Products_Galimov;
public:
	void AddProduct(shared_ptr<Product_Galimov> ptr);
	void OutputProducts();
	void ToFileProducts(CArchive& ar);
	void FromFileProducts(CArchive& ar);
	void ClearProducts();
	void AddProductWithPointer();
	CSize DrawTable(CDC* pDC);
	~Store();
};

