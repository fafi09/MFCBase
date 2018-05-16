#include "StdAfx.h"
#include "MsgQueue.h"


CMsgQueue::CMsgQueue(void)
{
}


CMsgQueue::~CMsgQueue(void)
{
}


// ��ʼ������
BOOL CMsgQueue::InitQueue(UINT32 nUnitCount, UINT32 nUnitLen)
{
	m_nUnitCount = nUnitCount;
	m_nUnitLen = nUnitLen;

	m_pUnitData = (BYTE*)malloc(m_nUnitCount*m_nUnitLen);
	memset(m_pUnitData, 0, m_nUnitCount* m_nUnitLen);

	m_nBeginUnit = 0;
	m_nEndUnit = 0;

	m_pPushSemaphore = new CSemaphore(nUnitCount, nUnitCount);
	m_pPopSemaphore = new CSemaphore(0, nUnitCount);

	return TRUE;
}


// �����ݷ������
BOOL CMsgQueue::Push(LPVOID pData)
{
	//���̷߳��������ٽ���

	//����push���ź���
	m_pPushSemaphore->Lock();

	//���㵱ǰ���Դ�����ݵĵ�ַ
	BYTE* pTmpData = m_pUnitData + m_nUnitLen * m_nEndUnit;

	m_nEndUnit++;
	if(m_nEndUnit >= m_nUnitCount)
		m_nEndUnit = 0;

	memcpy(pTmpData, pData, m_nUnitLen);

	//����pop���ź���
	m_pPopSemaphore->Unlock();

	//�����ٽ���

	return TRUE;
}


// �Ӷ���ȡ������


BOOL CMsgQueue::Pop(LPVOID pData)
{
	//���̷߳��������ٽ���

	//����pop���ź���
	m_pPopSemaphore->Lock();

	//���㵱ǰ���Ի�ȡ���ݵĵ�ַ
	BYTE* pTmpData = m_pUnitData + m_nUnitLen * m_nBeginUnit;

	m_nBeginUnit++;
	if(m_nBeginUnit >= m_nUnitCount)
		m_nBeginUnit = 0;

	memcpy(pData, pTmpData, m_nUnitLen);

	//����push���ź���
	m_pPushSemaphore->Unlock();


	//�����ٽ���

	return TRUE;
}
