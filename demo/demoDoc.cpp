// demoDoc.cpp : implementation of the CdemoDoc class
//

#include "stdafx.h"
#include "demo.h"

#include "demoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdemoDoc

IMPLEMENT_DYNCREATE(CdemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CdemoDoc, CDocument)
END_MESSAGE_MAP()


// CdemoDoc construction/destruction

CdemoDoc::CdemoDoc()
{
	// TODO: add one-time construction code here

}

CdemoDoc::~CdemoDoc()
{
}

BOOL CdemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CdemoDoc serialization

void CdemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CdemoDoc diagnostics

#ifdef _DEBUG
void CdemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CdemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CdemoDoc commands
