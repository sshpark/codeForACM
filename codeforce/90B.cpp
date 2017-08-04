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

char e[105][105], re[105][105];



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m;
	char str[105];
	while (~scanf("%d %d", &n, &m))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < m; j++)
			{
				e[i][j] = str[j];
				re[i][j] = str[j];
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				
				for (int k = 0; k < n; k++)
					if (e[k][j] == e[i][j] && k != i)
						re[k][j] = '1';
				for (int k = 0; k < m; k++)
					if (e[i][k] == e[i][j] && k != j)
						re[i][k] = '1';
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (re[i][j] != '1')
					printf("%c", re[i][j]);
		printf("\n");
	}

    return 0;
}