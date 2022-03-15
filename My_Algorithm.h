#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
#include<random>
using namespace std;

//**********************************************
//					分治法
//**********************************************

int Partition(int a[], int p, int r);	//默认 划分函数
int Partition(int a[], int p, int r, int x);	//自定义 划分函数
int RandomizedPartition(int a[], int p, int r);	 //随机划分函数
int RandomizedSelect(int a[], int p, int r, int k); //随机 线性时间选择
int Select(int a[], int p, int r, int k);
void QuickSort(int a[], int p, int r);




//****************************************************************************************************
//			小型函数
//****************************************************************************************************

int MyRandom(int i, int j);

template <class T>
void Swap(T& a, T& b);








