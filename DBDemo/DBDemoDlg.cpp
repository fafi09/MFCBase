
// DBDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DBDemo.h"
#include "DBDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDBDemoDlg �Ի���




CDBDemoDlg::CDBDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDBDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDBDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_wndDatas);
}

BEGIN_MESSAGE_MAP(CDBDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BIND_ODBC, &CDBDemoDlg::OnClickedBindOdbc)
	ON_BN_CLICKED(IDC_SHOW_ADO, &CDBDemoDlg::OnClickedShowAdo)
	ON_BN_CLICKED(IDC_SHOW_ODBC, &CDBDemoDlg::OnClickedShowOdbc)
END_MESSAGE_MAP()


// CDBDemoDlg ��Ϣ�������

BOOL CDBDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDBDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDBDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDBDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "TBL_MSG.h"
void CDBDemoDlg::OnClickedBindOdbc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTBL_MSG set;
	set.Open();

	AfxMessageBox(set.m_MSG_ID+ ":"+set.m_MSG_CONTENT);

	set.MoveFirst();
	AfxMessageBox(set.m_MSG_ID+ ":"+set.m_MSG_CONTENT);
}

#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace 				rename("EOF","adoEOF")
void CDBDemoDlg::OnClickedShowAdo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordset;
	try
	{
		//����Connection�ӿ�
		HRESULT nRet=pConnection.CreateInstance(
			_uuidof(Connection));
		if(FAILED(nRet))
		{
			return ;
		}
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
		nRet=pConnection->Open(_bstr_t(strConn),
			"","",adConnectUnspecified);
		if(FAILED(nRet))
			return ;


		pRecordset.CreateInstance(_uuidof(Recordset));

		pRecordset->Open(_bstr_t(TEXT("TBL_MSG")),(IDispatch*)pConnection,
			adOpenKeyset,adLockOptimistic,adCmdTable);

		FieldsPtr _Field = pRecordset->GetFields();
		LONG cnt = _Field->GetCount();

		

		for(short i = 0; i < cnt; i++)
		{
			VARIANT var;
			var.vt = VT_I4;
			var.lVal = i;
			FieldPtr _Fd = _Field->GetItem(var);
			m_wndDatas.InsertColumn(i, _Fd->GetName() , LVCFMT_LEFT,100);
		}

		int nItem = 0;
		while(!pRecordset->adoEOF)
		{
			for(int i = 0; i < cnt; i++)
			{
				CString strValue;
				strValue = pRecordset->GetCollect(_variant_t(long(i)));
				//strValue = pRecordset->GetCollect(_variant_t(i));
				if(i == 0 )
				{
					nItem = m_wndDatas.GetItemCount();
					nItem = m_wndDatas.InsertItem(nItem, strValue);
				}
				else
				{
					m_wndDatas.SetItemText(nItem, i, strValue);
				}
			}
			pRecordset->MoveNext();
		}
	}

	catch(...)
	{
		CString err;
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
		AfxMessageBox(err);
		if(pConnection!=NULL)
			pConnection->Close();
		return ;
	}

	pRecordset->Close();
	if(pConnection!=NULL)
		pConnection->Close();
}

#include <afxdb.h>
void CDBDemoDlg::OnClickedShowOdbc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDatabase db;
	if(TRUE != db.Open(TEXT("TEST")))
	{
		AfxMessageBox(TEXT("������Դʧ��"));
		return;
	}
	CRecordset set(&db);

	set.Open(CRecordset::forwardOnly, _T("select * from TBL_MSG "));

	short cnt = set.GetODBCFieldCount();

	CODBCFieldInfo info = {0};

	for(short i = 0; i < cnt; i++)
	{
		set.GetODBCFieldInfo(i, info);
		m_wndDatas.InsertColumn(i, info.m_strName, LVCFMT_LEFT,100);
	}
	
	int nItem = 0;
	while(!set.IsEOF())
	{
		for(int i = 0; i < cnt; i++)
		{
			CString strValue;
			set.GetFieldValue(i, strValue);

			if(i == 0 )
			{
				nItem = m_wndDatas.GetItemCount();
				nItem = m_wndDatas.InsertItem(nItem, strValue);
			}
			else
			{
				m_wndDatas.SetItemText(nItem, i, strValue);
			}
		}
		set.MoveNext();
	}

	set.Close();
	db.Close();
}
