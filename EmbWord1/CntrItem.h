
// CntrItem.h : CEmbWord1CntrItem 类的接口
//

#pragma once

class CEmbWord1Doc;
class CEmbWord1View;

class CEmbWord1CntrItem : public COleClientItem
{
	DECLARE_SERIAL(CEmbWord1CntrItem)

// 构造函数
public:
	CEmbWord1CntrItem(CEmbWord1Doc* pContainer = NULL);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。OLE 项通常是用
		//  非 NULL 文档指针构造的

// 特性
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

// 实现
public:
	~CEmbWord1CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
	IDispatch* GetDispatch(void);
};

