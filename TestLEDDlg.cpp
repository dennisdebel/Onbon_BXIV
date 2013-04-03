// TestLEDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestLED.h"
#include "TestLEDDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

       //------------------------------------------------------------------------------
        // 控制器类型
        #define CONTROLLER_TYPE_3T   0x10
        #define CONTROLLER_TYPE_3A   0x20
        #define CONTROLLER_TYPE_3A1   0x21
        #define CONTROLLER_TYPE_3A2   0x22
        #define CONTROLLER_TYPE_3M   0x30

        #define CONTROLLER_TYPE_4A1   0x0141
        #define CONTROLLER_TYPE_4A2   0x0241
        #define CONTROLLER_TYPE_4A3   0x0341
        #define CONTROLLER_TYPE_4AQ   0x1041
        #define CONTROLLER_TYPE_4A   0x0041

        #define CONTROLLER_TYPE_4M1   0x0142
        #define CONTROLLER_TYPE_4M   0x0042
        #define CONTROLLER_TYPE_4MC   0x0C42
        #define CONTROLLER_TYPE_4E   0x0044
        #define CONTROLLER_TYPE_4C   0x0043
        #define CONTROLLER_TYPE_4E1   0x0144
        #define CONTROLLER_TYPE_5M4   0x0452

        //------------------------------------------------------------------------------
//                                                                              
// 控制器通讯模式
        #define SEND_MODE_COMM   3 //hardcoded commmport ...3 in this case
        #define SEND_MODE_NET   2
//                                                                              

//                                                                              
// 用户发送信息命令表
        #define SEND_CMD_PARAMETER   0xA1FF //加载屏参数。
        #define SEND_CMD_SCREENSCAN   0xA1FE //设置扫描方式。
        #define SEND_CMD_SENDALLPROGRAM   0xA1F0 //发送所有节目信息。
        #define SEND_CMD_POWERON   0xA2FF //强制开机
        #define SEND_CMD_POWEROFF   0xA2FE //强制关机
        #define SEND_CMD_TIMERPOWERONOFF   0xA2FD //定时开关机
        #define  SEND_CMD_CANCEL_TIMERPOWERONOFF   0xA2FC //取消定时开关机
        #define SEND_CMD_RESIVETIME   0xA2FB //校正时间。
        #define SEND_CMD_ADJUSTLIGHT   0xA2FA //亮度调整。

//                                                                              

        #define SCREEN_NO   1
        #define SCREEN_WIDTH   128 //hardcodes screen parameters...
        #define SCREEN_HEIGHT   16
        #define SCREEN_TYPE   1
        #define SCREEN_DATADA   0
        #define SCREEN_DATAOE   0
        #define SCREEN_COMM   "COM3" //hardcoded screen port again...
        #define SCREEN_BAUD   57600
        #define SCREEN_ROWORDER   0
        #define SCREEN_FREQPAR   0
        #define SCREEN_SOCKETIP   "192.168.2.223"
        #define SCREEN_SOCKETPORT   5005
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLEDDlg dialog

CTestLEDDlg::CTestLEDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestLEDDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestLEDDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestLEDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestLEDDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestLEDDlg, CDialog)
	//{{AFX_MSG_MAP(CTestLEDDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CLOSE()
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_DOUBLECLICKED(IDC_BUTTON2, OnDoubleclickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestLEDDlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLEDDlg message handlers

	BOOL CTestLEDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here	afx_msg void OnDoubleclickedButton2();
	
	//inititalise hardcodes screen parameters so you only have to press button 4 to update text
	OnButton7();
	OnButton1();
	OnButton6();
	OnButton5();
	OnButton2();
	OnButton3();
	OnButton4();
	

	a = ::RegisterWindowMessage("LedSend Windows");
	bComm = TRUE;
	f= 0;
	m_bSendBusy=FALSE;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestLEDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestLEDDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestLEDDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestLEDDlg::OnButton1() 
{//hardcoded controller type / set your screen parameters
	int nresult;
	nresult = api_AddScreen(CONTROLLER_TYPE_4A1, SCREEN_NO, SCREEN_WIDTH
		, SCREEN_HEIGHT, SCREEN_TYPE, 1,SCREEN_DATADA, SCREEN_DATAOE
		, SCREEN_ROWORDER, SCREEN_FREQPAR,SCREEN_COMM
		, SCREEN_BAUD,SCREEN_SOCKETIP, SCREEN_SOCKETPORT,"ScreenStatus.ini");

}

void CTestLEDDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
		FreeLibrary(hInst);
	CDialog::OnCancel();
	//	FreeLibrary(hInst);
}

void CTestLEDDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
		FreeLibrary(hInst);
		KillTimer(100);
	CDialog::OnClose();
	
}

void CTestLEDDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	//	FreeLibrary(hInst);
	// TODO: Add your message handler code here
	
}

void CTestLEDDlg::OnButton2() //add bmp/text area to program (add program first with button 5)
{
int nresult;
nresult = api_AddScreenProgramBmpTextArea(SCREEN_NO, 0, 0, 0, SCREEN_WIDTH
		, SCREEN_HEIGHT);
}

void CTestLEDDlg::OnOK() 
{
	// TODO: Add extra validation here
	FreeLibrary(hInst);	
	CDialog::OnOK();

}

void CTestLEDDlg::OnDoubleclickedButton2() 
{
	// TODO: Add your control notification handler code here
	
}

void CTestLEDDlg::OnButton3() //send addd.txt
{
            int nresult = api_AddScreenProgramAreaBmpTextFile(SCREEN_NO, 0, 0, "Add.txt", 0, "Arial", 12, 0, 1, 1, 3, 0);
			//explain:
			//int nresult = api_AddScreenProgramAreaBmpTextFile(SCREEN_NO, 0, 0, "Add.txt", 0, "fontface", fontsize, 0(fontcolor), 1(nstunt), 4(displaymode!0=random,1=static), 3(showtime), 0);
}

void CTestLEDDlg::OnButton4() //send all programs
{
	if (m_bSendBusy==FALSE)
	{
		//while(1) // endless auto refresh loop....//todo: crahses program though....
		//{

    
			m_bSendBusy=TRUE;
            int nResult;
            nResult = api_SendScreenInfo(SCREEN_NO, SEND_MODE_COMM, SEND_CMD_SENDALLPROGRAM, 0);
			m_bSendBusy=FALSE;
			//Sleep(2000); /// refresh interval milliseconds

		//}
	}
}
























LRESULT CTestLEDDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	

	if(message == a)
	{
		if(lParam == 0)
			;
		else if(lParam == 1)
			AfxMessageBox("1");
		else if(lParam == 2)
			AfxMessageBox("2");
		else
			AfxMessageBox("d");
}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CTestLEDDlg::OnButton5()  //add (empty) program to screen 
{
            
            int rusult = api_AddScreenProgram(SCREEN_NO, 0, 0, 65535, 12, 3, 2011, 11, 26, 1, 1, 1, 1, 1, 1, 1, 8, 0, 18, 0);

}

void CTestLEDDlg::OnButton6() //no idea, check if screen is busy?
{
 	if (m_bSendBusy==FALSE)
	{
		m_bSendBusy=TRUE;
           int nResult;
            nResult = api_SendScreenInfo(SCREEN_NO, SEND_MODE_COMM, SEND_CMD_PARAMETER, 0);
  			m_bSendBusy=FALSE;
	}

}

void CTestLEDDlg::OnButton7() 
{ //read screen info and init the bx dll file?
	hInst = NULL;
	hInst = LoadLibrary("BX_IV.dll");

	 api_AddScreen=(AddScreen)GetProcAddress(hInst,"AddScreen");
	 api_AddScreenProgram=(AddScreenProgram)GetProcAddress(hInst,"AddScreenProgram");
	 api_AddScreenProgramBmpTextArea=(AddScreenProgramBmpTextArea)GetProcAddress(hInst,"AddScreenProgramBmpTextArea");
	 api_AddScreenProgramAreaBmpTextFile=(AddScreenProgramAreaBmpTextFile)GetProcAddress(hInst,"AddScreenProgramAreaBmpTextFile");
	 api_SendScreenInfo=(SendScreenInfo)GetProcAddress(hInst,"SendScreenInfo");

	 api_InitDLLResource=(InitDLLResource)GetProcAddress(hInst,"InitDLLResource");
	 api_FreeDLLResource=(FreeDLLResource)GetProcAddress(hInst,"FreeDLLResource");

	int nResult=api_InitDLLResource(GetSafeHwnd());	
}


void CTestLEDDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}
