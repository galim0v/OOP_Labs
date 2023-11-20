
// OOP_LR3_GalimovDoc.cpp : implementation of the COOPLR3GalimovDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OOP_LR3_Galimov.h"
#endif

#include "OOP_LR3_GalimovDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COOPLR3GalimovDoc

IMPLEMENT_DYNCREATE(COOPLR3GalimovDoc, CDocument)

BEGIN_MESSAGE_MAP(COOPLR3GalimovDoc, CDocument)
END_MESSAGE_MAP()


// COOPLR3GalimovDoc construction/destruction

COOPLR3GalimovDoc::COOPLR3GalimovDoc() noexcept
{
	// TODO: add one-time construction code here

}

COOPLR3GalimovDoc::~COOPLR3GalimovDoc()
{
}

BOOL COOPLR3GalimovDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	//вызов функции очистки
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	st.ClearProducts();
	return TRUE;
}




// COOPLR3GalimovDoc serialization

void COOPLR3GalimovDoc::Serialize(CArchive& ar)
{
	//перед загрузкой функцию очистки тк OnNewDocument не вызывается
	if (ar.IsStoring())
	{
		st.OutputProducts();//for save
		// TODO: add storing code here
	}
	else
	{
		st.ClearProducts();//for load
		st.AddProduct();
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void COOPLR3GalimovDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void COOPLR3GalimovDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void COOPLR3GalimovDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// COOPLR3GalimovDoc diagnostics

#ifdef _DEBUG
void COOPLR3GalimovDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COOPLR3GalimovDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COOPLR3GalimovDoc commands
