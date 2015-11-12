#pragma once

// MySocket ��� ����Դϴ�.

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


