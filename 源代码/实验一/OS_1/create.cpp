#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;

void create(string fileName, int maxByte, int mode)
{
	int temp;//����һ����������Ѱ��һ��uof�ձ���
	if (INDEX == 4)//�ȶ�uof��ʹ����������ж�
	{
		cout << "�ļ��򿪱�����,����йرպ��ٴ���" << endl;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (uof[i].state == 0)//stateֵΪ0˵����uof����Ϊ�տ��Խ�֮��Ϊcreate���ļ��򿪽��д���
			{
				temp = i;
				break;
			}
		}
		//��ufd��uof��ֵ
		ufd[file_sign].filename = fileName;
		ufd[file_sign].protect_way = mode;
		ufd[file_sign].max_length = maxByte;
		ufd[file_sign].current_length = 0;
		ufd[file_sign].file_address = address;
		uof[temp].read_pointer = address;
		address = address + maxByte;
		uof[temp].filename = fileName;
		uof[temp].file_operation = "create";
		uof[temp].write_pointer = address;
		uof[temp].current_length = 0;
		uof[temp].file_location = DISK;
		uof[temp].state = 1;
		DISK = DISK + maxByte / 64;//��������������һ������
		INDEX++;//�ļ�����Ŀ����
		cout << "�ļ������ɹ����ļ�������Ϊ��" << file_sign << endl;
		file_sign++;//�ļ������ɹ���Ŀ¼��һ
	}
}