#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int getsum(int n)
{
	int sum = 0;
	while (n != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int getcharsum(char *str)
{
	int sum = 0;
	for (int i = 0; i < strlen(str); i++)
		sum += str[i] - '0';
	return sum;
}

int main()
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	
	char str[1005];
	int n;
	while (scanf("%s", str) != EOF)
	{
		if (str[0] == '0')
			break;
		int depth = 1;

		n = getcharsum(str);

		if (n % 9 != 0)
		{
			printf("%s is not a multiple of 9.\n", str);
			continue;
		}

		while (true)
		{
			if (n == 9 || n % 9 != 0)
			{
				break;
			}
			if (getsum(n) % 9 == 0)
			{
				depth++;
				n = getsum(n);
			}
			
		}
		printf("%s is a multiple of 9 and has 9-degree %d.\n", str, depth);
	}
}