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

int a[205][205], dp[200][205], dp1[200][205], vis[205][205];


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m;

	while (~scanf("%d %d", &n, &m))
	{
		ms(dp);
		ms(dp1);
		ms(vis);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%d", &a[i][j]);
				dp[i][j] = a[i][j];
				dp1[i][j] = a[i][j];
			}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		int r = 1, c = 1;
		dp1[n][m] = a[n][m] = dp1[1][1] = a[1][1] = 0;
		while(r != n && c != m)
		{
			if (dp[r+1][c] < dp[r][c+1])
				c++;
			else if (dp[r+1][c] > dp[r][c+1])
				r++;
			else
			{
				printf("%d\n", a[r][c+1]);
				if (a[r+1][c] > a[r][c+1])
					r++;
				else if (a[r+1][c] < a[r][c+1])
					c++;
				else
					c++;
			}
			a[r][c] = 0;
			dp1[r][c] = 0;
		}
		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--)
				dp1[i][j] = max(dp1[i+1][j], dp1[i][j+1])+a[i][j];

		printf("%d\n", dp[n][n]+dp1[1][1]);
	}

    return 0;
}