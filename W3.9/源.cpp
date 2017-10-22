#include<iostream>
#include<string.h>
using namespace std;
#define maxn 100000

char s[maxn],t[maxn];
int main()
{
	while ((scanf_s("%s", s,100001) != EOF)&&(scanf_s("%s", t,100001) != EOF))
	{
		bool a = false;
		for (unsigned int i = 0; i < strlen(t); i++)
		{
			if (t[i] == s[0])
			{
				a = true;
				for (unsigned int j = 0; j < strlen(s); j++)
				{
					if (s[j] != t[i + j])
					{
						a = false;
					}
				}
			}
		}
		if (a)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

}