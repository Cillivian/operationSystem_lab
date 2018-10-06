#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<string>
#define FDF -2
#define FFF -1
#define N 100//存储空间(FAT表长度)
using namespace std;
#pragma warning(disable:4996)


struct FILEINFO {
	char name[10];
	int start;
	int length;
};


