#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	char str[1005];

	while (~scanf("%s", str))
	{
		int len = strlen(str), i = 0;
		for (i = 0; i < len; ++i)
			if (str[i] == '.')
				break;
		if (str[i-1] == '9')
		{
			puts("GOTO Vasilisa.");

		}
		else
		{
			int x = str[i+1] - '0';
			if (str[i+2] != '\0')
				x = x*10 + str[i+2] - '0';
			else
				x = x*10;
			if (x < 50)
				for (int j = 0; j < i; ++j)
					printf("%c", str[j]);
			else
			{
				for (int j = 0; j < i-1; ++j)
					printf("%c", str[j]);
				printf("%c", ++str[i-1]);
			}
			printf("\n");
		}	
		
	}

    return 0;
}