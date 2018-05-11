
// DBDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DBDemo.h"
#include "DBDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CDBDemoDlg 对话框




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


// CDBDemoDlg 消息处理程序

BOOL CDBDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDBDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDBDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "TBL_MSG.h"
void CDBDemoDlg::OnClickedBindOdbc()
{
	// TODO: 在此添加控件通知处理程序代码
	CTBL_MSG set;
	set.Open();

	AfxMessageBox(set.m_MSG_ID+ ":"+set.m_MSG_CONTENT);

	set.MoveFirst();
	AfxMessageBox(set.m_MSG_ID+ ":"+set.m_MSG_CONTENT);
}

#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace 				rename("EOF","adoEOF")
void CDBDemoDlg::OnClickedShowAdo()
{
	// TODO: 在此添加控件通知处理程序代码
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordset;
	try
	{
		//创建Connection接口
		HRESULT nRet=pConnection.CreateInstance(
			_uuidof(Connection));
		if(FAILED(nRet))
		{
			return ;
		}
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
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
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
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
	// TODO: 在此添加控件通知处理程序代码
	CDatabase db;
	if(TRUE != db.Open(TEXT("TEST")))
	{
		AfxMessageBox(TEXT("打开数据源失败"));
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
