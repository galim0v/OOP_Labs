#include "pch.h"
#include "Store_Galimov.h"



void Store::AddProduct(shared_ptr<Product_Galimov> ptr)
{
	if (ptr)
		Products_Galimov.push_back(ptr);
}

void Store::OutputProducts()
{
	for (auto i : Products_Galimov)
		(*i).OutputProduct();
}

//void Store::ToFileProducts()
//{
//	CFile f("f.dat", CFile::modeCreate | CFile::modeWrite);
//	CArchive ar(&f, CArchive::store);
//	ar << (int)Products_Galimov.size();
//	for (auto o : Products_Galimov)
//	{
//		auto* rawPtr = o.get();
//		ar << rawPtr;
//		//o->Serialize(ar);
//	}
//	Products_Galimov.clear();
//}

//void Store::FromFileProducts()
//{
//	CFile f("f.dat", CFile::modeRead);
//	CArchive ar(&f, CArchive::load);
//	//size_t n=0;
//	int n;
//	ar >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		Product_Galimov* ptr3;
//		ar >> ptr3;
//		shared_ptr<Product_Galimov> ptr2(ptr3);
//		Products_Galimov.push_back(ptr2);
//	}
//}

void Store::ClearProducts()
{
	Products_Galimov.clear();
}

Store::~Store()
{
	ClearProducts();
}
