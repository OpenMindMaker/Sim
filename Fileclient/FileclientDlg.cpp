
// FileclientDlg.cpp : 구현 파일
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
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CFileclientDlg 대화 상자



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


// CFileclientDlg 메시지 처리기

BOOL CFileclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	
	if(LoginDialog.DoModal()==IDOK){
		connect_ip = LoginDialog.m_str_ip;
		connect_port = LoginDialog.m_port;
	}

	UpdateData(TRUE);
	m_Csocket.SetParent(this);
	SetTimer(ID_ANIMATION_TIMER,150,NULL);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFileclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
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

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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






	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
					MessageBox(_T("동시사용자가 많거나 서버가\n 활성화 되지못했습니다."));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
