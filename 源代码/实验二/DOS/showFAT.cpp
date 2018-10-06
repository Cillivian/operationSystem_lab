#include"DOS.h"

extern int filenumber;//文件数量
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT表和剩余空间
void showFAT()
{
	int i;
	
	cout << "---空闲块总数：" << freespace << endl;
	cout << "---(-2代表FDF,-1代表FFF)" << endl;
	cout<<"---块号---状态---"<<endl;
	for (i = 0; i<N; i++) {
		
		cout << "---" << i << "---" << FAT[i] <<"---" <<endl;
	}
}