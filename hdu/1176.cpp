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

int dp[100005][11];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, t, x, m;

	while (~scanf("%d", &n) && n)
	{
		ms(dp);
		m = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &t);
			if (t > m) m = t;
			dp[t][x]++;
		}
		for (int i = m-1; i >= 0; i--)
			for (int j = 0; j < 11; j++)			
				dp[i][j] += max(max(dp[i+1][j], dp[i+1][j+1]), dp[i+1][j-1]);
		printf("%d\n", dp[0][5]);
	}

    return 0;
}