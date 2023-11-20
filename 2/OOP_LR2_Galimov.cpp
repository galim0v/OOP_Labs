#include "pch.h"
//#include "framework.h"
#include "OOP_LR2_Galimov.h"

#include <iostream>
#include "Product_Galimov.h"
#include "Store_Galimov.h"
#include <string>
#include <fstream>
#include "Discount_product_Galimov.h"
#include <memory>
#include "Utils.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
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
			shared_ptr<Product_Galimov> ptr = make_shared<Product_Galimov>();
			ptr->InputProduct();
			st.AddProduct(ptr);
			break;
		}
		case 2:
			st.OutputProducts();
			break;
		case 3:
		{
			st.FromFileProducts();
			break;
		}
		case 4:
			st.ToFileProducts();
			break;
		case 5:
		{//почему эти скобки зароляли в решении проблемы c2360 и c2361???
			shared_ptr<Discount_product_Galimov> dptr = make_shared<Discount_product_Galimov>();
			dptr->InputProduct();
			//st.AddDiscountProduct(dptr);
			st.AddProduct(dptr);
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
