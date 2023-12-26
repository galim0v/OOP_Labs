
// OOP_LR4_GalimovView.h : interface of the COOPLR4GalimovView class
//

#pragma once


class COOPLR4GalimovView : public CScrollView
{
protected: // create from serialization only
	COOPLR4GalimovView() noexcept;
	DECLARE_DYNCREATE(COOPLR4GalimovView)

// Attributes
public:
	COOPLR4GalimovDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~COOPLR4GalimovView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditMenu();
};

#ifndef _DEBUG  // debug version in OOP_LR4_GalimovView.cpp
inline COOPLR4GalimovDoc* COOPLR4GalimovView::GetDocument() const
   { return reinterpret_cast<COOPLR4GalimovDoc*>(m_pDocument); }
#endif

