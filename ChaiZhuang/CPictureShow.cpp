
#include"stdafx.h"
#include"CPictureShow.h"
CPictureShow::CPictureShow(){}
void CPictureShow::OnDraw(CDC*pDC ,CRect rect)
{
	CString path("C:/Users/Fabregas/Desktop/3.bmp");
	m_pic.LoadPictureFromFile(path);
	CSize sz=m_pic.GetSize();
	m_pic.Draw(pDC,0,400,sz.cx,sz.cy,0,0,sz.cx,sz.cy);

	/*CChaiZhuangView* ch=new CChaiZhuangView();
	CChaiZhuangDoc*pDoc=ch->GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->m_pic.Draw(pDC,0,0,rect.right-rect.left,rect.bottom-rect.top,0,0,rect.right-rect.left,rect.bottom-rect.top);*/

}
void CPictureShow::OnDrawDescription(CDC* pDC, CRect rect)
{
	OnDraw(pDC,rect);
}
