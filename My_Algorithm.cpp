
#include"My_Algorithm.h"
int Partition(int a[], int p, int r)    //Ĭ�ϻ��ֺ��� �������Ի�����Ϊ׼�ֳ����� �����ػ�������λ��
{
	int i = p, j = r + 1;
	int x = a[p];
	while (true)
	{
		while (a[++i] < x && i < j);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}


int Partition(int a[], int p, int r, int x)
{
	int i = p - 1, j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < j);
		while (a[--j] > x && i < j);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}

int RandomizedPartition(int a[], int p, int r)
{
	int i = MyRandom(p, r);
	Swap(a[i], a[p]);
	return Partition(a, p, r);
}

int RandomizedSelect(int a[], int p, int r, int k)
{ 
	if (p == r)
		return a[p];
	int i = RandomizedPartition(a, p, r);
	int j = i - p + 1;
	if (k <= j)
		return RandomizedSelect(a, p, i, k);
	else 
		return RandomizedSelect(a, i + 1, r, k - j);
}

int Select(int a[], int p, int r, int k)
{
	if ((r - p) < 75)
	{
		QuickSort(a, p, r);  //��ģ��С��ֱ�ӷ��أ�ʱ�临�Ӷ�Ϊ����
		return a[p + k - 1];
	}
	int n = r - p + 1;
	for (int i = 0; i < n / 5; i++)    //ÿ����Ԫ�أ��ɷ�n/5��(��ϸ�����һ��)
	{
		QuickSort(a, p + 5 * i, p + 5 * i + 4);		//��ÿ�������� a[p + 5 * i + 2] ��Ϊÿ����λ��
		Swap(a[i], a[p + 5 * i + 2]);				//�� ��λ���� �������У�
	}
	int x = Select(a, p, p + (n / 5 - 1), (n - 5) / 10);		//�ҳ���λ���ǵ���λ������Ϊ�Ǹ����ʵĻ�����
	int i = Partition(a, p, r, x);
	int j = i - p + 1;

	if (k <= j)
		return Select(a, p, i, k);
	else
		return Select(a, i + 1, r, k - j);
}


//int Select(int a[], int p, int r, int k)
//{
//	if ((r - p) < 75)
//	{
//		QuickSort(a, p, r);  //��ģ��С��ֱ�ӷ��أ�ʱ�临�Ӷ�Ϊ����
//		return a[p + k - 1];
//	}
//	for (int i = 0; i <= (r - p - 4) / 5; i++)    //ÿ����Ԫ�أ��ɷ�n/5��(��ϸ�����һ��)
//	{
//		QuickSort(a, p + 5 * i, p + 5 * i + 4);		//��ÿ�������� a[p + 5 * i + 2] ��Ϊÿ����λ��
//		Swap(a[i], a[p + 5 * i + 2]);				//�� ��λ���� �������У�
//	}
//	int x = Select(a, p, p + ( r - p - 4 / 5 ), (r- p - 4) / 10);		//�ҳ���λ���ǵ���λ������Ϊ�Ǹ����ʵĻ�����
//	int i = Partition(a, p, r, x);
//	int j = i - p + 1;
//
//	if (k <= j)
//		return Select(a, p, i, k);
//	else
//		return Select(a, i + 1, r, k - j);
//}

void QuickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}


int MyRandom(int i, int j)
{
	//default_random_engine e;
	//uniform_int_distribution<int> u(i, j); // ����ұ�����
	//e.seed(time(NULL));
	//return u(e);

	srand((unsigned)time(NULL));
	return i + rand() % (j - i + 1);
}


template <class T>
void Swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}
