#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[105], re[105], cur[105];

void fuzhi(int start)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		re[i] = str[(start+i)%len];
	}
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < 105; i++)
			re[i] = '\0';
		fuzhi(0);
		int k = 0;
		for (int j = 1; j < len; j++)
		{
			k = 0;
			for (int i = 0; i < len; i++)
			{
				if (str[(j+i)%len] < re[k])
				{
					fuzhi(j);
					break;
				}
				if (str[(j+i)%len] > re[k])
					break;
				if (str[(j+i)%len] == re[k])
				{
					k++;
					continue;
				}
			}
		}
		printf("%s\n", re);
	}
	return 0;
}
