
// AutoWord1Dlg.h : ͷ�ļ�
//

#pragma once


// CAutoWord1Dlg �Ի���
class CAutoWord1Dlg : public CDialogEx
{
// ����
public:
	CAutoWord1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AUTOWORD1_DIALOG };

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
	afx_msg void OnClickedAutoexe();
	afx_msg void OnClickedAutodll();
	afx_msg void OnClickedWord();
};
