
// ChaiZhuangView.h : CChaiZhuangView ��Ľӿ�
//

#pragma once


class CChaiZhuangView : public CView
{
	friend class CPictureShow;
protected: // �������л�����
	CChaiZhuangView();
	DECLARE_DYNCREATE(CChaiZhuangView)

// ����
public:
	CChaiZhuangDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CChaiZhuangView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ChaiZhuangView.cpp �еĵ��԰汾
inline CChaiZhuangDoc* CChaiZhuangView::GetDocument() const
   { return reinterpret_cast<CChaiZhuangDoc*>(m_pDocument); }
#endif

