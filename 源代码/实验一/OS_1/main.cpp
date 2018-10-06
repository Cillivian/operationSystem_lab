#include"fileSystem.h"


//定义全局变量
UOF uof[4];
MFD mfd[1];
UFD ufd[100];
//初始化变量
int DISK = 10;//模拟盘分配情况，初始化为10
int INDEX = 0;//打开文件的数目
int address = 1;//地址的初始
int file_sign = 1;//标记建立了文件数目

/*********************************函数原型***************************************/
void init();//初始化函数
void create(string filename, int maxByte, int mode);//创建文件函数
void write(int num, int byte);//写入文件函数
void close(int num);//关闭文件函数
void open(int num, string mode);//打开文件函数
void read(int num, int byte);//读取文件函数
void delete_(string filename);//删除文件函数
void do_uof();//查看uof函数
void do_ufd();//查看ufd函数
void do_mfd();//查看mfd函数
void help();//帮助信息页面
//uof初始化函数
void init()
{
	for (int i = 0; i < 4; i++)
		uof[i].state = 0;
}

int main()
{
	string cmd;//命令指令
	//MFD的生成
	mfd[0].username = "user";
	mfd[0].user_address = 0;
	//输入指令
	cout << "welcome to fileSystem input 'help' get more information" << endl;
	while (1)
	{
		cout << mfd[0].username+">";
		cin >> cmd;
		
		if (cmd == "help")
		{
			help();//帮助信息
		}
		else if (cmd == "create")
		{
			cout << "----------------create--------------------" << endl;
			string filename;//文件名
			int maxByte;//最大字节
			int mode;//文件模式
			cout << "文件名>" ;
			cin >> filename;
			cout << "最大字节>" ;
			cin >> maxByte;
			cout << "文件模式>";
			cin >> mode;
			create(filename, maxByte, mode);
		}
		else if (cmd == "write")
		{
			int num;//描述符
			int byte;//写入字符大小
			cout << "----------------write---------------------"<<endl ;
			cout << "文件描述符>";
			cin >> num;
			cout << "写入字节数>";
			cin >> byte;
			write(num, byte);
		}
		else if (cmd == "open")
		{
			int num;//描述符
			string operation;//打开操作
			cout << "----------------open----------------------" << endl;
			cout << "文件描述符>";
			cin >> num;
			cout << "打开方式>";
			cin >> operation;
			open(num, operation);
		}
		else if (cmd == "read")
		{
			int num;//描述符
			int byte;//用于描述输入
			cout << "----------------read----------------------" << endl;
			cout << "文件描述符>";
			cin >> num;
			cout << "读取字节数>";
			cin >> byte;
			read(num, byte);
		}
		else if (cmd == "close")
		{

			int num;//描述符
			cout << "----------------close---------------------" << endl;
			cout << "文件描述符>";
			cin >>num;
			close(num);
		}
		else if (cmd == "delete")
		{

			string filename;//文件名
			cout << "----------------delete--------------------" << endl;
			cout << "文件名>";
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
			cout << "指令输入有误，可输入‘help’查看" << endl;
		}
	}
}