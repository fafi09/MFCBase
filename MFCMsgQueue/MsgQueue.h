#pragma once

#include <afxmt.h>

class CMsgQueue
{
public:
	CMsgQueue(void);
	virtual ~CMsgQueue(void);
	// ��ʼ������
	BOOL InitQueue(UINT32 nUnitCount, UINT32 nUnitLen);
	// �����ݷ������
	BOOL Push(LPVOID pData);
//	BOOL Pop(void);
	BOOL Pop(LPVOID pData);
	//�������
	BYTE* m_pUnitData;
	//��Ԫ����
	UINT32 m_nUnitCount;
	//��Ԫ����
	UINT32 m_nUnitLen;
	//��ʼ��Ԫ
	UINT32 m_nBeginUnit;
	//������Ԫ
	UINT32 m_nEndUnit;
	//push���ź���
	CSemaphore* m_pPushSemaphore;
	//pop���ź���
	CSemaphore* m_pPopSemaphore;
};

