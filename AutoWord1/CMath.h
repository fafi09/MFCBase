// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\project\\Com\\ATLCalc\\bin\\AutoDll1.dll" no_namespace
// CMath ��װ��

class CMath : public COleDispatchDriver
{
public:
	CMath(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CMath(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMath(const CMath& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IMath ����
public:
	void Sub(long nSub1, long nSub2, long * pnSub)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_PI4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, nSub1, nSub2, pnSub);
	}

	// IMath ����
public:

};
