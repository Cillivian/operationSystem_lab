#include"DOS.h"

extern int filenumber;//�ļ�����
extern FILEINFO file[10];
extern int FAT[N];
extern int freespace; //FAT���ʣ��ռ�
void showFAT()
{
	int i;
	
	cout << "---���п�������" << freespace << endl;
	cout << "---(-2����FDF,-1����FFF)" << endl;
	cout<<"---���---״̬---"<<endl;
	for (i = 0; i<N; i++) {
		
		cout << "---" << i << "---" << FAT[i] <<"---" <<endl;
	}
}