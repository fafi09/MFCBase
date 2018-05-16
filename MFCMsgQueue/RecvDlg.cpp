// RecvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "RecvDlg.h"
#include "afxdialogex.h"
#include "MsgQueue.h"

// CRecvDlg �Ի���

IMPLEMENT_DYNAMIC(CRecvDlg, CDialog)

CRecvDlg::CRecvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecvDlg::IDD, pParent)
{

}

CRecvDlg::~CRecvDlg()
{
}

void CRecvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndData);
}


BEGIN_MESSAGE_MAP(CRecvDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_RECV, &CRecvDlg::OnBnClickedBtnRecv)
END_MESSAGE_MAP()


// CRecvDlg ��Ϣ�������


void CRecvDlg::OnBnClickedBtnRecv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxBeginThread(RecvThread,this);
}


UINT CRecvDlg::RecvThread(LPVOID pParam)
{
	CRecvDlg* pThis = (CRecvDlg*)pParam;
	while(1)
	{
		TCHAR szText[100] = {0};
		pThis->m_pQueue->Pop(szText);
		pThis->m_wndData.AddString(szText);
	}
	return 0;
}
