#pragma once
#include"afxwin.h"
#include"afxpropertygridctrl.h"
#include"CPicture.h"
class CPictureShow : public CMFCPropertyGridCtrl
{
	public:
		CPictureShow();
	public:
		CPicture	m_pic;										//��ʾͼƬ

	public:
		virtual void OnDrawDescription(CDC* pDC, CRect rect);//����������ͼ
		virtual void OnDraw(CDC*pDC, CRect rect);

		/*BOOL AddSubItem(CMFCPropertyGridProperty* pProp);
		BOOL RemoveSubItem(CMFCPropertyGridProperty*& pProp, BOOL bDelete = TRUE);
		BOOL AddOption(LPCTSTR lpszOption, BOOL bInsertUnique = TRUE);*/

};