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
		double tempc = 0; //���浱ǰ��ĸ�ķ�����
		int tempi=0;//��������
		int c=0;
		double res=0.0;
		while ((c = getchar()) != EOF && c != '\n')
		{
			int i;
			for ( i = 0; c != rev[i]; i++);//��ȡ�ַ��������λ��
			//cout << i << endl;
			if (i < 4)//������ĸʱ����Ҫͳ��һ�·������������浱ǰ��ĸ�ķ��������������ֻ���
			{
				if (tempi) res += tempi*tempc;
				else res += tempc;
				tempc = num[i];
				tempi = 0;
				//cout << res << endl;
			}
			else//��������ʱ��Ҫ�����ִ���tempi�У��ٶ�ȡ�ַ�
			{
				tempi = tempi * 10 + (c - '0');  
				continue;
			}
		}
		if (tempi) res += tempi*tempc;//����������ֽ�β����Ҫ���϶Է������ļ���
		else res += tempc;
		printf_s("%.3f\n", res);
	}
}