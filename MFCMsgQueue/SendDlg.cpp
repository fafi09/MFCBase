// SendDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCMsgQueue.h"
#include "SendDlg.h"
#include "afxdialogex.h"
#include "MsgQueue.h"

// CSendDlg �Ի���

IMPLEMENT_DYNAMIC(CSendDlg, CDialog)

CSendDlg::CSendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendDlg::IDD, pParent)
{

}

CSendDlg::~CSendDlg()
{
}

void CSendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndSend);
}


BEGIN_MESSAGE_MAP(CSendDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_SEND, &CSendDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CSendDlg ��Ϣ�������


void CSendDlg::OnBnClickedBtnSend()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxBeginThread(SendThread, this);
}


UINT CSendDlg::SendThread(LPVOID pParam)
{
	CSendDlg* dlg = (CSendDlg*)pParam;
	TCHAR szText[] = TEXT("hello send");
	while(1)
	{
		dlg->m_pQueue->Push(szText);
		dlg->m_wndSend.AddString(szText);
		Sleep(1000);
	}
	return 0;
}
