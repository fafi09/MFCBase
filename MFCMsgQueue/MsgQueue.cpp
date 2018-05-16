#include "StdAfx.h"
#include "MsgQueue.h"


CMsgQueue::CMsgQueue(void)
{
}


CMsgQueue::~CMsgQueue(void)
{
}


// 初始化队列
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


// 将数据放入队列
BOOL CMsgQueue::Push(LPVOID pData)
{
	//多线程访问增加临界区

	//减少push的信号量
	m_pPushSemaphore->Lock();

	//计算当前可以存放数据的地址
	BYTE* pTmpData = m_pUnitData + m_nUnitLen * m_nEndUnit;

	m_nEndUnit++;
	if(m_nEndUnit >= m_nUnitCount)
		m_nEndUnit = 0;

	memcpy(pTmpData, pData, m_nUnitLen);

	//增加pop的信号量
	m_pPopSemaphore->Unlock();

	//增加临界区

	return TRUE;
}


// 从队列取出数据


BOOL CMsgQueue::Pop(LPVOID pData)
{
	//多线程访问增加临界区

	//减少pop的信号量
	m_pPopSemaphore->Lock();

	//计算当前可以获取数据的地址
	BYTE* pTmpData = m_pUnitData + m_nUnitLen * m_nBeginUnit;

	m_nBeginUnit++;
	if(m_nBeginUnit >= m_nUnitCount)
		m_nBeginUnit = 0;

	memcpy(pData, pTmpData, m_nUnitLen);

	//增加push的信号量
	m_pPushSemaphore->Unlock();


	//增加临界区

	return TRUE;
}
