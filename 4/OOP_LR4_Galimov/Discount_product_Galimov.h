#pragma once
#include "Product_Galimov.h"
#include "pch.h"

class Discount_product_Galimov :
    public Product_Galimov
{
protected:
    float discount = 0, quantity = 0;
public:
    DECLARE_SERIAL(Discount_product_Galimov);

    Discount_product_Galimov() {}
    void InputProduct() override;
    void OutputProduct() override;

    void Serialize(CArchive& ar) override;
    void GetLength(CDC* pDC, int* aLen);
    void CDCDrow(CDC* pDC, int* aLeft, int* aLen, int& top, int lineHeight);
};
