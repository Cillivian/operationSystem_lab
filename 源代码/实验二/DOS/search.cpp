#include"DOS.h"

extern int filenumber;//�ļ�����
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT���ʣ��ռ�

void search(char *tmpname) {
	int i;
	for (i = 0; i<filenumber; i++)
	{
		if (strcmp(file[i].name, tmpname) == 0)//�Ƚϲ����ļ������Ѵ����ļ����Ƿ���ͬ 
		{
			cout << "�ҵ��ļ�" << endl;
			cout << "---�ļ���---��ʼ��---�ļ�����" << endl;
			cout << "---" << file[i].name << "   " << file[i].start << "   " << file[i].length << endl;
		}
		else
		{
			cout << "�Ҳ�����Ӧ�ļ�" << endl;
		}
	}
}
