
// OOP_LR4_GalimovView.cpp : implementation of the COOPLR4GalimovView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OOP_LR4_Galimov.h"
#endif

#include "OOP_LR4_GalimovDoc.h"
#include "OOP_LR4_GalimovView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COOPLR4GalimovView

IMPLEMENT_DYNCREATE(COOPLR4GalimovView, CScrollView)

BEGIN_MESSAGE_MAP(COOPLR4GalimovView, CScrollView)
END_MESSAGE_MAP()

// COOPLR4GalimovView construction/destruction

COOPLR4GalimovView::COOPLR4GalimovView() noexcept
{
	// TODO: add construction code here

}

COOPLR4GalimovView::~COOPLR4GalimovView()
{
}

BOOL COOPLR4GalimovView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// COOPLR4GalimovView drawing

void COOPLR4GalimovView::OnDraw(CDC* pDC)
{
	COOPLR4GalimovDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen(PS_SOLID, 3, RGB(0, 0, 128));
	CPen* pOldpen = pDC->SelectObject(&pen);

	CSize sizeTotal = pDoc->st.DrawTable(pDC);
	SetScrollSizes(MM_TEXT, sizeTotal); //логический размер и режим сопоставления координат для прокрутки вида

	pDC->SelectObject(&pOldpen);
}

void COOPLR4GalimovView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// COOPLR4GalimovView diagnostics

#ifdef _DEBUG
void COOPLR4GalimovView::AssertValid() const
{
	CScrollView::AssertValid();
}

void COOPLR4GalimovView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

void COOPLR4GalimovView::OnEditMenu()
{
	Invalidate();
}

COOPLR4GalimovDoc* COOPLR4GalimovView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COOPLR4GalimovDoc)));
	return (COOPLR4GalimovDoc*)m_pDocument;
}
#endif //_DEBUG


// COOPLR4GalimovView message handlers
