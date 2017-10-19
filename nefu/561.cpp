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
int n, m;
int nxt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char e[25][25];
int vis[25][25], ans;
void dfs(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || e[x][y] == '#')
		return;
	ans++;
	REP(i, 0, 4)
	{
		int nx = x+nxt[i][0], ny = y+nxt[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && e[nx][ny] == '.')
		{
			vis[nx][ny] = 1;
			dfs(nx, ny);
			// vis[nx][ny] = 0;
		}
	}
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif


	while (~scanf("%d%d", &m, &n) && m+n)
	{
		ms(vis);
		ans = 0;
		int sx, sy;
		REP(i, 0, n)
		{
			scanf("%s", e[i]);
			REP(j, 0, m)
			if (e[i][j] == '@')
				sx = i, sy = j;
		}
		dfs(sx, sy);
		printf("%d\n", ans);
	}

    return 0;
}