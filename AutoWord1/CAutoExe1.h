// �����Ϳ������á�����ࡱ�����ļ�������ɵ� IDispatch ��װ��

#import "D:\\project\\Com\\ATLCalc\\bin\\AutoExe1.exe" no_namespace
// CAutoExe1 ��װ��

class CAutoExe1 : public COleDispatchDriver
{
public:
	CAutoExe1(){} // ���� COleDispatchDriver Ĭ�Ϲ��캯��
	CAutoExe1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAutoExe1(const CAutoExe1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IAutoExe1 ����
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

	// IAutoExe1 ����
public:

};
