#pragma once

// MySocket 명령 대상입니다.

class CMySocket : public CSocket
{

private:
	CDialog * m_pWnd;

public:
	CMySocket();
	virtual ~CMySocket();
	void SetParent(CDialog* pWnd);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


