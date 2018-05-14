
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
	ON_BN_CLICKED(IDC_ADD_ADO, &CDBDemoDlg::OnClickedAddAdo)
	ON_BN_CLICKED(IDC_DEL_ADO, &CDBDemoDlg::OnClickedDelAdo)
	ON_BN_CLICKED(IDC_UPD_ADO, &CDBDemoDlg::OnClickedUpdAdo)
	ON_BN_CLICKED(IDC_BINARY_ADO, &CDBDemoDlg::OnBnClickedBinaryAdo)
	ON_BN_CLICKED(IDC_BIND_ADO, &CDBDemoDlg::OnBnClickedBindAdo)
	ON_BN_CLICKED(IDC_BIND_UPD_ADO, &CDBDemoDlg::OnBnClickedBindUpdAdo)
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


void CDBDemoDlg::OnClickedShowAdo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
				//strValue = pRecordset->GetCollect(_variant_t(i));  _variant_t(int)������ת����ʽ�ᱨ��
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


void CDBDemoDlg::AdoMethod2(void)
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//�����¼
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		long cnt = pRecordSet->Fields->GetCount();
		/*CString msg;
		msg.Format(TEXT("�ֶ���:%ld"),cnt);
		AfxMessageBox(msg);*/

		for(int i = 0; i < cnt; i++)
		{
			CString _FiledName = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetName();
			m_wndDatas.InsertColumn(i,_FiledName, LVCFMT_LEFT, 100);

		}

		long rcordCnt = pRecordSet->GetRecordCount();
		/*CString msg;
		msg.Format(TEXT("��¼��:%ld"),rcordCnt);
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
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
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
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

		if(IDOK == AfxMessageBox(TEXT("�Ƿ�ع���"), MB_OKCANCEL))
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
		��Command��Connection�����Execute�����õ���Recordset��ֻ���ġ�
		��Ϊ�ڴ�Recordset֮ǰ�������޷���������LockType���ԣ���Ĭ��ֵΪֻ������
		���ڴ�֮������LockType��������
		�ҷ��������������õ���¼��Rs1�󣬲���Rs1�еļ�¼�޷��޸ģ���ʹֱ����SQL����޸�ͬһ�����κμ�¼�����С�
		*/
		pRecordSet = pCommand->Execute(NULL, NULL, adCmdText);
		//pRecordSet->Open((IDispatch*)pCommand, vtMissing, adOpenKeyset, adLockOptimistic, adCmdUnspecified);

		long cnt = pRecordSet->Fields->GetCount();
		/*CString msg;
		msg.Format(TEXT("�ֶ���:%ld"),cnt);
		AfxMessageBox(msg);*/

		for(int i = 0; i < cnt; i++)
		{
			CString _FiledName = pRecordSet->Fields->GetItem(_variant_t(long(i)))->GetName();
			m_wndDatas.InsertColumn(i,_FiledName, LVCFMT_LEFT, 100);

		}

		long rcordCnt = pRecordSet->GetRecordCount();
		/*CString msg;
		msg.Format(TEXT("��¼��:%ld"),rcordCnt);
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();	
	}
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





void CDBDemoDlg::OnClickedAddAdo()
{
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		pRecordSet.CreateInstance(_uuidof(Recordset));
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
		pConnection->Open(_bstr_t(strConn),"","",adConnectUnspecified);

		pRecordSet->Open(_T("TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdTable);

		if(!pRecordSet->Supports(adAddNew))
		{
			AfxMessageBox(TEXT("��֧��addnew"));
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
			AfxMessageBox(TEXT("��֧��adUpdate"));
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
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
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
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
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
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
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\project\\MFC\\MFC\\DBDemo\\19\\db\\ado.mdb"));
		//�������ݿ�
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
			//��ȡÿ��Ԫ��
			SafeArrayGetElement(value.parray,
				&nIndex,pszValue+nIndex);
		}

		AfxMessageBox(pszValue);


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

#include "MsgBinding.h"

void CDBDemoDlg::OnBnClickedBindAdo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//�����¼
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		CMsgBinding binding;
		//��Recordset�ӿڻ�ȡIADORecordBinding�ӿ�
		IADORecordBinding* piAdoBinding = NULL;

		if(FAILED(pRecordSet->QueryInterface(_uuidof(IADORecordBinding), (LPVOID*)&piAdoBinding)))
		{
			pRecordSet->Close();
			pConnection->Close();
			return;
		}
		//������󶨵�IADORecordBinding�ӿ�
		//ʹ��IADORecordBinding->>BindToRecordset��������
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
		{//CMsgBinding�л�ȡ�ֶε�����
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();
	}
}


void CDBDemoDlg::OnBnClickedBindUpdAdo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	_ConnectionPtr pConnection;
	_RecordsetPtr pRecordSet;

	try
	{
		pConnection.CreateInstance(_uuidof(Connection));
		//���������ַ���
		CString strConn;
		//������ַ���һ��Ҫд��һ�����Ȼ�����
		strConn.Format(TEXT("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;User ID=;Password=;"),TEXT("D:\\software\\noteCode\\11_���ݿ�ADO\\18\\db\\ado.mdb"));
		//�������ݿ�
		pConnection->Open(_bstr_t(strConn), "","", adConnectUnspecified);

		pRecordSet.CreateInstance(_uuidof(Recordset));


		//�����¼
		pRecordSet->Open(_T("select * from TBL_MSG"), (IDispatch*)pConnection, adOpenKeyset, adLockOptimistic, adCmdText);

		CMsgBindingEx binding;
		//��Recordset�ӿڻ�ȡIADORecordBinding�ӿ�
		IADORecordBinding* piAdoBinding = NULL;

		if(FAILED(pRecordSet->QueryInterface(_uuidof(IADORecordBinding), (LPVOID*)&piAdoBinding)))
		{
			pRecordSet->Close();
			pConnection->Close();
			return;
		}
		//������󶨵�IADORecordBinding�ӿ�
		//ʹ��IADORecordBinding->>BindToRecordset��������
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
		{//CMsgBinding�л�ȡ�ֶε�����
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
		err.Format(TEXT("ִ�С����ݿ⿪�����ӡ�ʱ��������%08x"),GetLastError());
		AfxMessageBox(err);
		pConnection->Close();
	}
}
