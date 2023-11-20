#include "Discount_product_Galimov.h"

void Discount_product_Galimov::InputProduct()
{
	Product_Galimov::InputProduct();
	cout << "Input discount: ";
	cin >> discount;
	cout << "Input quantity: ";
	cin >> quantity;
}

void Discount_product_Galimov::OutputProduct()
{
	Product_Galimov::OutputProduct();
	cout <<discount<<"\n"
		<<quantity<<"\n";
}

void Discount_product_Galimov::ToFileProduct(ofstream& output)//тут нужна MFC сериализация
{
	Product_Galimov::ToFileProduct(output);
	output << discount << "\n" 
		<< quantity << "\n";
}

void Discount_product_Galimov::FromFileProduct(ifstream& input)//тут нужна MFC сериализация
{
	Product_Galimov::FromFileProduct(input);
	input >> discount >> quantity;
}
