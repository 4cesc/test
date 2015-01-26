
#include"stdafx.h"
#include"CMyPropertiesWnd.h"
CMyPropertiesWnd::CMyPropertiesWnd(){}
void CMyPropertiesWnd::OnDraw(CDC*pDC ,CRect rect)
{
	CString path("C:/Users/Fabregas/Desktop/1.bmp");
	CMFCPropertyGridProperty *m_pSel=GetCurSel();
	//MessageBox((m_pSel->GetDescription()));
	if(m_pSel->GetDescription()=="1")
		path="C:/Users/Fabregas/Desktop/1.bmp";
	else if(m_pSel->GetDescription()=="2")
		 path="C:/Users/Fabregas/Desktop/2.bmp";
	else if(m_pSel->GetDescription()=="3")
		path="C:/Users/Fabregas/Desktop/3.bmp";
	else if(m_pSel->GetDescription()=="4")
		path="C:/Users/Fabregas/Desktop/4.bmp";
	else if(m_pSel->GetDescription()=="5")
		path="C:/Users/Fabregas/Desktop/5.bmp";
	/*if(m_pSel->GetName()==_T("组件库"))
		 path=("C:/Users/Fabregas/Desktop/2.bmp");
	/*if(m_pSel->m_strName=="其他工具")
		 path=("C:/Users/Fabregas/Desktop/2.bmp");*/
	m_pic.LoadPictureFromFile(path);
	CSize sz=m_pic.GetSize();
	int m_nDescrHeight=GetDescriptionHeight();
	//int m_nDescrRows=GetDescriptionRows();
	//int width=GetPropertyColumnWidth();
	//int m_nRowHeight=GetRowHeight();
	m_pic.Draw(pDC,20,rect.top+20,rect.right-rect.left-40,m_nDescrHeight-20,0,0,sz.cx,sz.cy);

	/*CChaiZhuangView* ch=new CChaiZhuangView();
	CChaiZhuangDoc*pDoc=ch->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_pic.Draw(pDC,0,0,rect.right-rect.left,rect.bottom-rect.top,0,0,rect.right-rect.left,rect.bottom-rect.top);*/

}
void CMyPropertiesWnd::OnDrawDescription(CDC* pDC, CRect rect)
{
	OnDraw(pDC,rect);
}
