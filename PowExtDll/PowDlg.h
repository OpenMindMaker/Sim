
#pragma once
#include "resource.h"

// CPowDlg ��ȭ �����Դϴ�.

class AFX_EXT_CLASS CPowDlg : public CDialog
{
	DECLARE_DYNAMIC(CPowDlg)

public:
	CPowDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPowDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POWDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_value;
	afx_msg void OnBnClickedButton1();
};
