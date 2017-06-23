#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int book[30];
int map(char c)
{
	if (c == 'B' || c == 'F' || c == 'V' || c == 'P')
		return 1;
	else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
		return 2;
	else if (c == 'D' || c == 'T')
		return 3;
	else if (c == 'L')
		return 4;
	else if (c == 'M' || c == 'N')
		return 5;
	else if (c == 'R')
		return 6;
	else
		return 0;
}
int main()
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.out", "w", stdout);
	char str[30];

	while (~scanf("%s", str))
	{
		memset(book, 0, sizeof(book));
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			book[i] = map(str[i]);
		for (int i = 0; i < len; i++)
		{
			if (book[i] != book[i+1] && book[i] != 0)
				printf("%d", book[i]);
			else if (book[i] == book[i+1] && book[i] != 0)
			{
				// printf("%d", book[i]);
				continue;
			}
		}
		printf("\n");
	}
	return 0;
}