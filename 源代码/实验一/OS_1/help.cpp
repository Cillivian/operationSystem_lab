#include<iostream>
using namespace std;

void help()
{
	cout << "------------------------------------------" << endl;
	cout << "----------------help----------------------" << endl;
	cout << "create                    :-------创建文件" << endl;
	cout << "open                      :-------打开文件" << endl;
	cout << "read                      :-------读取文件" << endl;
	cout << "write                     :-------写入文件" << endl;
	cout << "close                     :-------关闭文件" << endl;
	cout << "delete                    :-------删除文件" << endl;
	cout << "uof                       :-------打开UOF" << endl;
	cout << "mfd                       :-------打开MFD" << endl;
	cout << "ufd                       :-------打开UFD" << endl;
	cout << "exit                      :-------关闭系统" << endl;
	cout << "note:    0----allocated;        1----free" << endl;
	cout << "mode:            1:可读, 2:可写, 3:可读写" << endl;
	cout << "-----------------------------------------" << endl;
}