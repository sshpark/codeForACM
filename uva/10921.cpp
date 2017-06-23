#include <iostream>
#include <string.h>
using namespace std;
int judge(char c)
{
	if (c == 'A' || c == 'B' || c == 'C')
		return 2;
	if (c == 'D' || c == 'E' || c == 'F')
		return 3;
	if (c == 'G' || c == 'H' || c == 'I')
		return 4;
	if (c == 'J' || c == 'K' || c == 'L')
		return 5;
	if (c == 'M' || c == 'N' || c == 'O')
		return 6;
	if (c == 'P' || c == 'Q' || c == 'R' || c == 'S')
		return 7;
	if (c == 'T' || c == 'U' || c == 'V')
		return 8;
	else
		return 9;
}
int main()
{
	char str[35];
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/cqu/data.in", "r", stdin);
	while (~scanf("%s", str))
	{
		int len = strlen(str);

		for (int i = 0; i < len; ++i)
		{
			if (str[i] == '0' || str[i] == '1' || str[i] == '-')
				printf("%c", str[i]);
			else
				printf("%d", judge(str[i]));
		}
		printf("\n");
	}
}