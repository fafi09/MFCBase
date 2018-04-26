// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\project\\Com\\ATLCalc\\bin\\ATLDisp.dll" no_namespace
// CFruit 包装类

class CFruit : public COleDispatchDriver
{
public:
	CFruit(){} // 调用 COleDispatchDriver 默认构造函数
	CFruit(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFruit(const CFruit& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IFruit 方法
public:
	void Add(long nAdd1, long nAdd2, long * pnAdd)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nAdd1, nAdd2, pnAdd);
	}
	long get_eye()
	{
		long result;
		InvokeHelper(0x4, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_eye(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void ShowMsg()
	{
		InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IFruit 属性
public:

};
