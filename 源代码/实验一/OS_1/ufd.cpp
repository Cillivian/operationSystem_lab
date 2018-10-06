#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;

void do_ufd()
{
	cout << "----------------ufd-----------------------" << endl;
	for (int i = 1; i < file_sign; i++)
		cout << "filename：" << ufd[i].filename << " mode：" << ufd[i].protect_way << " current length：" << ufd[i].current_length << endl;
}