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
#include <bitset>
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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
const int N = 256;
int n, m, ne, x, y, z;
int id[N], w[N], v[N], nxt[N], head[N], lch[N], rch[N], f[N];
int g[N][N];

void add(int x, int y, int z)
{
	id[++ne] = y; w[ne] = z; nxt[ne] = head[x]; head[x] = ne;
}

void dfs(int x)
{
	for (int p = head[x]; p; p = nxt[p])
	{
		if (id[p] != f[x])
		{
			if (!lch[x])
				lch[x] = id[p];
			else
				rch[x] = id[p];
			f[id[p]] = x;
			v[id[p]] = w[p];
			dfs(id[p]);
		}
	}
}
int dp(int x, int k)
{
	if (!k)
		return 0;
	if (g[x][k] > 0)
		return g[x][k];
	if (!lch[x])
		return g[x][k] = v[x];
	REP(i, 0, k)
	g[x][k] = max(g[x][k], dp(lch[x], i)+dp(rch[x], k-i-1));
	g[x][k] += v[x];
	return g[x][k];
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	

	while (~scanf("%d%d", &n, &m))
	{
		REP(i, 1, n)
		{
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
			add(y, x, z);
		}
		dfs(1);
		memset(g, 255, sizeof(g));
		printf("%d\n", dp(1, m+1));
	}

    return 0;
}