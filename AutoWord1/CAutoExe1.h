// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\project\\Com\\ATLCalc\\bin\\AutoExe1.exe" no_namespace
// CAutoExe1 包装类

class CAutoExe1 : public COleDispatchDriver
{
public:
	CAutoExe1(){} // 调用 COleDispatchDriver 默认构造函数
	CAutoExe1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAutoExe1(const CAutoExe1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IAutoExe1 方法
public:
	void SetVisible(short bShow)
	{
		static BYTE parms[] = VTS_I2 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, bShow);
	}
	void TypeText(LPCTSTR pszText)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pszText);
	}

	// IAutoExe1 属性
public:

};
