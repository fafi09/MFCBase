// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装类

#import "D:\\project\\Com\\ATLCalc\\bin\\AutoDll1.dll" no_namespace
// CMath 包装类

class CMath : public COleDispatchDriver
{
public:
	CMath(){} // 调用 COleDispatchDriver 默认构造函数
	CMath(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMath(const CMath& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IMath 方法
public:
	void Sub(long nSub1, long nSub2, long * pnSub)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSub1, nSub2, pnSub);
	}

	// IMath 属性
public:

};
