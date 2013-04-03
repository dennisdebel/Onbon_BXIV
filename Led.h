#ifndef _LED_H_
#define _LED_H_

#define READ_TIMEOUT      500      // milliseconds

#include <windows.h>
#include <stdio.h>
#include <io.h>

class CLED //声明该类可以外部调用
{
public:
        CLED();
        ~CLED();
        
        //void LoadPicToArea(char *pcFileName);
        bool Init(HANDLE hHandle,int iLedWidth,int iLedHeight);
        bool Connect(int iPortID);
        void Disconnect();
        void SetPlayList(int iPlayMode,int iPlaySpeed,int iPauseTime);
        void SendStartCommand(int iScreenID,int iBufID,int iTotalCounts);
        DWORD SendData(char *pcFileName,bool bColor,bool bLeftOrRight);
        void SendEndCommand();
        void ClearScreen(int iScreenID,int iBufID);
        void WriteStrToScreen(HANDLE hHande,int iStartX,int iStartY,char *szString);
        void CreateNewFont(TCHAR * szFaceName,COLORREF crFontColor,
                        int iDeciPtHeight,int iDeciPtWidth,int iSpace,int iAttributes, BOOL fLogRes);
        //int  GetSysFont(TCHAR *FontName[]);
        bool CreateShowArea(int iWidth,int iHeight);
         bool Write(BYTE * lpBuf, DWORD dwToWrite);

};



#endif
