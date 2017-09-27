#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	const char rev[]= "CHON0123456789";
	const double num[] = { 12.01, 1.008, 16.00, 14.01 };
	int a,b;
	cin >> a;
	while ((b = getchar()) != EOF && b != '\n');
	while (a--)
	{
		double tempc = 0; //缓存当前字母的分子量
		int tempi=0;//缓存数字
		int c=0;
		double res=0.0;
		while ((c = getchar()) != EOF && c != '\n')
		{
			int i;
			for ( i = 0; c != rev[i]; i++);//获取字符在数组的位置
			//cout << i << endl;
			if (i < 4)//遇到字母时，就要统计一下分子量，并缓存当前字母的分子量并清零数字缓存
			{
				if (tempi) res += tempi*tempc;
				else res += tempc;
				tempc = num[i];
				tempi = 0;
				//cout << res << endl;
			}
			else//遇到数字时，要将数字存入tempi中，再读取字符
			{
				tempi = tempi * 10 + (c - '0');  
				continue;
			}
		}
		if (tempi) res += tempi*tempc;//如果是以数字结尾，就要补上对分子量的计算
		else res += tempc;
		printf_s("%.3f\n", res);
	}
}