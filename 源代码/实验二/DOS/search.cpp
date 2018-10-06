#include"DOS.h"

extern int filenumber;//文件数量
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT表和剩余空间

void search(char *tmpname) {
	int i;
	for (i = 0; i<filenumber; i++)
	{
		if (strcmp(file[i].name, tmpname) == 0)//比较插入文件名与已存在文件名是否相同 
		{
			cout << "找到文件" << endl;
			cout << "---文件名---起始块---文件长度" << endl;
			cout << "---" << file[i].name << "   " << file[i].start << "   " << file[i].length << endl;
		}
		else
		{
			cout << "找不到相应文件" << endl;
		}
	}
}
