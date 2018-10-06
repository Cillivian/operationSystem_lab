#include"DOS.h"

/*全局变量*/

 int filenumber;//文件数量
FILEINFO file[10];
int FAT[N];
int freespace; //FAT表和剩余空间
/*函数原型*/
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
	int tmplength;//要写入文件长度
	string cmd;//命令
	filenumber = 0;
	for (i = 0; i<N; i++) {  //初始化FAT表
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

			cout << "文件名>";
			cin >> tmpname;
			cout << "文件长度>";
			cin >> tmplength;
			write(tmpname, tmplength);

		}
		else if (cmd == "insert")
		{
			cout << "输入插入文件名>";
			cin >> tmpname;
			int insertpoint;
			cout << "要插入到节点>";
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
			
			cout << "输入要搜索的文件名>";
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
			cout << "输入有误，请输入正确指令，输入‘help’获取帮助信息" << endl;
		}
	}
	showFAT();
}
