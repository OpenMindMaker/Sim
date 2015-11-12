
// FileclientDlg.h : ��� ����
//

#pragma once
#include "MySocket.h"
#include "afxwin.h"
#include <winsock2.h>
#include <mswsock.h>
#include "Login.h"
// CFileclientDlg ��ȭ ����
class CFileclientDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFileclientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FILECLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CMySocket m_Csocket;

	CString connect_ip;
	int connect_port;

	CLogin LoginDialog;

	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();





	afx_msg void OnBnClickedSendfile();
	afx_msg void OnBnClickedRecvfile();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_rec_deco;
	int m_view;
};
