// PowDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PowDlg.h"
#include "afxdialogex.h"
#include "math.h"

// CPowDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPowDlg, CDialog)

CPowDlg::CPowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPowDlg::IDD, pParent)
	, m_value(0)
{

}

CPowDlg::~CPowDlg()
{
}

void CPowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value);
}


BEGIN_MESSAGE_MAP(CPowDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CPowDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPowDlg 메시지 처리기입니다.


void CPowDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int result = pow(10.,m_value);
	CString str;
	str.Format(_T("10dml %d승은 %d입니다."),m_value,result);
}
