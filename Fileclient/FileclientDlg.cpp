
// FileclientDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Fileclient.h"
#include "FileclientDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#include <stdio.h>
#include <windows.h>
#include <process.h> 
#include <direct.h>

#define BUF_SIZE 30
#define _MAX_PATH 260

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int grow = 1 ;
int ellipse_thick = 10;
// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileclientDlg ��ȭ ����



CFileclientDlg::CFileclientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_rec_deco = 0;
	m_view = 0;
}

void CFileclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SENDFILE, &CFileclientDlg::OnBnClickedSendfile)
	ON_BN_CLICKED(IDC_RECVFILE, &CFileclientDlg::OnBnClickedRecvfile)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CFileclientDlg �޽��� ó����

BOOL CFileclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	if(LoginDialog.DoModal()==IDOK){
		connect_ip = LoginDialog.m_str_ip;
		connect_port = LoginDialog.m_port;
	}

	UpdateData(TRUE);
	m_Csocket.SetParent(this);
	SetTimer(ID_ANIMATION_TIMER,150,NULL);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CFileclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CFileclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();	
		CClientDC dc(this);
		CDC MemDC;
		MemDC.CreateCompatibleDC(&dc);
		CBitmap bitmap,bitmap2,bitmap3;
		bitmap.LoadBitmapW(IDB_MANGO);
		bitmap2.LoadBitmapW(IDB_BLACK_BMP);
		bitmap3.LoadBitmapW(IDB_REC_BMP);

		CBitmap *oldBitmap,*oldBitmap2,*oldBitmap3;
		oldBitmap = MemDC.SelectObject(&bitmap);
		dc.BitBlt(0,0,1000,76,&MemDC,0,0,SRCCOPY);
		dc.SelectObject(oldBitmap);
		oldBitmap2 = MemDC.SelectObject(&bitmap2);
		dc.BitBlt(0,76,1000,1000,&MemDC,0,0,SRCCOPY);
		dc.SelectObject(oldBitmap2);
		oldBitmap3= MemDC.SelectObject(&bitmap3);


		int thin = ellipse_thick;
		CBrush rec_red ,rec_black;
		rec_red.CreateSolidBrush(RGB(255,10,10));
		rec_black.CreateSolidBrush(RGB(0,0,0));
		CBrush *usedRec = dc.SelectObject(&rec_red);
		dc.Ellipse(120-thin,230-thin,240+thin,320+thin);
		dc.SelectObject(usedRec);
		rec_red.DeleteObject();
		CBrush *usedRec2 = dc.SelectObject(&rec_black);
		dc.Ellipse(120,230,240,320);
		dc.SelectObject(usedRec2);
		rec_black.DeleteObject();
		dc.BitBlt(140,250,1000,1000,&MemDC,0,0,SRCCOPY);
		dc.SelectObject(oldBitmap3);
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CFileclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileclientDlg::OnConnect(){
}

void CFileclientDlg::OnClose(){
	m_Csocket.Close();
}

void CFileclientDlg::OnSend(){

}

void CFileclientDlg::OnReceive(){
}


unsigned WINAPI Mthread(void * arg) 
{
	char *pstrBuffer = NULL;
	char strBuffer[_MAX_PATH] = { 0, };
    pstrBuffer = getcwd( strBuffer, _MAX_PATH );
	sprintf(pstrBuffer,"%s\\%s",pstrBuffer ,"recoder.exe");
	system(pstrBuffer);
	return 0;
}


void CFileclientDlg::OnBnClickedSendfile()
{
	KillTimer(ID_ANIMATION_TIMER);
	HANDLE tHandles = (HANDLE)_beginthreadex(NULL, 0, Mthread, NULL, 0, NULL);
	
	Sleep(3500);






	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItem(IDC_RECVFILE)->EnableWindow(FALSE);
	GetDlgItem(IDC_SENDFILE)->EnableWindow(FALSE);
	m_Csocket.Create();
	m_Csocket.Connect(connect_ip,connect_port);

	FILE *readfile=fopen("output.wav", "rb");
	char buf[BUF_SIZE];
	int readCnt;
	m_Csocket.Send("send\n",BUF_SIZE);
	Sleep(10);
	
	while(1)
	{
		readCnt=fread((void*)buf, 1, BUF_SIZE, readfile);
		int sentData=0;
		while(1){
			int r=m_Csocket.Send( (char*)&buf+sentData, readCnt-sentData, 0);
			if(r==SOCKET_ERROR){
				if(GetLastError()==WSAEWOULDBLOCK){
					Sleep(10);
					continue;
				}
				else{
					MessageBox(_T("���û���ڰ� ���ų� ������\n Ȱ��ȭ �������߽��ϴ�."));
					fclose(readfile);
					return;
				}
			}
			sentData+=r;
			if(sentData==readCnt)
				break;

		}
		if(readCnt<BUF_SIZE)
			break;
	}
	m_Csocket.ShutDown(1);
	fclose(readfile);
	m_Csocket.Close();
	GetDlgItem(IDC_SENDFILE)->EnableWindow(TRUE);
	GetDlgItem(IDC_RECVFILE)->EnableWindow(TRUE);



	WaitForMultipleObjects(0,&tHandles, TRUE, INFINITE);

	SetTimer(ID_ANIMATION_TIMER,250,NULL);
}



void CFileclientDlg::OnBnClickedRecvfile()
{
	
	KillTimer(ID_ANIMATION_TIMER);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItem(IDC_RECVFILE)->EnableWindow(FALSE);
	GetDlgItem(IDC_SENDFILE)->EnableWindow(FALSE);
	m_Csocket.Create();
	m_Csocket.Connect(connect_ip,connect_port);
	FILE *writefile=fopen("FromServer.wav", "wb");
	char buf[BUF_SIZE];
	char msg[10];
	int readCnt;
	m_Csocket.Send("receive\n",BUF_SIZE);
	while((readCnt=m_Csocket.Receive( buf, BUF_SIZE, 0))!=0){
			size_t r = fwrite((void*)buf, 1, readCnt, writefile);
		}

	puts("Received file data");
	m_Csocket.ShutDown(2);
	fclose(writefile);
	Sleep(200);
	char *pstrBuffer = NULL;
	char strBuffer[_MAX_PATH] = { 0, };
    pstrBuffer = getcwd( strBuffer, _MAX_PATH );
	sprintf(pstrBuffer,"%s\\%s",pstrBuffer ,"player.exe");
	system(pstrBuffer);
	m_Csocket.Close();
	GetDlgItem(IDC_SENDFILE)->EnableWindow(TRUE);
	GetDlgItem(IDC_RECVFILE)->EnableWindow(TRUE);
	SetTimer(ID_ANIMATION_TIMER,150,NULL);
}


void CFileclientDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(grow)
	{	
		if(ellipse_thick == 0){
			grow = 0;
		}
		ellipse_thick -= 10;

	}
	else
	{
		if(ellipse_thick == 50){
			grow = 1;
		}
		ellipse_thick += 10;
	
	}
	Invalidate(TRUE);
	CDialogEx::OnTimer(nIDEvent);
}
