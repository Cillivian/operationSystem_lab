#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK; 
extern int INDEX;
extern int address;
extern int file_sign;
void write(int num, int byte)
{
	int temp = 5;//用于判断该文件是否在uof中
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)//满足这两个条件时说明文件在打开状态，可进行写操作
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)//又因为i小于5，temp要和i等值，就会满足这个条件，说明文件是打开状态
	{
		if (ufd[num].protect_way == 1)//判断文件的保护方式
			cout << "没有写权限" << endl;
		else
		{
			//write实施
			uof[temp].current_length += byte;
			uof[temp].file_operation = "write";
			ufd[num].current_length += byte;
			cout << "文件已写" << endl;
		}
	}
	else//temp未改变，文件未打开
		cout << "文件未打开" << endl;
}
