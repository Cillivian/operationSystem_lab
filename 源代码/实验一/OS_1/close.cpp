#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void close(int num)
{
	int temp = 5;
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)/*�����ж��ļ�λ��*/
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)
	{
		//close����
		uof[temp].state = 0;
		uof[temp].filename = " ";
		uof[temp].file_operation = " ";
		uof[temp].current_length = NULL;
		uof[temp].file_location = NULL;
		uof[temp].read_pointer = NULL;
		uof[temp].write_pointer = NULL;
		INDEX--;
		cout << "�ļ����ѹر�" << endl;
	}
	else
		cout << "�ļ�δ��" << endl;
}