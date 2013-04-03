// TestLEDDlg.h : header file
//

#if !defined(AFX_TESTLEDDLG_H__C9845FF7_F9C0_45FF_8E5C_1C0184669AC8__INCLUDED_)
#define AFX_TESTLEDDLG_H__C9845FF7_F9C0_45FF_8E5C_1C0184669AC8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestLEDDlg dialog
/*添加屏幕*/
typedef int(__stdcall *AddScreen)(int nControlType,int nScreenNo,int nWidth,int nHeight,int nScreenType,
								  int nPixelMode,int nDataDA,int nDataOE,int nRowOrder,int nFreqPar,
								  char* pCom,int nBaud,char* pSocketIP,int nSocketPort,char* pScreenStatusFile);

/*添加屏幕节目*/
typedef int(__stdcall *AddScreenProgram)(int nScreenNo,int nProgramType,int nPlayLength,int nStartYear,
										 int nStartMonth,int nStartDay,int nEndYear,int nEndMonth,int nEndDay,
										 int nMonPlay,int nTuesPlay,int nWedPlay,int nThursPlay,int nFriPlay,
										 int nSatPlay,int nSunPlay,int nStartHour,int nStartMinute,int nEndHour,
										 int nEndMinute);
/*添加图文区域*/
typedef int(__stdcall *AddScreenProgramBmpTextArea)(int nScreenNo,int nProgramOrd,int nX,int nY,int nWidth,int nHeight);
/*向显示屏指定节目指定区域添加文件*/
typedef int(__stdcall *AddScreenProgramAreaBmpTextFile)(int nScreenNo,int nProgramOrd,int nAreaOrd,char* pFileName,
														int nShowSingle, char* pFontName,int nFontSize,int nBold,int nFontColor,
														int nStunt,int nRunSpeed,int nShowTime);
/*发送相应命令到显示屏*/
	typedef int(__stdcall *SendScreenInfo)(int nScreenNo,int nSendMode,int nSendCmd,int nOtherParam1);

	typedef int(__stdcall *InitDLLResource)(HANDLE AHandle);
	typedef void(__stdcall *FreeDLLResource)();

class CTestLEDDlg : public CDialog
{
// Construction
public:
	CTestLEDDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestLEDDlg)
	enum { IDD = IDD_TESTLED_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLEDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	public:
		float f;
		BOOL bComm;
		unsigned int a;
		HINSTANCE hInst;

		AddScreen api_AddScreen;
		BOOL m_bSendBusy;//此变量在数据更新中非常重要，请务必保留。
		AddScreenProgram api_AddScreenProgram;
		AddScreenProgramBmpTextArea api_AddScreenProgramBmpTextArea;
		AddScreenProgramAreaBmpTextFile api_AddScreenProgramAreaBmpTextFile;
		SendScreenInfo api_SendScreenInfo;

		InitDLLResource api_InitDLLResource;
		FreeDLLResource api_FreeDLLResource;

//	Cardinal UniqueMsgID;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestLEDDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	virtual void OnCancel();
	afx_msg void OnClose();
	afx_msg void OnCancelMode();
	afx_msg void OnButton2();
	virtual void OnOK();
	afx_msg void OnDoubleclickedButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLEDDLG_H__C9845FF7_F9C0_45FF_8E5C_1C0184669AC8__INCLUDED_)
