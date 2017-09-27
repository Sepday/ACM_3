#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int num[10001][10];
	memset(num, 0, sizeof(num));
	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			num[i][j] = num[i - 1][j];
			int left = i;
			while (left)
			{
				num[i][left % 10]++;
				left /= 10;
			}
		}
	}
	int a,n;
	cin >> a;
	while (a--)
	{
		scanf_s("%d", &n);
		for (int i = 0; i < 9; i++)
			printf_s("%d ", num[n][i]);
			printf_s("%d\n", num[n][9]);
	}
	system("pause");
}