#include <iostream>
#include <string.h>
using namespace std;
int dp[105][105];
int main() {
	int T, n, t, p;
	cin >> T;
	while (T--) {
		cin >> n >> t >> p;
		for (int i = 1; i <= t; i++) dp[1][i] = 1;
		for (int i = 1; i <= n; i++)
			for (int k = p; k <= t; k++)
				for (int j = p; j <= t; j++)
					if (j - k >= p)
						dp[i][j] += dp[i-1][j-k];
		printf("%d\n", dp[n][t]);
	}
}