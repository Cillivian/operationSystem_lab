#include"DOS.h"

extern int filenumber;//�ļ�����
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT���ʣ��ռ�

void showlist()
{
	int i;
	cout << "---�ļ�������" << filenumber << endl;
	cout << "---�ļ���---��ʼ��---�ļ�����" << endl;
	
	for (i = 0; i<filenumber; i++) {
		cout << "---"<< file[i].name <<"   "<< file[i].start <<"   "<< file[i].length <<endl;
		
	}
}