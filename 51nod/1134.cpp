#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, a[50005];
	int dp[50005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, 0, sizeof dp);
	int len = 0;
	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > dp[len]) dp[++len] = a[i];
		else {
			int pos = lower_bound(dp, dp+len, a[i]) - dp;
			dp[pos] = a[i];
		}
	}
	printf("%d\n", len+1);
	return 0;
}