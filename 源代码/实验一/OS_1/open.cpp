#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void open(int num, string mode)
{
	int temp;
	if (num >= file_sign || ufd[num].filename == " ")//���ļ������������ѷ�������������ֵ�����ڻ���֮ǰ���ڵ��ļ���ɾ��
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		if (INDEX == 4)//�ļ��򿪵���Ŀ�����ж�
		{
			cout << "�ļ��򿪱�����,����йرպ��ٴ�" << endl;
		}
		else//�ļ��򿪱��п�λʱ
		{
			for (int i = 0; i < 4; i++)
			{
				if (uof[i].state == 0)
				{
					temp = i;
					break;
				}
			}
			//���ļ��򿪱������ֵ
			uof[temp].read_pointer = ufd[num].file_address;
			uof[temp].filename = ufd[num].filename;
			uof[temp].file_operation = mode;
			uof[temp].write_pointer = ufd[num].file_address + ufd[num].max_length;
			uof[temp].current_length = ufd[num].current_length;
			uof[temp].file_location = DISK;
			uof[temp].state = 1;
			INDEX++;//�ļ�����Ŀ����
		}
	}
}