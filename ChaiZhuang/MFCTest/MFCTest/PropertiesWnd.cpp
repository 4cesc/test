
#include "stdafx.h"

#include "PropertiesWnd.h"
#include "Resource.h"
#include "MainFrm.h"
#include "MFCTest.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar

CPropertiesWnd::CPropertiesWnd()
{
	m_nComboHeight = 0;
}

CPropertiesWnd::~CPropertiesWnd()
{
}

BEGIN_MESSAGE_MAP(CPropertiesWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_EXPAND_ALL, OnExpandAllProperties)
	ON_UPDATE_COMMAND_UI(ID_EXPAND_ALL, OnUpdateExpandAllProperties)
	ON_COMMAND(ID_SORTPROPERTIES, OnSortProperties)
	ON_UPDATE_COMMAND_UI(ID_SORTPROPERTIES, OnUpdateSortProperties)
	ON_COMMAND(ID_PROPERTIES1, OnProperties1)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES1, OnUpdateProperties1)
	ON_COMMAND(ID_PROPERTIES2, OnProperties2)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES2, OnUpdateProperties2)
	ON_WM_SETFOCUS()
	ON_WM_SETTINGCHANGE()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourceViewBar 消息处理程序

void CPropertiesWnd::AdjustLayout()
{
	if (GetSafeHwnd () == NULL || (AfxGetMainWnd() != NULL && AfxGetMainWnd()->IsIconic()))
	{
		return;
	}

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndObjectCombo.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), m_nComboHeight, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top + m_nComboHeight, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndPropList.SetWindowPos(NULL, rectClient.left, rectClient.top + m_nComboHeight + cyTlb, rectClient.Width(), rectClient.Height() -(m_nComboHeight+cyTlb), SWP_NOACTIVATE | SWP_NOZORDER);
}

int CPropertiesWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// 创建组合:
	const DWORD dwViewStyle = WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST | WS_BORDER | CBS_SORT | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

	if (!m_wndObjectCombo.Create(dwViewStyle, rectDummy, this, 1))
	{
		TRACE0("未能创建属性组合 \n");
		return -1;      // 未能创建
	}
	m_wndObjectCombo.AddString(_T("教学模式"));
	m_wndObjectCombo.AddString(_T("实操模式"));
	m_wndObjectCombo.AddString(_T("结构爆炸"));
	m_wndObjectCombo.SetCurSel(0);

	CRect rectCombo;
	m_wndObjectCombo.GetClientRect (&rectCombo);

	m_nComboHeight = rectCombo.Height();

	if (!m_wndPropList.Create(WS_VISIBLE | WS_CHILD, rectDummy, this, 2))
	{
		TRACE0("未能创建属性网格\n");
		return -1;      // 未能创建
	}

	InitPropList();

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, IDR_PROPERTIES);
	m_wndToolBar.LoadToolBar(IDR_PROPERTIES, 0, 0, TRUE /* 已锁定*/);
	m_wndToolBar.CleanUpLockedImages();
	m_wndToolBar.LoadBitmap(theApp.m_bHiColorIcons ? IDB_PROPERTIES_HC : IDR_PROPERTIES, 0, 0, TRUE /* 锁定*/);

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() & ~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));
	m_wndToolBar.SetOwner(this);

	// 所有命令将通过此控件路由，而不是通过主框架路由:
	m_wndToolBar.SetRouteCommandsViaFrame(FALSE);

	AdjustLayout();
	return 0;
}

void CPropertiesWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout();
}

void CPropertiesWnd::OnExpandAllProperties()
{
	m_wndPropList.ExpandAll();
}

void CPropertiesWnd::OnUpdateExpandAllProperties(CCmdUI* /* pCmdUI */)
{
}

void CPropertiesWnd::OnSortProperties()
{
	m_wndPropList.SetAlphabeticMode(!m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnUpdateSortProperties(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_wndPropList.IsAlphabeticMode());
}

void CPropertiesWnd::OnProperties1()
{
	// TODO: 在此处添加命令处理程序代码
}

void CPropertiesWnd::OnUpdateProperties1(CCmdUI* /*pCmdUI*/)
{
	// TODO: 在此处添加命令更新 UI 处理程序代码
}

void CPropertiesWnd::OnProperties2()
{
	// TODO: 在此处添加命令处理程序代码
}

void CPropertiesWnd::OnUpdateProperties2(CCmdUI* /*pCmdUI*/)
{
	// TODO: 在此处添加命令更新 UI 处理程序代码
}

void CPropertiesWnd::InitPropList()
{
	SetPropListFont();

	m_wndPropList.EnableHeaderCtrl(FALSE);
	m_wndPropList.EnableDescriptionArea();
	m_wndPropList.SetVSDotNetLook();
	m_wndPropList.MarkModifiedProperties();

	CMFCPropertyGridProperty* pGroup1 = new CMFCPropertyGridProperty(_T("其他工具"));

	CMFCPropertyGridProperty* pProp=(new CMFCPropertyGridProperty(_T("呆扳手"),_T("8"), _T("IDB_INFO")));
	pProp->AddOption(_T("8"));
	pProp->AddOption(_T("9"));
	pProp->AddOption(_T("10"));
	pProp->AddOption(_T("11"));
	pProp->AddOption(_T("12"));
	pProp->AddOption(_T("13"));
	pProp->AddOption(_T("14"));
	pProp->AddOption(_T("15"));
	pProp->AddOption(_T("16"));
	pProp->AddOption(_T("17"));
	pProp->AddOption(_T("18"));
	pProp->AddOption(_T("19"));
	pProp->AddOption(_T("20"));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);

    pProp = new CMFCPropertyGridProperty(_T("内六角扳手"), _T("6"), _T("其中之一:“无”、“细”、“可调整大小”或“对话框外框”"));
	pProp->AddOption(_T("3"));
	pProp->AddOption(_T("4"));
	pProp->AddOption(_T("5"));
	pProp->AddOption(_T("5.5"));
	pProp->AddOption(_T("6"));
	pProp->AddOption(_T("8"));
	pProp->AddOption(_T("10"));
	pProp->AllowEdit(FALSE);

	pGroup1->AddSubItem(pProp);
	pProp =(new CMFCPropertyGridProperty(_T("锤子"), (_variant_t) _T("8"), _T("指定窗口标题栏中显示的文本")));
	pProp->AllowEdit(FALSE);
	pGroup1->AddSubItem(pProp);
	pGroup1->Expand(FALSE);
	

	CMFCPropertyGridProperty* pGroup2 = new CMFCPropertyGridProperty(_T("零件库"));
	pProp=(new CMFCPropertyGridProperty(_T("导套"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("导柱"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("模柄"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("冲针"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("挡料销"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("弹簧"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("上模座"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("弹压板"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凸模固定板"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凹模固定板"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("下模座"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凹模"),_T("1"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup2->AddSubItem(pProp);
	m_wndPropList.AddProperty(pGroup2);

	CMFCPropertyGridProperty* pGroup3 = new CMFCPropertyGridProperty(_T("连接件库"));
	pProp=(new CMFCPropertyGridProperty(_T("塞打螺丝M10*30"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup3->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("杯头螺丝M6*20"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup3->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("杯头螺丝M6*25"),_T("4"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup3->AddSubItem(pProp);
	pGroup3->Expand(FALSE);
	m_wndPropList.AddProperty(pGroup3);

	CMFCPropertyGridProperty* pGroup4 = new CMFCPropertyGridProperty(_T("组件库"));
	pProp=(new CMFCPropertyGridProperty(_T("上模座组件"),_T("0"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup4->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凸模组件"),_T("0"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup4->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凹模型芯组件"),_T("0"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup4->AddSubItem(pProp);
	pProp=(new CMFCPropertyGridProperty(_T("凹模组件"),_T("0"), _T("指定窗口的字体不使用粗体，并且控件将使用三维边框")));
	pProp->AllowEdit(FALSE);
	pGroup4->AddSubItem(pProp);

	pGroup4->Expand(FALSE);
	m_wndPropList.AddProperty(pGroup4);
	m_wndPropList.AddProperty(pGroup1);
}

void CPropertiesWnd::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndPropList.SetFocus();
}

void CPropertiesWnd::OnSettingChange(UINT uFlags, LPCTSTR lpszSection)
{
	CDockablePane::OnSettingChange(uFlags, lpszSection);
	SetPropListFont();
}

void CPropertiesWnd::SetPropListFont()
{
	::DeleteObject(m_fntPropList.Detach());

	LOGFONT lf;
	afxGlobalData.fontRegular.GetLogFont(&lf);

	NONCLIENTMETRICS info;
	info.cbSize = sizeof(info);

	afxGlobalData.GetNonClientMetrics(info);

	lf.lfHeight = info.lfMenuFont.lfHeight;
	lf.lfWeight = info.lfMenuFont.lfWeight;
	lf.lfItalic = info.lfMenuFont.lfItalic;

	m_fntPropList.CreateFontIndirect(&lf);

	m_wndPropList.SetFont(&m_fntPropList);
	m_wndObjectCombo.SetFont(&m_fntPropList);
}
