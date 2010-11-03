// demoView.h : interface of the CdemoView class
//


#pragma once


class CdemoView : public CView
{
protected: // create from serialization only
	CdemoView();
	DECLARE_DYNCREATE(CdemoView)

// Attributes
public:
	CdemoDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CdemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

protected:
	typedef enum {
		LEFT,
		MIDDLE,
		RIGHT
	} MButtons;
	virtual void mouseClickMessageBox(MButtons button);
	virtual int isDrawingYourPicture(bool isFirst);

	bool drawYourPicture;
	float val;
	static const float DEFAULT_VAL;
public:
	afx_msg void OnMymenuPicture1();
	afx_msg void OnMymenuPicture2();
	afx_msg void OnUpdateMymenuPicture1(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMymenuPicture2(CCmdUI *pCmdUI);
	afx_msg void OnMymenuSetradius();
	afx_msg void OnMymenuSetvalue();
};

#ifndef _DEBUG  // debug version in demoView.cpp
inline CdemoDoc* CdemoView::GetDocument() const
   { return reinterpret_cast<CdemoDoc*>(m_pDocument); }
#endif

