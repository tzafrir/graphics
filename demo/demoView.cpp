// demoView.cpp : implementation of the CdemoView class
//

#include "stdafx.h"
#include "demo.h"
#include <math.h>

#include "demoDoc.h"
#include "demoView.h"

#include "HW0Dialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CdemoView::mouseClickMessageBox(MButtons button) {
	CString msg;
	switch (button) {
		case LEFT:
			msg = "Left";
			break;
		case MIDDLE:
			msg = "Middle";
			break;
		case RIGHT:
			msg = "Right";
			break;
	}
	msg += " button was pressed!";
	MessageBox(msg);
}

int CdemoView::isDrawingYourPicture(bool isFirst) {
	int result = drawYourPicture ? 0 : 1;
	if (!isFirst) {
		result = (result + 1) % 2;
	}
	return result;
}

// CdemoView

IMPLEMENT_DYNCREATE(CdemoView, CView)

BEGIN_MESSAGE_MAP(CdemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_MYMENU_PICTURE1, &CdemoView::OnMymenuPicture1)
	ON_COMMAND(ID_MYMENU_PICTURE2, &CdemoView::OnMymenuPicture2)
	ON_UPDATE_COMMAND_UI(ID_MYMENU_PICTURE1, &CdemoView::OnUpdateMymenuPicture1)
	ON_UPDATE_COMMAND_UI(ID_MYMENU_PICTURE2, &CdemoView::OnUpdateMymenuPicture2)
	ON_COMMAND(ID_MYMENU_SETVALUE, &CdemoView::OnMymenuSetvalue)
END_MESSAGE_MAP()

// CdemoView construction/destruction

CdemoView::CdemoView()
{
	drawYourPicture = false;
	val = DEFAULT_VAL;
}

CdemoView::~CdemoView()
{
}

BOOL CdemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdemoView drawing

void CdemoView::OnDraw(CDC* pDC)
{
	if (drawYourPicture) {
		for (int x = 0; x < 256; x++) {
			for (int y = 0; y < 256; y++) {
				double gray = 127 + 128*sin(((x-127.0)*(x-127.0)+(y-127.0)*(y-127.0))/val);
				pDC->SetPixel(x,y,RGB(gray,gray,gray));
			}
		}
	} else {
		// Course code.
		CPen *redPen = new CPen(PS_SOLID,10,RGB(255,0,0));
		pDC->SelectObject(redPen); pDC->MoveTo(CPoint(0,0));
		pDC->LineTo(CPoint(100,100));
		for(int i=0; i<500; i++) pDC->SetPixel(i,(i-250)*(i-250)/250,RGB(0,0,255));
		delete redPen;
	}
}

// CdemoView printing

BOOL CdemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CdemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CdemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CdemoView diagnostics

#ifdef _DEBUG
void CdemoView::AssertValid() const
{
	CView::AssertValid();
}

void CdemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdemoDoc* CdemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdemoDoc)));
	return (CdemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CdemoView message handlers

void CdemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mouseClickMessageBox(LEFT);
}

void CdemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	mouseClickMessageBox(RIGHT);
}

void CdemoView::OnMButtonDown(UINT nFlags, CPoint point)
{
	mouseClickMessageBox(MIDDLE);
}

void CdemoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString msg;
	if (nChar >= 'A' && nChar <= 'Z') {
		msg = (char)nChar;	
	} else {
		msg = "A key";
	}
	msg += " was pressed!";
	MessageBox(msg);	
}


void CdemoView::OnMymenuPicture1()
{
	drawYourPicture = false;
	Invalidate();
}

void CdemoView::OnMymenuPicture2()
{
	drawYourPicture = true;
	Invalidate();
}

void CdemoView::OnUpdateMymenuPicture1(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(isDrawingYourPicture(true));
}

void CdemoView::OnUpdateMymenuPicture2(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(isDrawingYourPicture(false));
}

const float CdemoView::DEFAULT_VAL = 128.0;
void CdemoView::OnMymenuSetvalue()
{
	HW0Dialog dlg(val);
	if (dlg.DoModal() == IDOK) {
		val = dlg.getVal();
		Invalidate();
	}
}
