#include "Store_Galimov.h"


void Store::AddProduct(const shared_ptr<Product_Galimov>& ptr)
{
	if (ptr)
		Products_Galimov.push_back(ptr);
}

//void Store::AddDiscountProduct(Discount_product_Galimov* dp) //это плохо?
//{
//	if (dp)
//		Products_Galimov.push_back(dp);
//}

void Store::OutputProducts()
{
	for (auto i : Products_Galimov)
	//for (Product_Galimov *i : Products_Galimov)
		(*i).OutputProduct();
}

void Store::ToFileProducts()
{
	ofstream fout;
	fout.open("ToFile.txt", ios_base::out);

	if (!fout.is_open()) {
		cerr << "Не удается открыть файл " <<endl;
		return ; // Завершить программу с ошибкой
	}

	for (auto i : Products_Galimov)
		(*i).ToFileProduct(fout);
	fout.close();
}

void Store::FromFileProducts()
{
	ifstream fin;
	fin.open("FromFile.txt",ios_base::in);

	if (!fin.is_open()) {
		cerr << "Не удается открыть файл " << endl;
		return; // Завершить программу с ошибкой
	}
	ClearProducts();
	Product_Galimov*pr=new Product_Galimov;
	shared_ptr<Product_Galimov> ptr = make_shared<Product_Galimov>();

	while (fin>>(*pr)) {			//почему перегрузка оператора зароляла?
		//pr.FromFileProduct(fin); //нужна ли эта строчка
		AddProduct(ptr);
		ptr = make_shared<Product_Galimov>();
		//pr = new Product_Galimov;
		//delete pr;
	}
	fin.close();

}

void Store::ClearProducts()
{
	/*for (auto i : Products_Galimov) {
		delete(i);
	}*/
	Products_Galimov.clear();
}

Store::~Store()
{
	ClearProducts();
}
