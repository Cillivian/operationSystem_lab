#include"DOS.h"

extern int filenumber;//�ļ�����
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT���ʣ��ռ�
void write(char *tmpname, int tmplength)
{
	int last, i, j;
	strcpy(file[filenumber].name, tmpname);//�����ļ������ļ������
	file[filenumber].length = tmplength;
	for (i = 2; i<N; i++) {	//���ļ�
		if (FAT[i] == 0) {
			file[filenumber].start = i;//�׸����п�Ϊ�ļ���ʼ��
			last = i;
			FAT[last] = FFF;
			break;
		}
	}
	for (i = 1; i<tmplength; i++) {	//lastΪ�ϸ���¼��λ��
		for (j = 2; j<N; j++)
			if (FAT[j] == 0) {
				FAT[last] = j;
				last = j;
				FAT[last] = FFF;
				break;
			}
	}
	FAT[last] = FFF;//�ļ�ĩ��������
	freespace -= tmplength;//�ı���п����
	filenumber++;
	
	cout << "�ļ�����"<<tmpname<<"    �ļ����ȣ�"<<tmplength<< endl;
	
}