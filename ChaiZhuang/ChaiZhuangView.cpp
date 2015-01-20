
// ChaiZhuangView.cpp : CChaiZhuangView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChaiZhuangView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CChaiZhuangView 构造/析构

CChaiZhuangView::CChaiZhuangView()
{
	// TODO: 在此处添加构造代码

}

CChaiZhuangView::~CChaiZhuangView()
{
}

BOOL CChaiZhuangView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CChaiZhuangView 绘制

void CChaiZhuangView::OnDraw(CDC* /*pDC*/)
{
	CChaiZhuangDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CChaiZhuangView 打印


void CChaiZhuangView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChaiZhuangView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CChaiZhuangView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CChaiZhuangView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CChaiZhuangView 诊断

#ifdef _DEBUG
void CChaiZhuangView::AssertValid() const
{
	CView::AssertValid();
}

void CChaiZhuangView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChaiZhuangDoc* CChaiZhuangView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChaiZhuangDoc)));
	return (CChaiZhuangDoc*)m_pDocument;
}
#endif //_DEBUG


// CChaiZhuangView 消息处理程序
