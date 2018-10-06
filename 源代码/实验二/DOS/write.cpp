#include"DOS.h"

extern int filenumber;//文件数量
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT表和剩余空间
void write(char *tmpname, int tmplength)
{
	int last, i, j;
	strcpy(file[filenumber].name, tmpname);//复制文件名和文件块个数
	file[filenumber].length = tmplength;
	for (i = 2; i<N; i++) {	//存文件
		if (FAT[i] == 0) {
			file[filenumber].start = i;//首个空闲块为文件开始块
			last = i;
			FAT[last] = FFF;
			break;
		}
	}
	for (i = 1; i<tmplength; i++) {	//last为上个记录的位置
		for (j = 2; j<N; j++)
			if (FAT[j] == 0) {
				FAT[last] = j;
				last = j;
				FAT[last] = FFF;
				break;
			}
	}
	FAT[last] = FFF;//文件末存结束标记
	freespace -= tmplength;//改变空闲块个数
	filenumber++;
	
	cout << "文件名："<<tmpname<<"    文件长度："<<tmplength<< endl;
	
}