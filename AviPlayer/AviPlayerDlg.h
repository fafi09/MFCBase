
// AviPlayerDlg.h : ͷ�ļ�
//

#pragma once


// CAviPlayerDlg �Ի���
class CAviPlayerDlg : public CDialogEx
{
// ����
public:
	CAviPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AVIPLAYER_DIALOG };

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
	CAnimateCtrl m_wndAnimate;
	CListBox m_wndHistory;
	CHotKeyCtrl m_wndHotKey;
	CButton m_wndLoop;
	CString m_strFilePath;
	afx_msg void OnOpen();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg void OnLoop();
	afx_msg void OnDblclkHistory();
	afx_msg void OnSethotkey();
	CComboBox m_wndLoopNum;
};
