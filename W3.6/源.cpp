#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 11
int main()
{
	int t = 0;
	int x, y;
	char a[maxn][maxn];
	int index[maxn][maxn];
	memset(index, 0, sizeof(index));
	while (cin>>x&&x)
	{
		int temp = 0;
		memset(index, 0, sizeof(index));	
		cin >>  y;
		for (int x2 = 0; x2 < x;x2++)//输入puzzle
			cin>>a[x2];

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if ((i == 0 || j == 0 || a[i - 1][j] == '*' || a[i][j - 1] == '*') && a[i][j] != '*')
				{
					temp++;
					index[i][j] = temp;
				}
			} 
		}
		
		if (t++)
		cout << endl;
		cout << "puzzle #" << t << ":" << endl;
		cout << "Across\n";
		for (int i = 0; i < x; i++)
		{
			int move = 0;
			while(move<y)
			{
				//cout << "here1" << endl;
				if (index[i][move])
				{
					//cout << "HERE2" << endl;
					printf_s("%3d.", index[i][move]);
					while (move < y && a[i][move] != '*')
						printf_s("%c", a[i][move++]);
					cout << endl;
				}
				else
				{
					//cout << "HERE3" << endl;
					move++;
				}
				//cout << "HERE4" << endl;
				//cout << move << endl;
			}
			//cout << "here5" << endl;
		}
		
		cout << "Down\n";
		for (int i = 0; i < x; i++)//从第一排到最后一排
		{		
				int move_x = i;
				int move_y = 0;
				while (move_y < y)//当列游标还没到最后一列时
				{
					if (index[move_x][move_y])//如果游标所到位置为起始位即值不为0时
					{
						printf_s("%3d.", index[move_x][move_y]);//输出起始位编号
						while (move_x < x&&a[move_x][move_y] != '*')//当排游标还没到最后一排且游标当前位置不是*时
						{
							index[move_x][move_y] = 0;//将当前起始位设为0，防止重复输出
							printf_s("%c", a[move_x++][move_y]);	//输出当前游标位的值且排游标自增1
						}
						move_y++;
						move_x = i;
						cout << endl;
					}
					else move_y++;//否则增加列游标
				}		
		}
	}
}