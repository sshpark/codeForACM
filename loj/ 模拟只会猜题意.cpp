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

const int N = 10005;

ll pa[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll n, m, x;

	while (~scanf("%lld %lld", &n, &m))
	{
		ms(pa);
		for (int i = 0; i < n; ++i)
		{

			scanf("%lld", &x);
			if (i == 0)
				pa[0] = x;
			else
				pa[i] = pa[i-1] + x;
		}
		// for (int i = 0; i < n; ++i)
		// 	printf("%lld ", pa[i]);
		// printf("\n");
		for (int i = 0; i < m; ++i)
		{
			scanf("%lld", &x);
			ll maxn = -inf;
			for (int j = 0; j < n; ++j)
			{
				for (int k = x+j-1; k < n; ++k)
				{
					maxn = max(pa[k]-pa[j] + 1, maxn);
				}
			}
			printf("%lld\n", maxn);
		}
	}

    return 0;
}