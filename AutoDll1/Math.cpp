// Math.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoDll1.h"
#include "Math.h"


// CMath

IMPLEMENT_DYNCREATE(CMath, CCmdTarget)


CMath::CMath()
{
	EnableAutomation();
	
	// Ϊ��ʹӦ�ó����� OLE �Զ��������ڻ״̬ʱ����
	//	���У����캯������ AfxOleLockApp��
	
	AfxOleLockApp();
}

CMath::~CMath()
{
	// Ϊ������ OLE �Զ����������ж������ֹӦ�ó���
	// 	������������ AfxOleUnlockApp��
	
	AfxOleUnlockApp();
}


void CMath::OnFinalRelease()
{
	// �ͷ��˶��Զ�����������һ�����ú󣬽�����
	// OnFinalRelease�����ཫ�Զ�
	// ɾ���ö����ڵ��øû���֮ǰ�����������
	// ��������ĸ���������롣

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CMath, CCmdTarget)
END_MESSAGE_MAP()


BEGIN_DISPATCH_MAP(CMath, CCmdTarget)
	DISP_FUNCTION_ID(CMath, "Sub", dispidSub, Sub, VT_EMPTY, VTS_I4 VTS_I4 VTS_PI4)
END_DISPATCH_MAP()

// ע��: ������� IID_IMath ֧��
//  ��֧������ VBA �����Ͱ�ȫ�󶨡��� IID ����ͬ���ӵ� .IDL �ļ��е�
//  ���Ƚӿڵ� GUID ƥ�䡣

// {AC39E5B6-F623-4066-81DD-438539CABEE0}
static const IID IID_IMath =
{ 0xAC39E5B6, 0xF623, 0x4066, { 0x81, 0xDD, 0x43, 0x85, 0x39, 0xCA, 0xBE, 0xE0 } };

BEGIN_INTERFACE_MAP(CMath, CCmdTarget)
	INTERFACE_PART(CMath, IID_IMath, Dispatch)
END_INTERFACE_MAP()

// {E8DF1F38-70BB-4150-9A32-CB2B15424E95}
IMPLEMENT_OLECREATE_FLAGS(CMath, "AutoDll1.Math", afxRegApartmentThreading, 0xe8df1f38, 0x70bb, 0x4150, 0x9a, 0x32, 0xcb, 0x2b, 0x15, 0x42, 0x4e, 0x95)


// CMath ��Ϣ�������


void CMath::Add(long nAdd1, long nAdd2, long* pnAdd)
{
	*pnAdd = nAdd1 + nAdd2;
}


void CMath::Sub(LONG nSub1, LONG nSub2, LONG* pnSub)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pnSub = nSub1 - nSub2;
}
