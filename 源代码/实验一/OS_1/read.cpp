#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void read(int num, int byte)
{
	int temp = 5;//判断文件是否打开
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)
	{
		if (ufd[num].protect_way == 2)//检测文件的保护方式
			cout << "文件不可读" << endl;
		else
		{
			//read操作
			uof[temp].file_operation = "read";
			cout << "已读取字节数为：" << byte << endl;
		}
	}
	else
		cout << "文件未打开" << endl;
}