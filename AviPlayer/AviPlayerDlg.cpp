
// AviPlayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AviPlayer.h"
#include "AviPlayerDlg.h"
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


// CAviPlayerDlg �Ի���




CAviPlayerDlg::CAviPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAviPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strFilePath = _T("");
}

void CAviPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ANIMATE, m_wndAnimate);
	DDX_Control(pDX, IDC_HISTORY, m_wndHistory);
	DDX_Control(pDX, IDC_HOTKEY, m_wndHotKey);
	DDX_Control(pDX, IDC_LOOP, m_wndLoop);
	DDX_Text(pDX, IDC_PATH, m_strFilePath);
	DDX_Control(pDX, IDC_LOOPNUM, m_wndLoopNum);
}

BEGIN_MESSAGE_MAP(CAviPlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN, &CAviPlayerDlg::OnOpen)
	ON_COMMAND(IDC_START, &CAviPlayerDlg::OnStart)
	ON_COMMAND(IDC_STOP, &CAviPlayerDlg::OnStop)
	ON_BN_CLICKED(IDC_LOOP, &CAviPlayerDlg::OnLoop)
	ON_LBN_DBLCLK(IDC_HISTORY, &CAviPlayerDlg::OnDblclkHistory)
	ON_BN_CLICKED(IDC_SETHOTKEY_BTN, &CAviPlayerDlg::OnSethotkey)
END_MESSAGE_MAP()


// CAviPlayerDlg ��Ϣ�������

BOOL CAviPlayerDlg::OnInitDialog()
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
	//��ʼ������ѭ����״̬
	OnLoop();
	//��ʼ��ѭ������
	m_wndLoopNum.SetCurSel(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CAviPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAviPlayerDlg::OnPaint()
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
HCURSOR CAviPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAviPlayerDlg::OnOpen()
{
	TCHAR szFilter[] = TEXT("AVI(*.avi)|*.avi||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);
	if(IDOK != dlg.DoModal())
	{
		return;
	}

	CString fileName = dlg.GetFileName();
	m_strFilePath = dlg.GetPathName();

	UpdateData(FALSE);

	//���ļ������ӵ���ʷ�б�
	int idx = m_wndHistory.AddString(fileName);

	CString* pfileName = new CString;
	*pfileName = dlg.GetFileName();

	m_wndHistory.SetItemData(idx, (DWORD)pfileName);


	 
}


void CAviPlayerDlg::OnStart()
{
	m_wndAnimate.Open(m_strFilePath);
	if(m_wndLoop.GetCheck())
	{
		int selIdx = m_wndLoopNum.GetCurSel();
		switch(selIdx)
		{
		case 0:
			m_wndAnimate.Play(0, -1, -1);
			break;
		case 1:
			m_wndAnimate.Play(0, -1, 1);
			break;
		case 2:
			m_wndAnimate.Play(0, -1, 2);
			break;
		}
	}
	else
	{
		m_wndAnimate.Play(0, -1, -1);
	}
}


void CAviPlayerDlg::OnStop()
{
	m_wndAnimate.Stop();
	m_wndAnimate.Close();
}


void CAviPlayerDlg::OnLoop()
{
	//�õ������Ƿ�ѭ����״̬
	int nCheck = m_wndLoop.GetCheck();
	//����combo�Ƿ����
	m_wndLoopNum.EnableWindow(nCheck);

}


void CAviPlayerDlg::OnDblclkHistory()
{
	int idxSel = m_wndHistory.GetCurSel();
	CString* fileName = (CString*)m_wndHistory.GetItemData(idxSel);
	m_strFilePath = *fileName;

	UpdateData(FALSE);

}


void CAviPlayerDlg::OnSethotkey()
{
	//��ȡ�ȼ�
	DWORD nHotKey = m_wndHotKey.GetHotKey();
	//���ó����ȼ�
	SendMessage(WM_SETHOTKEY, nHotKey);
}
