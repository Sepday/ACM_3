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
		unsigned int k = 0;
		for (unsigned int i = 0; i < strlen(s); i++)
		{
				for (unsigned int j = k; j < strlen(t); j++)
				{
					if (s[i] == t[j])
					{
						a = true;
						k = j+1;
						break;
					}
					a = false;
				}
				if (!a)
				{
					break;
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