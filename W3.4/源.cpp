#include<iostream>
#include<string.h>
using namespace std;
#define maxn 90
int main()
{
	int a;
	cin >> a;
	while (a--)
	{
		char str[maxn];
		int res=90;
		bool temp = true;
		scanf_s("%s", str,80);
		int len;
		len = strlen(str);
		for (int i = 1; i <len; i++)
		{
			for (int j = 0; j < len-i; j++)
			{
				if ((len%i)||(str[j] != str[j + i]))
						temp = false;							
			}
			if (temp && (i < res))
				res = i;
			temp = true;
		}
		if (res == 90)
			res = len;
		cout << res << endl;
		if(a)cout << endl;
	}
	system("pause");
}
