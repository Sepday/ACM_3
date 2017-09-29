#include<iostream>
#include <string.h>
#define maxn 3000
#define maxn2 100005
using namespace std;
int vid[maxn2], vis[maxn2],s[maxn], num;//vid存的是商，vis存的是余数,num存的是位数,s存的是被除数是否重复
int main()
{
	int a, b;
	while (cin>>a>>b&&b!=0)
	{
		num = 1;
		int m = a;
		memset(vid, 0, sizeof(vid));//商
		memset(vis, 0, sizeof(vis));//余   13 
		memset(s, 0, sizeof(s));


		//算出小点数前面的数字
		vid[0] = m / b;
		vis[0] = m%b;
		m = m%b;//m=b1
		//num已经为1,vis[1]不存在


		while (!s[m] && m)//当m没有重复,并且m不为0,为0是整除即没有循环小数
		{
			s[m] = num;//s[b1]=n1
			vid[num] = m * 10 / b;//vid[num]=a2
			vis[num++]=m * 10 % b;//vis[num]=b2,n2
			m = m * 10 % b;//m=b2
		}
		printf_s("%d/%d = %d.", a, b, vid[0]);//输出的含小数点

	
		if (!m)//如果是整除,则将小数部分全部取出;否的话，则要将循环小数前的取出
		{
			for (int i = 1; i <num; i++)
			{
				printf_s("%d", vid[i]);
			}
		}
		else
		{
			for (int i = 1; i < s[m]; i++)
			{
				printf_s("%d", vid[i]);
			}
		}


		printf_s("(");
		
		if (m)
		{
			for (int i = s[m]; i < num&&i < 51; i++)
			{
				printf_s("%d", vid[i]);
			}
			if (num> 50)
			{
				printf_s("...");
			}
		}
		else
		{
			printf_s("0");
		}
			
		printf_s(")");
		printf_s("\n   ");


		if (m)
		{
			printf_s("%d", num - s[m]);
		}
		else
		{
			printf_s("1");
		}
		printf_s(" = number of digits in repeating cycle\n");
	}
}