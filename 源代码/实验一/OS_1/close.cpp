#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void close(int num)
{
	int temp = 5;
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)/*检索判定文件位置*/
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)
	{
		//close操作
		uof[temp].state = 0;
		uof[temp].filename = " ";
		uof[temp].file_operation = " ";
		uof[temp].current_length = NULL;
		uof[temp].file_location = NULL;
		uof[temp].read_pointer = NULL;
		uof[temp].write_pointer = NULL;
		INDEX--;
		cout << "文件以已关闭" << endl;
	}
	else
		cout << "文件未打开" << endl;
}