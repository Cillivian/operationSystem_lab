#include"DOS.h"

extern int filenumber;//�ļ�����
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT���ʣ��ռ�

void insert(char *tmpname, int insertpoint)
{
	int i;
	int last, brpoint;
	for (i = 0; i<filenumber; i++)//Ѱ��Ҫִ�в���������ļ������������±����last
	{
		if (strcmp(file[i].name, tmpname) == 0)//�Ƚϲ����ļ������Ѵ����ļ����Ƿ���ͬ 
		{
			last = i;
			break;
		}
		if ((i==filenumber)&& (strcmp(file[i].name, tmpname) != 0))
		{
			cout << "�����ļ���������" << endl;
			return;
		}
	}
	brpoint = file[last].start;	//brpoint��¼��ǰ�ļ�ɨ�赽��λ��
	for (i = 0; i<insertpoint - 1; i++)
	{
		brpoint = FAT[brpoint]; //ɨ��ֱ���ҵ�����λ��
	}
	for (i = 0; i<N; i++)//Ѱ��һ�����п����
	{
		if (FAT[i] == 0)
		{
			FAT[i] = FAT[brpoint];
			FAT[brpoint] = i;
			break;
		}
	}
	file[last].length++;	//�ı���п�������ļ�����
	freespace--;

	cout << "�ļ�����" << tmpname << "    �ļ����ȣ�" << file[last].length << endl;
}