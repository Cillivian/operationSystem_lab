#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void delete_(string filename)
{
	int temp = 5;
	int k = 0;
	for (int i = 0; i < 4; i++)//判断文件是否打开
	{
		if (uof[i].filename == filename && uof[i].state == 1)
		{
			temp = i;
			break;
		}
	}
	if (temp == 5)
	{
		for (int i = 1; i <= file_sign; i++)//和判断文件是否打开相似的方式，引入变量k，每次循环都增大k直到最后k=file_sign都未终止时，说明未找到这个名字的文件
		{
			if (ufd[i].filename == filename)
			{
				/*清除文件*/
				ufd[i].filename = " ";
				ufd[i].protect_way = 0;
				ufd[i].max_length = 0;
				ufd[i].current_length = 0;
				ufd[i].file_address = 0;
				cout << "文件成功删除" << endl;
				break;
			}
			k = i;
		}
		if (k == file_sign)
		{
			cout << "未找到该文件，请确认文件名" << endl;
			return;
		}
	
	}
	else
		cout << "文件还未关闭，关闭后再删除" << endl;
}