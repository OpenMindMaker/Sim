// Modalless.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Fileclient.h"
#include "Modalless.h"
#include "afxdialogex.h"


// CModalless ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CModalless, CDialog)

CModalless::CModalless(CWnd* pParent /*=NULL*/)
	: CDialog(CModalless::IDD, pParent)
{

}

CModalless::~CModalless()
{
}

void CModalless::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalless, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &CModalless::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CModalless::OnBnClickedCancel)
END_MESSAGE_MAP()


// CModalless �޽��� ó�����Դϴ�.


void CModalless::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
		// �׸��� �޽����� ���ؼ��� CDialog::OnPaint()��(��) ȣ������ ���ʽÿ�.
}


void CModalless::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialog::OnOK();
}


void CModalless::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialog::OnCancel();
}
