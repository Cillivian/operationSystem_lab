#include"fileSystem.h"


//����ȫ�ֱ���
UOF uof[4];
MFD mfd[1];
UFD ufd[100];
//��ʼ������
int DISK = 10;//ģ���̷����������ʼ��Ϊ10
int INDEX = 0;//���ļ�����Ŀ
int address = 1;//��ַ�ĳ�ʼ
int file_sign = 1;//��ǽ������ļ���Ŀ

/*********************************����ԭ��***************************************/
void init();//��ʼ������
void create(string filename, int maxByte, int mode);//�����ļ�����
void write(int num, int byte);//д���ļ�����
void close(int num);//�ر��ļ�����
void open(int num, string mode);//���ļ�����
void read(int num, int byte);//��ȡ�ļ�����
void delete_(string filename);//ɾ���ļ�����
void do_uof();//�鿴uof����
void do_ufd();//�鿴ufd����
void do_mfd();//�鿴mfd����
void help();//������Ϣҳ��
//uof��ʼ������
void init()
{
	for (int i = 0; i < 4; i++)
		uof[i].state = 0;
}

int main()
{
	string cmd;//����ָ��
	//MFD������
	mfd[0].username = "user";
	mfd[0].user_address = 0;
	//����ָ��
	cout << "welcome to fileSystem input 'help' get more information" << endl;
	while (1)
	{
		cout << mfd[0].username+">";
		cin >> cmd;
		
		if (cmd == "help")
		{
			help();//������Ϣ
		}
		else if (cmd == "create")
		{
			cout << "----------------create--------------------" << endl;
			string filename;//�ļ���
			int maxByte;//����ֽ�
			int mode;//�ļ�ģʽ
			cout << "�ļ���>" ;
			cin >> filename;
			cout << "����ֽ�>" ;
			cin >> maxByte;
			cout << "�ļ�ģʽ>";
			cin >> mode;
			create(filename, maxByte, mode);
		}
		else if (cmd == "write")
		{
			int num;//������
			int byte;//д���ַ���С
			cout << "----------------write---------------------"<<endl ;
			cout << "�ļ�������>";
			cin >> num;
			cout << "д���ֽ���>";
			cin >> byte;
			write(num, byte);
		}
		else if (cmd == "open")
		{
			int num;//������
			string operation;//�򿪲���
			cout << "----------------open----------------------" << endl;
			cout << "�ļ�������>";
			cin >> num;
			cout << "�򿪷�ʽ>";
			cin >> operation;
			open(num, operation);
		}
		else if (cmd == "read")
		{
			int num;//������
			int byte;//������������
			cout << "----------------read----------------------" << endl;
			cout << "�ļ�������>";
			cin >> num;
			cout << "��ȡ�ֽ���>";
			cin >> byte;
			read(num, byte);
		}
		else if (cmd == "close")
		{

			int num;//������
			cout << "----------------close---------------------" << endl;
			cout << "�ļ�������>";
			cin >>num;
			close(num);
		}
		else if (cmd == "delete")
		{

			string filename;//�ļ���
			cout << "----------------delete--------------------" << endl;
			cout << "�ļ���>";
			cin >> filename;
			delete_(filename);
		}
		
		else if (cmd == "uof")
		{
			do_uof();
		}
		else if (cmd == "ufd")
		{
			do_ufd();
		}
		else if (cmd == "mfd")
		{
			do_mfd();
		}
		else if (cmd=="exit")
		{
			break;
		}
		else
		{
			cout << "ָ���������󣬿����롮help���鿴" << endl;
		}
	}
}