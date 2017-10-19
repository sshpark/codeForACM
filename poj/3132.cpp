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
bool isp[1200];
int pri[1200], len = 0;
int dp[1200][20];
void shuai()
{
	memset(isp, true, sizeof(isp));
	for (int i = 2; i < 1200; i++)
		if (isp[i])
		{
			pri[len++] = i;
			for (int j = i*i; j < 1200; j+=i)
				isp[j] = false;
		}
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	shuai();
	int n, k;
	dp[0][0] = 1;
	REP(i, 0, len)
	{
		for (int j = 14; j >= 1; j--)
			for (int k = 1199; k >= pri[i]; k--)
				dp[k][j] += dp[k-pri[i]][j-1];
	}
	while (~scanf("%d %d", &n, &k) && n+k)
		printf("%d\n", dp[n][k]);
    return 0;
}