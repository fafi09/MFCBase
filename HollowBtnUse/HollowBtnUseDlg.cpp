
// HollowBtnUseDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HollowBtnUse.h"
#include "HollowBtnUseDlg.h"
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


// CHollowBtnUseDlg �Ի���




CHollowBtnUseDlg::CHollowBtnUseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHollowBtnUseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHollowBtnUseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHollowBtnUseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CHollowBtnUseDlg ��Ϣ�������

BOOL CHollowBtnUseDlg::OnInitDialog()
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
	SetBmpRgn(IDB_BITMAP1);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CHollowBtnUseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHollowBtnUseDlg::OnPaint()
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

		/*CClientDC dc(this);
		CRect dcRect;
		GetClientRect(&dcRect);
		dc.FillSolidRect(dcRect, RGB(255,128,64));*/
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CHollowBtnUseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHollowBtnUseDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}
BEGIN_EVENTSINK_MAP(CHollowBtnUseDlg, CDialogEx)
	ON_EVENT(CHollowBtnUseDlg, IDC_HOLLOWBTN1CTRL1, DISPID_CLICK, CHollowBtnUseDlg::ClickHollowbtn1ctrl1, VTS_NONE)
END_EVENTSINK_MAP()


void CHollowBtnUseDlg::ClickHollowbtn1ctrl1()
{
	AfxMessageBox(TEXT("click"));
}


void CHollowBtnUseDlg::SetBmpRgn(int nID)
{
	//����ͼƬ
	CClientDC dc(this);
	CBitmap bmp;
	bmp.LoadBitmap(nID);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);
	CBitmap *pOldBmp=dcBmp.SelectObject(&bmp);
	//��������
	CRect rcWnd;
	GetWindowRect(&rcWnd);
	CRgn rgnWnd;
	rgnWnd.CreateRectRgn(0,0,
		rcWnd.Width(),rcWnd.Height());
	//����ͼƬ������
	for(int nX=0;nX<77;nX++)
	{
		for(int nY=0;nY<77;nY++)
		{
			//��ȡͼƬÿһ�������ɫ
			COLORREF nColor=dcBmp.GetPixel(nX,nY);
			//�ж���ɫ�Ƿ�Ϊ����ɫ
			if(nColor==RGB(255,255,255))
			{
				CRgn rgnRect;
				rgnRect.CreateRectRgn(nX+50,nY+50,nX+51,nY+51);
				//��ȥ����ɫ������
				rgnWnd.CombineRgn(&rgnWnd,&rgnRect,
					RGN_XOR);
			}
		}

	}
	//���ô���
	SetWindowRgn(rgnWnd,TRUE);
	dcBmp.SelectObject(pOldBmp);
}
