// MySocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Fileclient.h"
#include "MySocket.h"
#include "FileclientDlg.h"


// MySocket

CMySocket::CMySocket()
{
}

CMySocket::~CMySocket()
{
}



void CMySocket::SetParent(CDialog *pWnd){
	m_pWnd = pWnd;
}

void CMySocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnClose();
	}
	CSocket::OnClose(nErrorCode);
}


void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)-> OnConnect();
	}
	CAsyncSocket::OnConnect(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnReceive();
	}
	CAsyncSocket::OnReceive(nErrorCode);
}


void CMySocket::OnSend(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnSend();
	}
	CAsyncSocket::OnSend(nErrorCode);
}



// MySocket ��� �Լ�
