#include<iostream>
#include<string.h>
using namespace std;

char DNA[50][1001];
const char item[]{ 'A', 'C', 'G', 'T' };
int sum[4];
int total[50];
char maxItem()
{
	int a = sum[0];
	int b = 0;
	if (a < sum[1])
	{
		a = sum[1];
		b = 1;
	}	
	else if (a < sum[2])
	{
		a = sum[2];
		b = 2;
	}
	else if (a < sum[3])
	{
		a = sum[3];
		b = 3;
	}
	return item[b];
}

int main()
{
	memset(sum, 0, sizeof(sum));
	int a;
	cin >> a;
	while (a--)
	{
		memset(DNA, 0, sizeof(DNA));
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			scanf("%s",DNA[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				switch (DNA[m][n])
				{
					case 'A':
						sum[0]++;
						break;
					case 'C':
						sum[1]++;
						break;
					case 'G':
						sum[2]++;
						break;
					case 'T':
						sum[3]++;
						break;
				}
			}
		 }
		 
	}
}

