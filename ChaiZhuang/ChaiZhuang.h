
// ChaiZhuang.h : ChaiZhuang Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������

extern CString  g_strCurProcessDir;//Ӧ�ó���(.exe)�ڴ����ϵ�Ŀ¼
// CChaiZhuangApp:
// �йش����ʵ�֣������ ChaiZhuang.cpp
//

class CChaiZhuangApp : public CWinAppEx
{
public:
	CChaiZhuangApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
private:
	CString GetProcessDir(void);
};

extern CChaiZhuangApp theApp;
