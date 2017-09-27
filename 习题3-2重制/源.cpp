#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

#define maxn 100
int main()
{
	const char rev[] = "CHON0123456789";
	const double num[] = { 12.01, 1.008, 16.00, 14.01 };
	int a, b;
	cin >> a;
	while (a--)
	{
		double tempc = 0;
		int tempi = 0;
		char c[maxn];
		double res = 0.0;
		scanf_s("%s", c,80);
		for (int j = 0; j < strlen(c);j++)
		{
			int i;
			for (i = 0; c[j] != rev[i]; i++);
			if (i < 4)
			{
				if (tempi) res += tempi*tempc;
				else res += tempc;
				tempc = num[i];
				tempi = 0;

			}
			else
			{
				tempi = tempi * 10 + (c[j] - '0');
				continue;
			}
		}
		if (tempi) res += tempi*tempc;
		else res += tempc;
		printf("%.3f\n", res);
	}
}
