
// AutoWord1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoWord1.h"
#include "AutoWord1Dlg.h"
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


// CAutoWord1Dlg �Ի���




CAutoWord1Dlg::CAutoWord1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAutoWord1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoWord1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAutoWord1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_AUTOEXE, &CAutoWord1Dlg::OnClickedAutoexe)
	ON_BN_CLICKED(IDC_AUTODLL, &CAutoWord1Dlg::OnClickedAutodll)
	ON_BN_CLICKED(IDC_WORD, &CAutoWord1Dlg::OnClickedWord)
END_MESSAGE_MAP()


// CAutoWord1Dlg ��Ϣ�������

BOOL CAutoWord1Dlg::OnInitDialog()
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

void CAutoWord1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAutoWord1Dlg::OnPaint()
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
HCURSOR CAutoWord1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#include "CAutoExe1.h"

void CAutoWord1Dlg::OnClickedAutoexe()
{
	CAutoExe1 exe;
	exe.CreateDispatch(TEXT("AutoExe1.Document"));

	exe.SetVisible(TRUE);
	exe.TypeText(TEXT("hello AutoExe"));

	exe.DetachDispatch();
}

#include "CMath.h"
void CAutoWord1Dlg::OnClickedAutodll()
{
	CMath math;
	math.CreateDispatch(TEXT("AutoDll1.Math"));

	LONG nAdd = 0;
	math.Sub(10, 4, &nAdd);


	math.DetachDispatch();
	CString strText;
	strText.Format(TEXT("%d"),nAdd);
	AfxMessageBox(strText);

}

#include "CApplication.h"
#include "CDocument0.h"
#include "CSelection.h"
#include "CDocuments.h"

void CAutoWord1Dlg::OnClickedWord()
{
	CApplication app;
	app.CreateDispatch(TEXT("Word.Application"));
	app.put_Visible(TRUE);

	CDocuments docs = app.get_Documents();

	COleVariant templateDoc(_T(""));
	COleVariant newTemplateDoc(0L);
	COleVariant doctype(0L);
	COleVariant varVisiable;


	CDocument0 doc = docs.Add(&templateDoc, &newTemplateDoc, &doctype, &varVisiable);

	CSelection sel = app.get_Selection();
	sel.TypeText(TEXT("hello world"));

	doc.Save();
	app.DetachDispatch();
}
