// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\project\\Com\\ATLCalc\\bin\\ATLDisp.dll" no_namespace
// CFruit ��װ��

class CFruit : public COleDispatchDriver
{
public:
	CFruit(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CFruit(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFruit(const CFruit& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IFruit ����
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

	// IFruit ����
public:

};
