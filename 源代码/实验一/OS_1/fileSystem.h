#include<iostream>
#include<string>
using namespace std;
 

/*�ļ��ṹ��Ĺ���*/

/*struct FCB
{
	char filename[12]; //�ļ���
	char attribute;//0��ʾĿ¼,1��ʾ�����ļ�
	int time;//����ʱ��
	int data;//��������
	int first;//��ʼ�̺�
	int length;//�ļ�����
	char free;//��ʾĿ¼���Ƿ�Ϊ��
};*/
struct MFD
{
	string username;
	int user_address;
};

//�û�Ŀ¼�ṹ��
struct UFD
{
	string filename;
	int protect_way;
	int current_length;
	int max_length;
	int file_address;
};

//�û��򿪱�ṹ��
struct UOF
{
	//FCB fcb;
	string filename;
	string file_operation;
	int read_pointer;
	int write_pointer;
	int current_length;
	int file_location;
	int state;
};
