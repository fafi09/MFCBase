#ifndef _MSGBINDING_H_
#define _MSGBINDING_H_

#include "AdoRecordBindingEx.h"

class CMsgBinding : public CADORecordBinding
{
public:
	BEGIN_ADO_BINDING(CMsgBinding)
		ADO_VARIABLE_LENGTH_ENTRY2(1,adVarChar, m_szMsgID, sizeof(m_szMsgID), m_nMsgID, true)
		ADO_VARIABLE_LENGTH_ENTRY2(2,adVarChar, m_szSender, sizeof(m_szSender), m_nSender, true)
		ADO_VARIABLE_LENGTH_ENTRY2(3,adVarChar, m_szReceiver, sizeof(m_szReceiver), m_nReceiver, true)
	END_ADO_BINDING()
public:
	TCHAR m_szMsgID[256];
	long m_nMsgID;
	TCHAR m_szSender[256];
	long m_nSender;
	TCHAR m_szReceiver[256];
	long m_nReceiver;
};

class CMsgBindingEx : public CAdoRecordBindingEx
{
public:
	BEGIN_ADO_BINDING(CMsgBindingEx)
		ADO_VARIABLE_LENGTH_ENTRY2(1,adVarChar, m_szMsgID, sizeof(m_szMsgID), m_nMsgID, true)
		ADO_VARIABLE_LENGTH_ENTRY2(2,adVarChar, m_szSender, sizeof(m_szSender), m_nSender, true)
		ADO_VARIABLE_LENGTH_ENTRY2(3,adVarChar, m_szReceiver, sizeof(m_szReceiver), m_nReceiver, true)
		END_ADO_BINDING()
public:
	TCHAR m_szMsgID[256];
	long m_nMsgID;
	TCHAR m_szSender[256];
	long m_nSender;
	TCHAR m_szReceiver[256];
	long m_nReceiver;
};


#endif //_MSGBINDING_H_
