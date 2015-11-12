// MySocket.cpp : 구현 파일입니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnClose();
	}
	CSocket::OnClose(nErrorCode);
}


void CMySocket::OnConnect(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)-> OnConnect();
	}
	CAsyncSocket::OnConnect(nErrorCode);
}


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnReceive();
	}
	CAsyncSocket::OnReceive(nErrorCode);
}


void CMySocket::OnSend(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (nErrorCode == 0){
		((CFileclientDlg*)m_pWnd)->OnSend();
	}
	CAsyncSocket::OnSend(nErrorCode);
}



// MySocket 멤버 함수
