// demoDoc.h : interface of the CdemoDoc class
//


#pragma once


class CdemoDoc : public CDocument
{
protected: // create from serialization only
	CdemoDoc();
	DECLARE_DYNCREATE(CdemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CdemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


