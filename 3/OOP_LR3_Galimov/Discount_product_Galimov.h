#pragma once
#include "Product_Galimov.h"
//#include "framework.h"
#include "pch.h"
#include <atlstr.h>


class Discount_product_Galimov :
    public Product_Galimov
{
protected:
    int discount = 0, quantity = 0;
public:
    DECLARE_SERIAL(Discount_product_Galimov);

    Discount_product_Galimov() {}
    void InputProduct() override;
    void OutputProduct() override;

    void Serialize(CArchive& ar) override;
};
