
// ChaiZhuangView.cpp : CChaiZhuangView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ChaiZhuang.h"
#endif

#include "ChaiZhuangDoc.h"
#include "ChaiZhuangView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChaiZhuangView

IMPLEMENT_DYNCREATE(CChaiZhuangView, CView)

BEGIN_MESSAGE_MAP(CChaiZhuangView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChaiZhuangView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CChaiZhuangView ����/����

CChaiZhuangView::CChaiZhuangView()
{
	// TODO: �ڴ˴���ӹ������

}

CChaiZhuangView::~CChaiZhuangView()
{
}

BOOL CChaiZhuangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CChaiZhuangView ����

void CChaiZhuangView::OnDraw(CDC* /*pDC*/)
{
	CChaiZhuangDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CChaiZhuangView ��ӡ


void CChaiZhuangView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChaiZhuangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CChaiZhuangView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CChaiZhuangView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CChaiZhuangView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChaiZhuangView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChaiZhuangView ���

#ifdef _DEBUG
void CChaiZhuangView::AssertValid() const
{
	CView::AssertValid();
}

void CChaiZhuangView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChaiZhuangDoc* CChaiZhuangView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChaiZhuangDoc)));
	return (CChaiZhuangDoc*)m_pDocument;
}
#endif //_DEBUG


// CChaiZhuangView ��Ϣ�������
