
// OOP_LR4_GalimovDoc.cpp : implementation of the COOPLR4GalimovDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OOP_LR4_Galimov.h"
#endif

#include "OOP_LR4_GalimovDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COOPLR4GalimovDoc

IMPLEMENT_DYNCREATE(COOPLR4GalimovDoc, CDocument)

BEGIN_MESSAGE_MAP(COOPLR4GalimovDoc, CDocument)
END_MESSAGE_MAP()


// COOPLR4GalimovDoc construction/destruction

COOPLR4GalimovDoc::COOPLR4GalimovDoc() noexcept
{
	// TODO: add one-time construction code here

}

COOPLR4GalimovDoc::~COOPLR4GalimovDoc()
{
}

BOOL COOPLR4GalimovDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	st.ClearProducts();
	return TRUE;
}




// COOPLR4GalimovDoc serialization

void COOPLR4GalimovDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		st.ToFileProducts(ar);//for save
		// TODO: add storing code here
	}
	else
	{
		st.ClearProducts();//for load
		st.FromFileProducts(ar);
		// TODO: add loading code here
		AfxGetMainWnd()->Invalidate(); //перерисовать себя
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void COOPLR4GalimovDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void COOPLR4GalimovDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void COOPLR4GalimovDoc::SetSearchContent(const CString& value)
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

// COOPLR4GalimovDoc diagnostics

#ifdef _DEBUG
void COOPLR4GalimovDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COOPLR4GalimovDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COOPLR4GalimovDoc commands
