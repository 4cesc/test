
// ChaiZhuangDoc.h : CChaiZhuangDoc ��Ľӿ�
//


#pragma once

//#include"CPicture.h"
class CChaiZhuangDoc : public CDocument
{
protected: // �������л�����
	CChaiZhuangDoc();
	DECLARE_DYNCREATE(CChaiZhuangDoc)

// ����
public:
	//CPicture m_pic;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	//virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CChaiZhuangDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
