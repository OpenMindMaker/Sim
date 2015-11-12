// Modalless.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Fileclient.h"
#include "Modalless.h"
#include "afxdialogex.h"


// CModalless 대화 상자입니다.

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


// CModalless 메시지 처리기입니다.


void CModalless::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
}


void CModalless::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnOK();
}


void CModalless::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}
