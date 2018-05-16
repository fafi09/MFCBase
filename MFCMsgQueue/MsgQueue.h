#pragma once

#include <afxmt.h>

class CMsgQueue
{
public:
	CMsgQueue(void);
	virtual ~CMsgQueue(void);
	// 初始化队列
	BOOL InitQueue(UINT32 nUnitCount, UINT32 nUnitLen);
	// 将数据放入队列
	BOOL Push(LPVOID pData);
//	BOOL Pop(void);
	BOOL Pop(LPVOID pData);
	//存放数据
	BYTE* m_pUnitData;
	//单元个数
	UINT32 m_nUnitCount;
	//单元长度
	UINT32 m_nUnitLen;
	//开始单元
	UINT32 m_nBeginUnit;
	//结束单元
	UINT32 m_nEndUnit;
	//push的信号量
	CSemaphore* m_pPushSemaphore;
	//pop的信号量
	CSemaphore* m_pPopSemaphore;
};

