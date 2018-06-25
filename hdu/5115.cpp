#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 205;
int a[maxn], b[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
    int T, n;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", a+i);
        for (int i = 1; i <= n; i++) scanf("%d", b+i);
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) dp[i][j] = 1000000000;
        for (int len = 0; len <= n; len++) {
            for (int i = 1; i+len <= n; i++) {
                int j = i+len;
                for (int k = i; k <= j; k++)
                    dp[i][j] = min(dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1], dp[i][j]);
            }
        }
        printf("Case #%d: %d\n", t, dp[1][n]);
    }
    return 0;
}