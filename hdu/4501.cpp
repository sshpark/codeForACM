#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, v1, v2, k;
	while (cin >> n >> v1 >> v2 >> k) {
		int price[105], score[105], w[105];
		int dp[105][105][10];
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++)
			cin >> price[i] >> score[i] >> w[i];
		for (int i = 0; i < n; i++) {
			for (int j = v1; j >= 0; j--)
				for (int p = v2; p >= 0; p--)
					for (int m = k; m >= 0; m--) {
						int tem = 0;
						if (m > 0)
							tem = max(dp[j][p][m-1]+w[i], tem);
						if (p >= score[i])
							tem = max(dp[j][p-score[i]][m]+w[i], tem);
						if (j >= price[i])
							tem = max(dp[j-price[i]][p][m]+w[i], tem);
						dp[j][p][m] = max(dp[j][p][m], tem);
					}
		}
		cout << dp[v1][v2][k] << endl;
	}
	return 0;
}