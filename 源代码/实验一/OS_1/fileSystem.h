#include<iostream>
#include<string>
using namespace std;
 

/*文件结构体的构建*/

/*struct FCB
{
	char filename[12]; //文件名
	char attribute;//0表示目录,1表示数据文件
	int time;//创建时间
	int data;//创建日期
	int first;//起始盘号
	int length;//文件长度
	char free;//表示目录项是否为空
};*/
struct MFD
{
	string username;
	int user_address;
};

//用户目录结构体
struct UFD
{
	string filename;
	int protect_way;
	int current_length;
	int max_length;
	int file_address;
};

//用户打开表结构体
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
