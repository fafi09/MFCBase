
// CntrItem.h : CEmbWord1CntrItem ��Ľӿ�
//

#pragma once

class CEmbWord1Doc;
class CEmbWord1View;

class CEmbWord1CntrItem : public COleClientItem
{
	DECLARE_SERIAL(CEmbWord1CntrItem)

// ���캯��
public:
	CEmbWord1CntrItem(CEmbWord1Doc* pContainer = NULL);
		// ע��: ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	CEmbWord1Doc* GetDocument()
		{ return reinterpret_cast<CEmbWord1Doc*>(COleClientItem::GetDocument()); }
	CEmbWord1View* GetActiveView()
		{ return reinterpret_cast<CEmbWord1View*>(COleClientItem::GetActiveView()); }

public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();

protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	virtual BOOL OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);

// ʵ��
public:
	~CEmbWord1CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
	IDispatch* GetDispatch(void);
};

