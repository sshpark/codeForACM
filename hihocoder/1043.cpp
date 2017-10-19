#include <iostream>
#include <string.h>
using namespace std;
int main() {
	int n, w, v[505], dp[100005], p[505];
	while (cin >> n >> w) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++)
			cin >> v[i] >> p[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= w; j++)
				if (v[i] < j) dp[j] = max(dp[j], dp[j-v[i]]+p[i]);
		cout << dp[w] << endl;
	}
}