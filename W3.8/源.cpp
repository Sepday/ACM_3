#include<iostream>
#include <string.h>
#define maxn 3000
#define maxn2 100005
using namespace std;
int vid[maxn2], vis[maxn2],s[maxn], num;//vid������̣�vis���������,num�����λ��,s����Ǳ������Ƿ��ظ�
int main()
{
	int a, b;
	while (cin>>a>>b&&b!=0)
	{
		num = 1;
		int m = a;
		memset(vid, 0, sizeof(vid));//��
		memset(vis, 0, sizeof(vis));//��   13 
		memset(s, 0, sizeof(s));


		//���С����ǰ�������
		vid[0] = m / b;
		vis[0] = m%b;
		m = m%b;//m=b1
		//num�Ѿ�Ϊ1,vis[1]������


		while (!s[m] && m)//��mû���ظ�,����m��Ϊ0,Ϊ0��������û��ѭ��С��
		{
			s[m] = num;//s[b1]=n1
			vid[num] = m * 10 / b;//vid[num]=a2
			vis[num++]=m * 10 % b;//vis[num]=b2,n2
			m = m * 10 % b;//m=b2
		}
		printf_s("%d/%d = %d.", a, b, vid[0]);//����ĺ�С����

	
		if (!m)//���������,��С������ȫ��ȡ��;��Ļ�����Ҫ��ѭ��С��ǰ��ȡ��
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