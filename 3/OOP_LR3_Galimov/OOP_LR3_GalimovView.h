
// OOP_LR3_GalimovView.h : interface of the COOPLR3GalimovView class
//

#pragma once


class COOPLR3GalimovView : public CScrollView
{
protected: // create from serialization only
	COOPLR3GalimovView() noexcept;
	DECLARE_DYNCREATE(COOPLR3GalimovView)

// Attributes
public:
	COOPLR3GalimovDoc* GetDocument() const;

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
	virtual ~COOPLR3GalimovView();
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

#ifndef _DEBUG  // debug version in OOP_LR3_GalimovView.cpp
inline COOPLR3GalimovDoc* COOPLR3GalimovView::GetDocument() const
   { return reinterpret_cast<COOPLR3GalimovDoc*>(m_pDocument); }
#endif

