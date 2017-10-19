#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int w[3500], v[3500], dp[13000];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++)
		cin >> v[i] >> w[i];
	for (int i = 0; i < n; i++)
		for (int j = m; j >= 0; j--)
			if (j >= v[i])
			dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
	printf("%d\n", dp[m]);
	return 0;
}