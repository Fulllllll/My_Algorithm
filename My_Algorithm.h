#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
#include<random>
using namespace std;

//**********************************************
//					���η�
//**********************************************

int Partition(int a[], int p, int r);	//Ĭ�� ���ֺ���
int Partition(int a[], int p, int r, int x);	//�Զ��� ���ֺ���
int RandomizedPartition(int a[], int p, int r);	 //������ֺ���
int RandomizedSelect(int a[], int p, int r, int k); //��� ����ʱ��ѡ��
int Select(int a[], int p, int r, int k);
void QuickSort(int a[], int p, int r);




//****************************************************************************************************
//			С�ͺ���
//****************************************************************************************************

int MyRandom(int i, int j);

template <class T>
void Swap(T& a, T& b);








