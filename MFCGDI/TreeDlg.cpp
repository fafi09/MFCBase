// TreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCGDI.h"
#include "TreeDlg.h"
#include "afxdialogex.h"


// CTreeDlg �Ի���

IMPLEMENT_DYNAMIC(CTreeDlg, CDialog)

CTreeDlg::CTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreeDlg::IDD, pParent)
{

}

CTreeDlg::~CTreeDlg()
{
}

void CTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_wndTree);
}


BEGIN_MESSAGE_MAP(CTreeDlg, CDialog)
	ON_BN_CLICKED(IDC_TREE_DEL, &CTreeDlg::OnClickedTreeDel)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CTreeDlg::OnSelchangedTree1)
	ON_NOTIFY(TVN_ENDLABELEDIT, IDC_TREE1, &CTreeDlg::OnEndlabeleditTree1)
END_MESSAGE_MAP()


// CTreeDlg ��Ϣ�������


void CTreeDlg::OnClickedTreeDel()
{
	//��ȡ��ѡ��Ľڵ�
	HTREEITEM hSelTree = m_wndTree.GetSelectedItem();
	if( hSelTree == NULL )
	{
		AfxMessageBox(TEXT("��ѡ��ڵ�"));
		return;
	}
	//��ȡ�ڵ�����
	CString strText = m_wndTree.GetItemText(hSelTree);
	if(IDOK != AfxMessageBox(strText, MB_OKCANCEL))
	{
		return;
	}
	//�ж��Ƿ�����ӽڵ�
	if(m_wndTree.ItemHasChildren(hSelTree))
	{
		AfxMessageBox(TEXT("�ýڵ�����ӽڵ�"));
		return;
	}
	m_wndTree.DeleteItem(hSelTree);
}


BOOL CTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	InitTreeCtrl();
	ShowTree();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTreeDlg::InitTreeCtrl(void)
{
	m_imgNormal.Create(IDB_BITMAP5, 18, 2, 0);
	m_imgState.Create(IDB_BITMAP6, 18, 2, 0);

	m_wndTree.SetImageList( &m_imgNormal, TVSIL_NORMAL );
	m_wndTree.SetImageList( &m_imgState, TVSIL_STATE );

	m_wndTree.SetItemHeight(20);
}


void CTreeDlg::ShowTree(void)
{
	HTREEITEM hRoot = m_wndTree.InsertItem(TEXT("D:\\1"), 0, 1);
	CFileFind finder;
	BOOL bFind = finder.FindFile(TEXT("D:\\1\\*.*"));
	while(bFind)
	{
		bFind = finder.FindNextFileW();
		m_wndTree.InsertItem(finder.GetFileName(), 0, 1, hRoot);
	}
	finder.Close();
	//չ���ڵ�
	m_wndTree.Expand(hRoot, TVE_EXPAND);
}


void CTreeDlg::OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	CString strText = m_wndTree.GetItemText(pNMTreeView->itemNew.hItem);
	AfxMessageBox(strText);
}


void CTreeDlg::OnEndlabeleditTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTVDISPINFO pTVDispInfo = reinterpret_cast<LPNMTVDISPINFO>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	m_wndTree.SetItemText(pTVDispInfo->item.hItem, pTVDispInfo->item.pszText);
}
