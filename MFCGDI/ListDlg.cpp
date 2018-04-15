// ListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "ListDlg.h"
#include "afxdialogex.h"


// CListDlg �Ի���

IMPLEMENT_DYNAMIC(CListDlg, CDialog)

CListDlg::CListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListDlg::IDD, pParent)
{

}

CListDlg::~CListDlg()
{
}

void CListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_wndCombo);
	DDX_Control(pDX, IDC_LIST, m_wndList);
}


BEGIN_MESSAGE_MAP(CListDlg, CDialog)
//	ON_COMMAND(ID_LIST_DLG, &CListDlg::OnListDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CListDlg::OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_ORDER, &CListDlg::OnClickedOrder)
	ON_BN_CLICKED(IDC_DEL, &CListDlg::OnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CListDlg::OnDblclkList)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST, &CListDlg::OnEndlabeleditList)
END_MESSAGE_MAP()


// CListDlg ��Ϣ�������


//void CListDlg::OnListDlg()
//{
//	// TODO: �ڴ���������������
//}


void CListDlg::InitListCtrl(void)
{
	m_imgNormal.Create(MAKEINTRESOURCE(IDB_BITMAP3), 48, 48, RGB(0,0,0));
	m_imgSmall.Create(MAKEINTRESOURCE(IDB_BITMAP4), 16, 16, RGB(0, 0, 0));
	m_wndList.SetImageList(&m_imgNormal, LVSIL_NORMAL);
	m_wndList.SetImageList(&m_imgSmall, LVSIL_SMALL);

	m_wndList.InsertColumn( 0, TEXT("����"), LVCFMT_LEFT, 150 );
	m_wndList.InsertColumn( 1, TEXT("����"), LVCFMT_LEFT, 150 );

	m_wndCombo.SetCurSel(0);
}


void CListDlg::ShowList(void)
{
	CFileFind finder;
	CString strPath = TEXT("D:\\*.*");
	BOOL bFind = finder.FindFile(strPath);
	while(bFind)
	{
		bFind = finder.FindNextFileW();
		if(finder.IsDirectory())
		{
			m_wndList.InsertItem(0, finder.GetFileName(), 0);
		}
		else
		{
			int nItem = m_wndList.InsertItem(0, finder.GetFileName(), 1);
			DWORD dwLen = finder.GetLength();
			CString strLen;
			strLen.Format(TEXT("%d"), dwLen);
			m_wndList.SetItemText(nItem, 1, strLen);

			//Ϊ��������
			LVITEM item = {0};
			item.mask = LVIF_PARAM;
			item.iItem = nItem;
			item.lParam = 1;
			m_wndList.SetItem(&item);
		}
	}

	finder.Close();
}


BOOL CListDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitListCtrl();
	ShowList();


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CListDlg::OnSelchangeCombo1()
{
	int nSel = m_wndCombo.GetCurSel();
	switch(nSel)
	{
	case 0:
		m_wndList.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_REPORT, LVS_ICON);
		break;
	case 1:
		m_wndList.ModifyStyle(LVS_SMALLICON | LVS_ICON | LVS_REPORT, LVS_LIST);
		break;
	case 2:
		m_wndList.ModifyStyle( LVS_ICON | LVS_LIST | LVS_REPORT, LVS_SMALLICON);
		break;
	case 3:
		m_wndList.ModifyStyle(LVS_SMALLICON | LVS_LIST | LVS_ICON, LVS_REPORT);
		break;
	}
}

int CALLBACK 
	MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	return lParam1 > lParam2;
}

void CListDlg::OnClickedOrder()
{
	m_wndList.SortItems(MyCompareProc, 0);
}


void CListDlg::OnClickedDel()
{
	//��ȡ��ǰҪѡ�����
	int nItem = m_wndList.GetNextItem(-1, LVNI_SELECTED );
	if( nItem == -1 )
	{
		AfxMessageBox(TEXT("��Ҫѡ��ɾ������"));
		return;
	}
	m_wndList.DeleteItem(nItem);
	//��������
	m_wndList.Arrange(LVA_DEFAULT);

}


void CListDlg::OnDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strText = m_wndList.GetItemText(pNMItemActivate->iItem, 0);
	AfxMessageBox(strText);
	*pResult = 0;
}


void CListDlg::OnEndlabeleditList(NMHDR *pNMHDR, LRESULT *pResult)
{
	NMLVDISPINFO *pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_wndList.SetItemText(pDispInfo->item.iItem, 0, pDispInfo->item.pszText);

	*pResult = 0;
}
