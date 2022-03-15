
#include"My_Algorithm.h"


int main()
{
	srand((unsigned)time(NULL));
	int a[105] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < 100; i++)
	{
		cout << Select(a, 0, 99, i + 1) << endl;
	}
	return 0;
}