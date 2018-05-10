// Tool.cpp : CTool 的实现

#include "stdafx.h"
#include "Tool.h"
#include "tlhelp32.h"

// CTool



STDMETHODIMP CTool::ProcessSnapshot(void)
{
	
	m_hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	return S_OK;
}


STDMETHODIMP CTool::ProcessFirst(LONG* pnID, BYTE* pszName)
{
	// TODO: 在此添加实现代码
	 PROCESSENTRY32 pe = {0};
	 pe.dwSize = sizeof(pe);

	 if(TRUE != Process32First(m_hProcess, &pe))
	 {
		 return E_FAIL;
	 }

	 *pnID = pe.th32ProcessID;
	 wcscpy((TCHAR*)pszName, pe.szExeFile);
	 
	return S_OK;
}


STDMETHODIMP CTool::ProcessNext(LONG* pnID, BYTE* pszName)
{
	// TODO: 在此添加实现代码
	PROCESSENTRY32 pe = {0};
	pe.dwSize = sizeof(pe);

	if(TRUE != Process32Next(m_hProcess, &pe))
	{
		return E_FAIL;
	}

	*pnID = pe.th32ProcessID;
	wcscpy((TCHAR*)pszName, pe.szExeFile);
	return S_OK;
}


STDMETHODIMP CTool::ThreadSnapshot(void)
{
	// TODO: 在此添加实现代码
	m_hThread = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);
	return S_OK;
}


STDMETHODIMP CTool::ThreadFirst(LONG* pnID, LONG* pnProcID)
{
	// TODO: 在此添加实现代码
	THREADENTRY32 te = {0};
	te.dwSize = sizeof(te);
	if(TRUE != Thread32First(m_hThread, &te))
	{
		return E_FAIL;
	}

	*pnID = te.th32ThreadID;
	*pnProcID = te.th32OwnerProcessID;
	return S_OK;
}


STDMETHODIMP CTool::ThreadNext(LONG* pnID, LONG* pnProcID)
{
	// TODO: 在此添加实现代码
	THREADENTRY32 te = {0};
	te.dwSize = sizeof(te);
	if(TRUE != Thread32Next(m_hThread, &te))
	{
		return E_FAIL;
	}

	*pnID = te.th32ThreadID;
	*pnProcID = te.th32OwnerProcessID;
	return S_OK;
}
