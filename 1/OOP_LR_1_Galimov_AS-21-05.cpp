#include <iostream>
#include "Product_Galimov.h"
#include "Store_Galimov.h"
#include <string>
#include <fstream>
#include "Discount_product_Galimov.h"
#include <memory>
#include "Utils.h"


using namespace std;

int main()
{
	//int a = 5; //&a предоставляет адрес в памяти, где хранится значение a.
	//int* b = &a; //b= указатель на целое число
	////Теперь указатель b указывает на тот же участок памяти, где хранится значение a.
	//cout << &a<<" "<<b<<" silki";
	//cout <<"\n"<< * b;
	//cout << "\n" << &b << " " << **(&b);

	size_t s = 0;
	Store st;
	do {
		PrintMenu();
		cin >> s;
		switch (s)
		{
		case 0:
			exit(0);
			break;
		case 1:
		{
			shared_ptr<Product_Galimov> ptr = make_shared<Product_Galimov>(); //Создаётся объект
			//Product_Galimov* pr = new Product_Galimov;
			ptr->InputProduct();
			st.AddProduct(ptr);
			break;
		}
		case 2:
			st.OutputProducts();
			break;
		case 3:
			st.FromFileProducts();
			break;
		case 4:
			st.ToFileProducts();
			break;
		case 5:
		{//почему эти скобки зароляли в решении проблемы c2360 и c2361???
			//Discount_product_Galimov* dpr = new Discount_product_Galimov;
			shared_ptr<Discount_product_Galimov> dptr = make_shared<Discount_product_Galimov>();
			dptr->InputProduct();
			st.AddProduct(dptr);
			//st.AddDiscountProduct(dpr); //можно ли другую функцию? или нужно именно через shared_prt?
			//cout << "test\n";
			break;
		}
		case 6:
			st.ClearProducts();
			break;
		default:
			cout << "Invalid value. Try again\n";
		}
	} while (s != 0);

	return 0;
}