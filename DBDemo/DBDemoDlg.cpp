
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
	ON_BN_CLICKED(IDC_ADD_ADO, &CDBDemoDlg::OnClickedAddAdo)
	ON_BN_CLICKED(IDC_DEL_ADO, &CDBDemoDlg::OnClickedDelAdo)
	ON_BN_CLICKED(IDC_UPD_ADO, &CDBDemoDlg::OnClickedUpdAdo)
	ON_BN_CLICKED(IDC_BINARY_ADO, &CDBDemoDlg::OnBnClickedBinaryAdo)
	ON_BN_CLICKED(IDC_BIND_ADO, &CDBDemoDlg::OnBnClickedBindAdo)
	ON_BN_CLICKED(IDC_BIND_UPD_ADO, &CDBDemoDlg::OnBnClickedBindUpdAdo)
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


void CDBDemoDlg::OnClickedShowAdo()
{
	// TODO: 在此添加控件通知处理程序代码
	//AdoMethod1();
	//AdoMethod2();
	AdoMethod3();
}

void CDBDemoDlg::AdoMethod1(void)
{
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
				//strValue = pRecordset->GetCollect(_variant_t(i));  _variant_t(int)无这种转换方式会报错
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


void CDBDemoDlg::AdoMethod2(void)
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//浏览记录
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		long cnt = pRecordSet->Fields->GetCount();
		/*CString msg;
		msg.Format(TEXT("字段数:%ld"),cnt);
		AfxMessageBox(msg);*/

		for(int i = 0; i < cnt; i++)
		{
			CString _FiledName = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetName();
			m_wndDatas.InsertColumn(i,_FiledName, LVCFMT_LEFT, 100);

		}

		long rcordCnt = pRecordSet->GetRecordCount();
		/*CString msg;
		msg.Format(TEXT("记录数:%ld"),rcordCnt);
		AfxMessageBox(msg);*/

		int nItem = 0;
		while(!pRecordSet->GetadoEOF())
		{
			for(int i = 0; i < cnt; i++)
			{
				_variant_t value = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetValue();
				if( i == 0 )
				{
					if(value.vt == VT_BSTR)
					{
						CString strValue(value.bstrVal);
						//AfxMessageBox(strValue);
						nItem = m_wndDatas.GetItemCount();
						m_wndDatas.InsertItem(nItem,strValue);
					}
				}
				else
				{
					if(value.vt == VT_BSTR)
					{
						CString strValue(value.bstrVal);
						m_wndDatas.SetItemText(nItem, i, strValue);
					}
				}
				
			}
			pRecordSet->MoveNext();
		}


		pRecordSet->Close();
		pConnection->Close();
	}
	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();
	}
}


void CDBDemoDlg::AdoMethod3(void)
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;
	_CommandPtr pCommand;
	_ParameterPtr param1;

	m_wndDatas.DeleteAllItems();
	int nCount=m_wndDatas.GetHeaderCtrl()->GetItemCount();
	for(int nIndex=0;nIndex<nCount;nIndex++)
	{
		m_wndDatas.DeleteColumn(0);

	}

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pRecordSet.CreateInstance(_uuidof(Recordset));
		pCommand.CreateInstance(_uuidof(Command));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn),"","",adConnectUnspecified);

		TCHAR pszSql[] = TEXT("select * from TBL_MSG where MSG_ID > ? ");

		/*VARIANT var;
		var.vt = VT_BSTR;
		var.bstrVal = _bstr_t("3");*/

		pCommand->ActiveConnection = pConnection;

		pCommand->CommandText = _bstr_t(TEXT("update TBL_MSG set MSG_CONTENT = 'ccc' where MSG_ID = '3'"));

		pCommand->CommandType = adCmdText;

		pConnection->BeginTrans();

		pCommand->Execute(NULL,NULL,adCmdText | adExecuteNoRecords);

		if(IDOK == AfxMessageBox(TEXT("是否回滚？"), MB_OKCANCEL))
		{
			pConnection->RollbackTrans();
		}
		else
		{
			pConnection->CommitTrans();
		}
		


		pCommand->CommandText = _bstr_t("select * from TBL_MSG where MSG_ID > ? ");
		param1 = pCommand->CreateParameter(_bstr_t(""),adBSTR, adParamInput, -1, _variant_t("2"));
		//param1->Value = _variant_t("2");

		pCommand->Parameters->Append(param1);

		/*
		用Command和Connection对象的Execute方法得到的Recordset是只读的。
		因为在打开Recordset之前，我们无法设置它的LockType属性（其默认值为只读）。
		而在打开之后设置LockType不起作用
		我发现用上述方法得到记录集Rs1后，不但Rs1中的记录无法修改，即使直接用SQL语句修改同一表中任何记录都不行。
		*/
		pRecordSet = pCommand->Execute(NULL, NULL, adCmdText);
		//pRecordSet->Open((IDispatch*)pCommand, vtMissing, adOpenKeyset, adLockOptimistic, adCmdUnspecified);

		long cnt = pRecordSet->Fields->GetCount();
		/*CString msg;
		msg.Format(TEXT("字段数:%ld"),cnt);
		AfxMessageBox(msg);*/

		for(int i = 0; i < cnt; i++)
		{
			CString _FiledName = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetName();
			m_wndDatas.InsertColumn(i,_FiledName, LVCFMT_LEFT, 100);

		}

		long rcordCnt = pRecordSet->GetRecordCount();
		/*CString msg;
		msg.Format(TEXT("记录数:%ld"),rcordCnt);
		AfxMessageBox(msg);*/

		int nItem = 0;
		while(!pRecordSet->GetadoEOF())
		{
			for(int i = 0; i < cnt; i++)
			{
				_variant_t value = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetValue();
				if( i == 0 )
				{
					if(value.vt == VT_BSTR)
					{
						CString strValue(value.bstrVal);
						//AfxMessageBox(strValue);
						nItem = m_wndDatas.GetItemCount();
						m_wndDatas.InsertItem(nItem,strValue);
					}
				}
				else
				{
					if(value.vt == VT_BSTR)
					{
						CString strValue(value.bstrVal);
						m_wndDatas.SetItemText(nItem, i, strValue);
					}
				}
				
			}
			pRecordSet->MoveNext();
		}

		pRecordSet->Close();

		pConnection->Close();
	}
	catch(_com_error &e)
	{    
		// Notify the user of errors if any.
		// Pass a connection pointer accessed from the Recordset.
		_variant_t vtConnect = pRecordSet->GetActiveConnection();

		// GetActiveConnection returns connect string if connection
		// is not open, else returns Connection object.
		switch(vtConnect.vt)
		{
		case VT_BSTR:
			PrintComError(e);
			break;
		case VT_DISPATCH:
			PrintProviderError(vtConnect);
			break;
		default:
			wprintf(TEXT("Errors occured."));
			break;
		}
	}

	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();	
	}
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





void CDBDemoDlg::OnClickedAddAdo()
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pRecordSet.CreateInstance(_uuidof(Recordset));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn),"","",adConnectUnspecified);

		pRecordSet->Open(_T("TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdTable);

		if(!pRecordSet->Supports(adAddNew))
		{
			AfxMessageBox(TEXT("不支持addnew"));
			pConnection->Close();
			return ;
		}

		pRecordSet->AddNew();
		long cnt = pRecordSet->Fields->GetCount();

		for(long i = 0; i < cnt; i++)
		{
			CString strValue;
			strValue.Format(TEXT("%ld"), i+4);
			pRecordSet->Fields->GetItem(_variant_t(i))->Value = _variant_t(strValue);
		}

		if(!pRecordSet->Supports(adUpdate))
		{
			AfxMessageBox(TEXT("不支持adUpdate"));
			pConnection->Close();
			return ;
		}

		pRecordSet->Update();
		pRecordSet->Close();
		pConnection->Close();
	}
	catch(_com_error &e)
	{    
		// Notify the user of errors if any.
		// Pass a connection pointer accessed from the Recordset.
		_variant_t vtConnect = pRecordSet->GetActiveConnection();

		// GetActiveConnection returns connect string if connection
		// is not open, else returns Connection object.
		switch(vtConnect.vt)
		{
		case VT_BSTR:
			PrintComError(e);
			break;
		case VT_DISPATCH:
			PrintProviderError(vtConnect);
			break;
		default:
			wprintf(TEXT("Errors occured."));
			break;
		}
	}

	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();	
	}
}




void CDBDemoDlg::OnClickedDelAdo()
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pRecordSet.CreateInstance(_uuidof(Recordset));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn),"","",adConnectUnspecified);

		pRecordSet->Open(_T("TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdTable);

		

		while(!pRecordSet->GetadoEOF())
		{
			CString strMsgID = pRecordSet->Fields->GetItem(_variant_t(long(0)))->GetValue();
			if(strMsgID == "4")
			{
				pRecordSet->Delete(adAffectCurrent);
				break;
			}
			pRecordSet->MoveNext();
		}

		
		pRecordSet->Update();
		pRecordSet->Close();
		pConnection->Close();
	}
	catch(_com_error &e)
	{    
		// Notify the user of errors if any.
		// Pass a connection pointer accessed from the Recordset.
		_variant_t vtConnect = pRecordSet->GetActiveConnection();

		// GetActiveConnection returns connect string if connection
		// is not open, else returns Connection object.
		switch(vtConnect.vt)
		{
		case VT_BSTR:
			PrintComError(e);
			break;
		case VT_DISPATCH:
			PrintProviderError(vtConnect);
			break;
		default:
			wprintf(TEXT("Errors occured."));
			break;
		}
	}

	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();	
	}
}


void CDBDemoDlg::OnClickedUpdAdo()
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pRecordSet.CreateInstance(_uuidof(Recordset));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn),"","",adConnectUnspecified);

		pRecordSet->Open(_T("TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdTable);



		while(!pRecordSet->GetadoEOF())
		{
			CString strMsgID = pRecordSet->Fields->GetItem(_variant_t(long(0)))->GetValue();
			if(strMsgID == "4")
			{
				CString strValue = pRecordSet->Fields->GetItem(_variant_t(long(1)))->GetValue();
				pRecordSet->Fields->GetItem(_variant_t(long(1)))->Value = strValue+"p";
				break;
			}
			pRecordSet->MoveNext();
		}


		pRecordSet->Update();
		pRecordSet->Close();
		pConnection->Close();
	}
	catch(_com_error &e)
	{    
		// Notify the user of errors if any.
		// Pass a connection pointer accessed from the Recordset.
		_variant_t vtConnect = pRecordSet->GetActiveConnection();

		// GetActiveConnection returns connect string if connection
		// is not open, else returns Connection object.
		switch(vtConnect.vt)
		{
		case VT_BSTR:
			PrintComError(e);
			break;
		case VT_DISPATCH:
			PrintProviderError(vtConnect);
			break;
		default:
			wprintf(TEXT("Errors occured."));
			break;
		}
	}

	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();	
	}
}


void CDBDemoDlg::PrintProviderError(_ConnectionPtr pConnection)
{
	// Print Provider Errors from Connection object.
	// pErr is a record object in the Connection's Error collection.
	ErrorPtr    pErr  = NULL;

	if( (pConnection->Errors->Count) > 0)
	{
		long nCount = pConnection->Errors->Count;
		// Collection ranges from 0 to nCount -1.
		for(long i = 0; i < nCount; i++)
		{
			pErr = pConnection->Errors->GetItem(i);
			CString err;
			printf("Error number: %x\t%s\n", pErr->Number, 
				(LPCSTR) pErr->Description);
			err.Format(TEXT("Error number: %x\t%s\n"), pErr->Number, 
				(LPCTSTR) pErr->Description);
			AfxMessageBox(err);
		}
	}
}


void CDBDemoDlg::PrintComError(_com_error &e)
{

	_bstr_t bstrSource(e.Source());
	_bstr_t bstrDescription(e.Description());

	// Print Com errors.  
	printf("Error\n");
	printf("\tCode = %08lx\n", e.Error());
	printf("\tCode meaning = %s\n", e.ErrorMessage());
	printf("\tSource = %s\n", (LPCSTR) bstrSource);
	printf("\tDescription = %s\n", (LPCSTR) bstrDescription);
}



void CDBDemoDlg::OnBnClickedBinaryAdo()
{
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
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\project\\MFC\\MFC\\DBDemo\\19\\db\\ado.mdb"));
		//连接数据库
		nRet=pConnection->Open(_bstr_t(strConn),
			"","",adConnectUnspecified);
		if(FAILED(nRet))
			return ;


		pRecordset.CreateInstance(_uuidof(Recordset));

		pRecordset->Open(_bstr_t(TEXT("TBL_MSG")),(IDispatch*)pConnection,
			adOpenKeyset,adLockOptimistic,adCmdTable);


		TCHAR szText[]=TEXT("hello Binary");

		long size = wcslen(szText);

		SAFEARRAYBOUND rgsabound = {0};
		rgsabound.cElements = wcslen(szText);
		rgsabound.lLbound = 0;

		SAFEARRAY* pSafeArray = SafeArrayCreate(VT_UI1,1, &rgsabound);

		for(LONG nIndex = 0; nIndex < size; nIndex++)
		{
			SafeArrayPutElement(pSafeArray, &nIndex, szText+nIndex);
		}

		VARIANT var;
		var.vt = VT_ARRAY | VT_UI1;
		var.parray = pSafeArray;
		pRecordset->MoveFirst();
		pRecordset->Fields->GetItem(_variant_t(long(5)))->AppendChunk(&var);
		pRecordset->Update();


		LONG actualSize = pRecordset->Fields->GetItem(_variant_t(long(5)))->ActualSize;
		_variant_t value = pRecordset->Fields->GetItem(_variant_t(long(5)))->GetChunk(actualSize);

		TCHAR* pszValue=(TCHAR*)malloc(actualSize+1);
		memset(pszValue,0,actualSize+1);

		for(LONG nIndex=0;nIndex<actualSize;nIndex++)
		{
			//获取每个元素
			SafeArrayGetElement(value.parray,
				&nIndex,pszValue+nIndex);
		}

		AfxMessageBox(pszValue);


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

#include "MsgBinding.h"

void CDBDemoDlg::OnBnClickedBindAdo()
{
	// TODO: 在此添加控件通知处理程序代码
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//浏览记录
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		CMsgBinding binding;
		//从Recordset接口获取IADORecordBinding接口
		IADORecordBinding* piAdoBinding = NULL;

		if(FAILED(pRecordSet->QueryInterface(_uuidof(IADORecordBinding), (LPVOID*)&piAdoBinding)))
		{
			pRecordSet->Close();
			pConnection->Close();
			return;
		}
		//将子类绑定到IADORecordBinding接口
		//使用IADORecordBinding->>BindToRecordset绑定数据类
		if(FAILED(piAdoBinding->BindToRecordset(&binding)))
		{
			piAdoBinding->Release();
			return;
		}
		m_wndDatas.InsertColumn(0,TEXT("ID"),LVCFMT_LEFT,100);
		m_wndDatas.InsertColumn(1,TEXT("SENDER"),LVCFMT_LEFT,100);
		m_wndDatas.InsertColumn(2,TEXT("RECEIVER"),LVCFMT_LEFT,100);

		int nItem=0;
		while(!pRecordSet->GetadoEOF())
		{//CMsgBinding中获取字段的数据
			nItem=
				m_wndDatas.InsertItem(nItem,binding.m_szMsgID);
			m_wndDatas.SetItemText(nItem,1,
				binding.m_szSender);
			m_wndDatas.SetItemText(nItem,2,
				binding.m_szReceiver);
			nItem++;

			pRecordSet->MoveNext();
		}

		pRecordSet->Close();
		pConnection->Close();
	}
	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();
	}
}


void CDBDemoDlg::OnBnClickedBindUpdAdo()
{
	// TODO: 在此添加控件通知处理程序代码
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//构造连接字符串
		CString strConn;
		//里面的字符串一定要写在一行里，不然会出错
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_数据库ADO\\18\\db\\ado.mdb"));
		//连接数据库
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//浏览记录
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		CMsgBindingEx binding;
		//从Recordset接口获取IADORecordBinding接口
		IADORecordBinding* piAdoBinding = NULL;

		if(FAILED(pRecordSet->QueryInterface(_uuidof(IADORecordBinding), (LPVOID*)&piAdoBinding)))
		{
			pRecordSet->Close();
			pConnection->Close();
			return;
		}
		//将子类绑定到IADORecordBinding接口
		//使用IADORecordBinding->>BindToRecordset绑定数据类
		if(FAILED(piAdoBinding->BindToRecordset(&binding)))
		{
			pRecordSet->Close();
			pConnection->Close();
			piAdoBinding->Release();
			return;
		}
		
		binding.m_piBinding = piAdoBinding;

		wcscpy(binding.m_szSender,TEXT("hello binding"));

		binding.Update();

		pRecordSet->MoveFirst();


		m_wndDatas.InsertColumn(0,TEXT("ID"),LVCFMT_LEFT,100);
		m_wndDatas.InsertColumn(1,TEXT("SENDER"),LVCFMT_LEFT,100);
		m_wndDatas.InsertColumn(2,TEXT("RECEIVER"),LVCFMT_LEFT,100);

		int nItem=0;
		while(!pRecordSet->GetadoEOF())
		{//CMsgBinding中获取字段的数据
			nItem=
				m_wndDatas.InsertItem(nItem,binding.m_szMsgID);

			int lens = WideCharToMultiByte(CP_ACP, 0, binding.m_szMsgID, wcslen(binding.m_szMsgID), NULL, 0, NULL, NULL);
			//int lens = wcslen(binding.m_szMsgID);

			char* szText = (char*)malloc(lens+1);
			memset(szText,0,lens+1);
			WideCharToMultiByte(CP_ACP,NULL,binding.m_szMsgID,wcslen(binding.m_szMsgID),szText,lens,NULL,NULL);

			m_wndDatas.SetItemText(nItem,1,
				binding.m_szSender);
			m_wndDatas.SetItemText(nItem,2,
				binding.m_szReceiver);
			nItem++;

			pRecordSet->MoveNext();
		}

		pRecordSet->Close();
		pConnection->Close();
	}

	catch(_com_error &e)
	{    
		// Notify the user of errors if any.
		// Pass a connection pointer accessed from the Recordset.
		_variant_t vtConnect = pRecordSet->GetActiveConnection();

		// GetActiveConnection returns connect string if connection
		// is not open, else returns Connection object.
		switch(vtConnect.vt)
		{
		case VT_BSTR:
			PrintComError(e);
			break;
		case VT_DISPATCH:
			PrintProviderError(vtConnect);
			break;
		default:
			wprintf(TEXT("Errors occured."));
			break;
		}
	}
	catch (...)
	{
		CString err;
		err.Format(TEXT("执行【数据库开启连接】时发生错误：%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();
	}
}
