
// OOP_LR3_GalimovDoc.h : interface of the COOPLR3GalimovDoc class
//


#pragma once
#include "Store_Galimov.h"

class COOPLR3GalimovDoc : public CDocument
{
protected: // create from serialization only
	COOPLR3GalimovDoc() noexcept;
	DECLARE_DYNCREATE(COOPLR3GalimovDoc)

// Attributes
public:
	Store st;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~COOPLR3GalimovDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
