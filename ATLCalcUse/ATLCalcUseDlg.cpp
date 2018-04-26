
// ATLCalcUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ATLCalcUse.h"
#include "ATLCalcUseDlg.h"
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


// CATLCalcUseDlg �Ի���




CATLCalcUseDlg::CATLCalcUseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CATLCalcUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CATLCalcUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CATLCalcUseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEST, &CATLCalcUseDlg::OnClickedTest)
	ON_BN_CLICKED(IDC_PROGID, &CATLCalcUseDlg::OnClickedProgid)
	ON_BN_CLICKED(IDC_CCOMPTR, &CATLCalcUseDlg::OnClickedCcomptr)
END_MESSAGE_MAP()


// CATLCalcUseDlg ��Ϣ�������

BOOL CATLCalcUseDlg::OnInitDialog()
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

void CATLCalcUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CATLCalcUseDlg::OnPaint()
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
HCURSOR CATLCalcUseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "../ATLCalc1/ATLCalc1_i.h"
#include "../ATLCalc1/ATLCalc1_i.c"

void CATLCalcUseDlg::OnClickedTest()
{
	ICalc* pCalc = NULL;
	LPOLESTR pOleStr = NULL;

	ProgIDFromCLSID(CLSID_Calc,&pOleStr);

	

	HRESULT hRet 
		= CoCreateInstance(CLSID_Calc, 
						NULL, 
						CLSCTX_INPROC_SERVER, 
						IID_ICalc, (LPVOID*)&pCalc);
	long nResult = 0;
	pCalc->Add(4,4,&nResult);
	CString strValue;
	strValue.Format(TEXT("%s,%ld"),pOleStr,nResult);
	AfxMessageBox(strValue);

	//�ͷŽӿ�
	pCalc->Release();
}


void CATLCalcUseDlg::OnClickedProgid()
{
	ICalc* pCalc = NULL;
	CLSID clsid = {0};

	//ͨ��progidȡclsid
	CLSIDFromProgID(TEXT("ATLCalc1.Calc"), &clsid);

	HRESULT hRet 
		= CoCreateInstance(clsid, 
		NULL, 
		CLSCTX_INPROC_SERVER, 
		IID_ICalc, (LPVOID*)&pCalc);
	long nResult = 0;
	pCalc->Sub(4,4,&nResult);
	CString strValue;
	strValue.Format(TEXT("%ld"),nResult);
	AfxMessageBox(strValue);

	//�ͷŽӿ�
	pCalc->Release();
}


void CATLCalcUseDlg::OnClickedCcomptr()
{
	CComPtr<ICalc> spCalc;

	spCalc.CoCreateInstance(CLSID_Calc);

	long nResult = 0;
	spCalc->Sub(5,4,&nResult);
	CString strValue;
	strValue.Format(TEXT("%ld"),nResult);
	AfxMessageBox(strValue);
}
