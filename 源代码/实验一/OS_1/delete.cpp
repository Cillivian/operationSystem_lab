#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK;
extern int INDEX;
extern int address;
extern int file_sign;
void delete_(string filename)
{
	int temp = 5;
	int k = 0;
	for (int i = 0; i < 4; i++)//�ж��ļ��Ƿ��
	{
		if (uof[i].filename == filename && uof[i].state == 1)
		{
			temp = i;
			break;
		}
	}
	if (temp == 5)
	{
		for (int i = 1; i <= file_sign; i++)//���ж��ļ��Ƿ�����Ƶķ�ʽ���������k��ÿ��ѭ��������kֱ�����k=file_sign��δ��ֹʱ��˵��δ�ҵ�������ֵ��ļ�
		{
			if (ufd[i].filename == filename)
			{
				/*����ļ�*/
				ufd[i].filename = " ";
				ufd[i].protect_way = 0;
				ufd[i].max_length = 0;
				ufd[i].current_length = 0;
				ufd[i].file_address = 0;
				cout << "�ļ��ɹ�ɾ��" << endl;
				break;
			}
			k = i;
		}
		if (k == file_sign)
		{
			cout << "δ�ҵ����ļ�����ȷ���ļ���" << endl;
			return;
		}
	
	}
	else
		cout << "�ļ���δ�رգ��رպ���ɾ��" << endl;
}