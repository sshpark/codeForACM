#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int book[100005];

int main()
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.out", "w", stdout);
	int step, mod, kase = 0;

	while (cin >> step >> mod)
	{

		
		memset(book, 0, sizeof(book));
		
		int y = 1;
		for (int i = 0; i < mod; i++)
		{
			book[y] = 1;
			y = (y + step) % mod;
		}
		int flag = 0;
		for (int i = 0; i < mod; i++)
			if (book[i] == 0)
			{
				flag = 1;
				printf("%10d%10d    %s\n", step, mod, "Bad Choice");
				break;
			}
		if (!flag)
			printf("%10d%10d    %s\n", step, mod, "Good Choice");
		printf("\n");
	}
}