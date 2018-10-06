#include"DOS.h"

extern int filenumber;//文件数量
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT表和剩余空间

void showlist()
{
	int i;
	cout << "---文件总数：" << filenumber << endl;
	cout << "---文件名---起始块---文件长度" << endl;
	
	for (i = 0; i<filenumber; i++) {
		cout << "---"<< file[i].name <<"   "<< file[i].start <<"   "<< file[i].length <<endl;
		
	}
}