#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 2005;
int dp[maxn][maxn], s[maxn][maxn], a[maxn][maxn] = {0};
int main(int argc, char const *argv[])
{
    int n;
    memset(dp, 1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][i]);
        a[n+i][n+i] = a[i][i];
    }

    for (int i = 0; i < n<<1; i++) {
        s[i][i] = i;
        dp[i][i] = 0;
    }

    for (int i = 0; i < n*2-1; i++)
        for (int j = i+1; j < n*2-1; j++)
            a[i][j] = a[i][j-1]+a[j][j];
        
    for (int len = 1; len < n; len++) {
        for(int i = 0; i+len < n*2-1; i++) {
            int j = i+len;
            for (int k = s[i][j-1]; k <= s[i+1][j]; k++) {
                if (dp[i][j] > a[i][j]+dp[i][k]+dp[k+1][j]) {
                    dp[i][j] = a[i][j]+dp[i][k]+dp[k+1][j];
                    s[i][j] = k;
                }
            }
        }
    }
    int ans = dp[0][n-1];
    for(int i = 1; i < n; i++) ans = min(ans, dp[i][i+n-1]);
    printf("%d\n",ans);
    return 0;
}