/*
为了完成猪头三讲师的在无名微型书中留的任务，同时也为了激励自己进步
是在这之前几天完成的
2013/7/7 by赫 
*/
#include "stdafx.h"
#define MAX 256


bool ReadFilePath(const wchar_t *DataFilePath);
void CreateTextToWideChar(FILE *stream);//建立一个临时转换为宽字符的文本
void CleanFile(FILE * stream);//清除函数
int _tmain(int argc, _TCHAR* argv[])
{
	_wsetlocale(LC_ALL, L"chs");
	ReadFilePath(L"C:\\alltemp_other.txt");

	getchar();
	return 0;
}
//读取unicode文件，并清除记录的垃圾文件
//参数1:日志文件路径
bool ReadFilePath(const wchar_t *DataFilePath)
{
    wchar_t ChBuffer = L'\0'; //将要从文件读取的单个字符
    wchar_t CleanFilePath[256] = L"\0"; //将要清除的垃圾文件路径
    DWORD ReadNumber = 0; //已经读取的路径拥有的字符数量
    DWORD dwReadSize = 100;//已经读取多少数据

    HANDLE handle_File = CreateFile(DataFilePath,
                                    GENERIC_READ,
                                    0,
                                    NULL,
                                    OPEN_EXISTING,
                                    FILE_ATTRIBUTE_NORMAL,
                                    NULL);
        
        while(ReadFile(handle_File,&ChBuffer,2,&dwReadSize,NULL))
        {
            if(dwReadSize == 0)
            {
                wprintf(L"检测到文件结尾\n");
                break;
            }

            if(ChBuffer == L'\r')
                continue;
            if(ChBuffer == L'\n')
            {
                CleanFilePath[ReadNumber] = L'\0';
                wprintf(L"已清除%s\n",CleanFilePath);
                DeleteFile(CleanFilePath);
                ReadNumber = 0;
            }
            else
                CleanFilePath[ReadNumber++] = ChBuffer;

        }
    // 释放文件对象资源
    CloseHandle(handle_File) ;
}
