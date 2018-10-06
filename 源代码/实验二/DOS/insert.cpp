#include"DOS.h"

extern int filenumber;//文件数量
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT表和剩余空间

void insert(char *tmpname, int insertpoint)
{
	int i;
	int last, brpoint;
	for (i = 0; i<filenumber; i++)//寻找要执行插入操作的文件，将其数组下标存入last
	{
		if (strcmp(file[i].name, tmpname) == 0)//比较插入文件名与已存在文件名是否相同 
		{
			last = i;
			break;
		}
		if ((i==filenumber)&& (strcmp(file[i].name, tmpname) != 0))
		{
			cout << "插入文件名不存在" << endl;
			return;
		}
	}
	brpoint = file[last].start;	//brpoint记录当前文件扫描到的位置
	for (i = 0; i<insertpoint - 1; i++)
	{
		brpoint = FAT[brpoint]; //扫描直到找到插入位置
	}
	for (i = 0; i<N; i++)//寻找一个空闲块插入
	{
		if (FAT[i] == 0)
		{
			FAT[i] = FAT[brpoint];
			FAT[brpoint] = i;
			break;
		}
	}
	file[last].length++;	//改变空闲块个数与文件长度
	freespace--;

	cout << "文件名：" << tmpname << "    文件长度：" << file[last].length << endl;
}