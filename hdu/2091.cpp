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

	char c;
	int n, kase = 0;

	while (~scanf("%c %d", &c, &n))
	{
			
		if (c == '@')
			break;
		if (kase++ != 0)
		printf("\n");
		int i, j;
		for (i = 1; i < n; i++)	
		{
			for (j = 1; j <= n - i; j++)
				printf(" ");
			printf("%c", c);
			if (i == 1)
			{
				printf("\n");
				continue;
			}
			for (int k = 1; k <= 2*(i-1)-1; k++)
				printf(" ");
			printf("%c", c);
			printf("\n");
		}
		for (i = 1; i <= 2*n-1; i++)
			printf("%c", c);
		printf("\n");
		getchar();
	}

    return 0;
}