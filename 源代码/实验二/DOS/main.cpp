#include"DOS.h"

/*ȫ�ֱ���*/

 int filenumber;//�ļ�����
FILEINFO file[10];
int FAT[N];
int freespace; //FAT���ʣ��ռ�
/*����ԭ��*/
void showlist();
void showFAT();
void search(char *tmpname);

void write(char *tmpname, int tmplength);
void insert(char *tmpname, int insertpoint);
void help();

int main()
{
	int i;
	char tmpname[10];
	int tmplength;//Ҫд���ļ�����
	string cmd;//����
	filenumber = 0;
	for (i = 0; i<N; i++) {  //��ʼ��FAT��
		FAT[i] = 0;
	}
	FAT[0] = FDF;
	FAT[1] = FFF;
	//FAT[3]=999;
	freespace = 98;
	cout << "-----------------------welcome to System-------------------" << endl;
	cout << "------------input 'help' get more information--------------" << endl;
	while (true) {
		cout << ">";
		cin >> cmd;
		if (cmd == "write")
		{

			cout << "�ļ���>";
			cin >> tmpname;
			cout << "�ļ�����>";
			cin >> tmplength;
			write(tmpname, tmplength);

		}
		else if (cmd == "insert")
		{
			cout << "��������ļ���>";
			cin >> tmpname;
			int insertpoint;
			cout << "Ҫ���뵽�ڵ�>";
			cin >> insertpoint;
			insert(tmpname, insertpoint);

		}
		else if (cmd == "list")
		{
			showlist();
		}
		else if (cmd == "FAT")
		{
			showFAT();
		}
		else if (cmd == "search")
		{
			
			cout << "����Ҫ�������ļ���>";
			cin >> tmpname;
			search(tmpname);
		}
		
		else if(cmd=="exit")
		{
			exit(0);
		}
		else if (cmd == "help")
		{
			help();
		}
		else
		{
			cout << "����������������ȷָ����롮help����ȡ������Ϣ" << endl;
		}
	}
	showFAT();
}
