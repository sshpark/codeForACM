#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1000;
const int mod = 1e9+7;
int dp[1005][20005];
void init() {
    for (int i = 1; i <= 1000; i++) dp[i][0] = 1;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= i*(i-1)/2 && j <= 20000; j++) {
            dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            if (j >= i) dp[i][j] = (dp[i][j]-dp[i-1][j-i]+mod)%mod;
        }
}
int main(int argc, char const *argv[])
{
    int T, n, k;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        printf("%d\n", dp[n][k]);
    }   
    return 0;
}