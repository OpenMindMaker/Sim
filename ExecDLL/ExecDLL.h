
// ExecDLL.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExecDLLApp:
// �� Ŭ������ ������ ���ؼ��� ExecDLL.cpp�� �����Ͻʽÿ�.
//

class CExecDLLApp : public CWinApp
{
public:
	CExecDLLApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExecDLLApp theApp;