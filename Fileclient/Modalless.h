#pragma once


// CModalless ��ȭ �����Դϴ�.

class CModalless : public CDialog
{
	DECLARE_DYNAMIC(CModalless)

public:
	CModalless(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CModalless();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
