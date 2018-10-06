#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void open(int num, string mode)
{
	int temp;
	if (num >= file_sign || ufd[num].filename == " ")//当文件描述符大于已分配的描述符最大值不存在或者之前存在的文件被删除
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		if (INDEX == 4)//文件打开的数目进行判断
		{
			cout << "文件打开表已满,请进行关闭后再打开" << endl;
		}
		else//文件打开表还有空位时
		{
			for (int i = 0; i < 4; i++)
			{
				if (uof[i].state == 0)
				{
					temp = i;
					break;
				}
			}
			//把文件打开表进行填值
			uof[temp].read_pointer = ufd[num].file_address;
			uof[temp].filename = ufd[num].filename;
			uof[temp].file_operation = mode;
			uof[temp].write_pointer = ufd[num].file_address + ufd[num].max_length;
			uof[temp].current_length = ufd[num].current_length;
			uof[temp].file_location = DISK;
			uof[temp].state = 1;
			INDEX++;//文件打开数目增加
		}
	}
}