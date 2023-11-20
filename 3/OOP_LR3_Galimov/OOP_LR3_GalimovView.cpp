
// OOP_LR3_GalimovView.cpp : implementation of the COOPLR3GalimovView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "OOP_LR3_Galimov.h"
#endif

#include "OOP_LR3_GalimovDoc.h"
#include "OOP_LR3_GalimovView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COOPLR3GalimovView

IMPLEMENT_DYNCREATE(COOPLR3GalimovView, CScrollView)

BEGIN_MESSAGE_MAP(COOPLR3GalimovView, CScrollView)
END_MESSAGE_MAP()

// COOPLR3GalimovView construction/destruction

COOPLR3GalimovView::COOPLR3GalimovView() noexcept
{
	// TODO: add construction code here

}

COOPLR3GalimovView::~COOPLR3GalimovView()
{
}

BOOL COOPLR3GalimovView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// COOPLR3GalimovView drawing

void COOPLR3GalimovView::OnDraw(CDC* /*pDC*/)
{
	COOPLR3GalimovDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void COOPLR3GalimovView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// COOPLR3GalimovView diagnostics

#ifdef _DEBUG
void COOPLR3GalimovView::AssertValid() const
{
	CScrollView::AssertValid();
}

void COOPLR3GalimovView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

COOPLR3GalimovDoc* COOPLR3GalimovView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COOPLR3GalimovDoc)));
	return (COOPLR3GalimovDoc*)m_pDocument;
}
#endif //_DEBUG


// COOPLR3GalimovView message handlers
