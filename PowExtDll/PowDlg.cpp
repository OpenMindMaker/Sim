// PowDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PowDlg.h"
#include "afxdialogex.h"
#include "math.h"

// CPowDlg ��ȭ �����Դϴ�.

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


// CPowDlg �޽��� ó�����Դϴ�.


void CPowDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	int result = pow(10.,m_value);
	CString str;
	str.Format(_T("10dml %d���� %d�Դϴ�."),m_value,result);
}
