#include"fileSystem.h"
/*ȫ�ֱ���������*/
extern UOF uof[4];
extern MFD mfd[1];
extern UFD ufd[100];
extern int DISK; 
extern int INDEX;
extern int address;
extern int file_sign;
void write(int num, int byte)
{
	int temp = 5;//�����жϸ��ļ��Ƿ���uof��
	for (int i = 0; i < 4; i++)
	{
		if (ufd[num].filename == uof[i].filename && uof[i].state == 1)//��������������ʱ˵���ļ��ڴ�״̬���ɽ���д����
		{
			temp = i;
			break;
		}
	}
	if (temp < 5)//����ΪiС��5��tempҪ��i��ֵ���ͻ��������������˵���ļ��Ǵ�״̬
	{
		if (ufd[num].protect_way == 1)//�ж��ļ��ı�����ʽ
			cout << "û��дȨ��" << endl;
		else
		{
			//writeʵʩ
			uof[temp].current_length += byte;
			uof[temp].file_operation = "write";
			ufd[num].current_length += byte;
			cout << "�ļ���д" << endl;
		}
	}
	else//tempδ�ı䣬�ļ�δ��
		cout << "�ļ�δ��" << endl;
}
