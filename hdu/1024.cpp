#include <iostream>
#include <algorithm>
const int maxn = 1000005;
using namespace std;
#define INF 0x7fffffff
int dp[maxn];
int prem[maxn];
int a[maxn];
int main() 
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	int n, m, mmax;
	while (~scanf("%d %d", &m, &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", a+i);
			dp[i] = 0, prem[i] = 0;
		}
		dp[0] = 0, prem[0] = 0;
		for (int i = 1; i <= m; i++) {
			mmax = -INF;
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j-1]+a[j], prem[j-1]+a[j]);
				prem[j-1] = mmax;
				mmax = max(mmax, dp[j]);
			}
		}
		printf("%d\n", mmax);
	}
	return 0;
}