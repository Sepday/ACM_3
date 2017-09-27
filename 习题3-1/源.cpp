#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	cin >> a;	
	while (a--)
	{
		int p = 0, q = 0;
		char ch[90];
		scanf_s("%s", ch, 80);
		int tot = 0;
		for (int i = 0; i < strlen(ch); i++)
		{
			if (ch[i] == 'O')p += ++q;
			else if (ch[i] == 'X')q = 0;
		}
		printf("%d\n", p);
	}
}