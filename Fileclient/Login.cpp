// Login.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Fileclient.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLogin, CDialog)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CLogin::IDD, pParent)
	, m_port(7773)
	, m_str_ip(_T("localhost"))
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_port);
	DDX_Text(pDX, IDC_EDIT1, m_str_ip);
}


BEGIN_MESSAGE_MAP(CLogin, CDialog)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLogin::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLogin �޽��� ó�����Դϴ�.


void CLogin::OnBnClickedOk()
{
	UpdateData(TRUE);
	if(!m_str_ip.Compare(_T("localhost"))){
		if(m_port == 7773){
			OnOK();
		}
	}

}


void CLogin::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	exit(0);
}
