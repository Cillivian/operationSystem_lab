#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;

void create(string fileName, int maxByte, int mode)
{
	int temp;//定义一个变量用于寻找一个uof空表项
	if (INDEX == 4)//先对uof的使用情况进行判断
	{
		cout << "文件打开表已满,请进行关闭后再创建" << endl;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (uof[i].state == 0)//state值为0说明该uof表项为空可以将之作为create的文件打开进行存入
			{
				temp = i;
				break;
			}
		}
		//对ufd和uof赋值
		ufd[file_sign].filename = fileName;
		ufd[file_sign].protect_way = mode;
		ufd[file_sign].max_length = maxByte;
		ufd[file_sign].current_length = 0;
		ufd[file_sign].file_address = address;
		uof[temp].read_pointer = address;
		address = address + maxByte;
		uof[temp].filename = fileName;
		uof[temp].file_operation = "create";
		uof[temp].write_pointer = address;
		uof[temp].current_length = 0;
		uof[temp].file_location = DISK;
		uof[temp].state = 1;
		DISK = DISK + maxByte / 64;//块的连续分配进行一个调整
		INDEX++;//文件打开数目增加
		cout << "文件创建成功，文件描述符为：" << file_sign << endl;
		file_sign++;//文件创建成功，目录加一
	}
}