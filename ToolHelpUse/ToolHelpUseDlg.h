
// ToolHelpUseDlg.h : ͷ�ļ�
//

#pragma once


// CToolHelpUseDlg �Ի���
class CToolHelpUseDlg : public CDialogEx
{
// ����
public:
	CToolHelpUseDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TOOLHELPUSE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_wndProc;
	CTreeCtrl m_wndThread;
	void ShowProcess(void);
	void ShowThread(void);
};
