
// Fileclient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFileclientApp:
// �� Ŭ������ ������ ���ؼ��� Fileclient.cpp�� �����Ͻʽÿ�.
//

class CFileclientApp : public CWinApp
{
public:
	CFileclientApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFileclientApp theApp;