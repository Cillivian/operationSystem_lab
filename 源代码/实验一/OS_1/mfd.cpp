#include"fileSystem.h"
/*全局变量的声明*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;

void do_mfd()
{
	cout << "----------------mfd-----------------------" << endl;
	cout << "username：" << mfd[0].username << " user address：" << mfd[0].user_address << endl;
}