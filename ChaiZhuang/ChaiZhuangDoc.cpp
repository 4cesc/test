
// ChaiZhuangDoc.cpp : CChaiZhuangDoc ���ʵ��
//

#include "stdafx.h"
#include"PropertiesWnd.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ChaiZhuang.h"
#endif

#include "ChaiZhuangDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChaiZhuangDoc

IMPLEMENT_DYNCREATE(CChaiZhuangDoc, CDocument)

BEGIN_MESSAGE_MAP(CChaiZhuangDoc, CDocument)
END_MESSAGE_MAP()


// CChaiZhuangDoc ����/����

CChaiZhuangDoc::CChaiZhuangDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CChaiZhuangDoc::~CChaiZhuangDoc()
{
}

BOOL CChaiZhuangDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}
/*BOOL CChaiZhuangDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CPropertiesWnd *cp=new CPropertiesWnd();
	return cp->m_pic.LoadPictureFromFile(lpszPathName);
}*/




// CChaiZhuangDoc ���л�

void CChaiZhuangDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CChaiZhuangDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CChaiZhuangDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CChaiZhuangDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CChaiZhuangDoc ���

#ifdef _DEBUG
void CChaiZhuangDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChaiZhuangDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CChaiZhuangDoc ����
