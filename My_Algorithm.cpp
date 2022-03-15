
#include"My_Algorithm.h"
int Partition(int a[], int p, int r)    //默认划分函数 将数组以划分数为准分成两部 并返回划分数的位置
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
		QuickSort(a, p, r);  //规模较小，直接返回，时间复杂度为常数
		return a[p + k - 1];
	}
	int n = r - p + 1;
	for (int i = 0; i < n / 5; i++)    //每组五元素，可分n/5组(不细分最后一组)
	{
		QuickSort(a, p + 5 * i, p + 5 * i + 4);		//将每组排序，则 a[p + 5 * i + 2] 则为每组中位数
		Swap(a[i], a[p + 5 * i + 2]);				//将 中位数们 相邻排列，
	}
	int x = Select(a, p, p + (n / 5 - 1), (n - 5) / 10);		//找出中位数们的中位数，即为那个合适的划分数
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
//		QuickSort(a, p, r);  //规模较小，直接返回，时间复杂度为常数
//		return a[p + k - 1];
//	}
//	for (int i = 0; i <= (r - p - 4) / 5; i++)    //每组五元素，可分n/5组(不细分最后一组)
//	{
//		QuickSort(a, p + 5 * i, p + 5 * i + 4);		//将每组排序，则 a[p + 5 * i + 2] 则为每组中位数
//		Swap(a[i], a[p + 5 * i + 2]);				//将 中位数们 相邻排列，
//	}
//	int x = Select(a, p, p + ( r - p - 4 / 5 ), (r- p - 4) / 10);		//找出中位数们的中位数，即为那个合适的划分数
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
	//uniform_int_distribution<int> u(i, j); // 左闭右闭区间
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
