#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void read(int num, int byte)
{
	int temp = 5;//�ж��ļ��Ƿ��
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)
	{
		if (ufd[num].protect_way == 2)//����ļ��ı�����ʽ
			cout << "�ļ����ɶ�" << endl;
		else
		{
			//read����
			uof[temp].file_operation = "read";
			cout << "�Ѷ�ȡ�ֽ���Ϊ��" << byte << endl;
		}
	}
	else
		cout << "�ļ�δ��" << endl;
}