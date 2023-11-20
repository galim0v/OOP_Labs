#pragma once
#include "Product_Galimov.h"

class Discount_product_Galimov :
    public Product_Galimov
{
protected:
    int discount = 0, quantity = 0;
public:
    Discount_product_Galimov()=default;
    void InputProduct() override;
    void OutputProduct() override;

    void ToFileProduct(ofstream& output) override;//��� ����� MFC ������������
    void FromFileProduct(ifstream& input) override;//��� ����� MFC ������������
};

