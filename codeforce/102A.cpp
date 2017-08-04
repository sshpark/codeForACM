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

int e[105][105];
int a[105];
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m;

	while (~scanf("%d %d", &n, &m))
	{
		ms(e);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		int f, s;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d %d", &f, &s);
			e[f][s] = e[s][f] = 1;
		}
		int sum = inf;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; j++)
				if (e[i][j] == 1)
				{
					for (int k = 1; k <= n; k++)
					{
						if (e[i][j] && e[i][k] && e[j][k])
						{
							if (sum > a[i]+a[j]+a[k])
								sum = a[i]+a[j]+a[k];
						}
					}
				}
		}
		if (sum != inf)
			printf("%d\n", sum);
		else
			puts("-1");
		
	}

    return 0;
}