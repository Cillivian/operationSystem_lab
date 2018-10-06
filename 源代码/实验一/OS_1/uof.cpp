#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;

void do_uof()
{
	cout << "----------------uof-----------------------" << endl;
	for (int i = 0; i < 4; i++)
		cout << "filename：" << uof[i].filename << " operation：" << uof[i].file_operation << " length：" << uof[i].current_length << " state：" << uof[i].state << endl;
}