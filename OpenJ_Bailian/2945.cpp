#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, dp[30], a[30];
	while (cin >> n) {
		for (int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++)
				if (a[i] <= a[j])
					dp[i] = max(dp[j]+1, dp[i]);
		}
		int maxa = -1;
		for (int i = 0; i < n; i++) maxa = max(maxa, dp[i]);
		printf("%d\n", maxa);
	}	

}