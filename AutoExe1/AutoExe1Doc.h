
// AutoExe1Doc.h : CAutoExe1Doc ��Ľӿ�
//


#pragma once


class CAutoExe1Doc : public CDocument
{
protected: // �������л�����
	CAutoExe1Doc();
	DECLARE_DYNCREATE(CAutoExe1Doc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CAutoExe1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

	// ���ɵ� OLE ����ӳ�亯��

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	void SetVisible(SHORT bShow);

	enum 
	{
		dispidTypeText = 2L,
		dispidSetVisible = 1L
	};
	void TypeText(LPCTSTR pszText);
};
