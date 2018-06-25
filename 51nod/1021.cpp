#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[2005], dp[2005][2005], sum[2005][2005];
int main(int argc, char const *argv[])
{
    memset(sum, 0, sizeof sum);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int temp = n << 1;
    for (int i = n+1; i <= temp; i++) a[i] = a[i-n];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j-1]+a[j+i-1];
    memset(dp, 0, sizeof dp);
    for (int len = 2; len <= n; len++) { // 区间长度
        for (int i = 1; i <= n-len+1; i++) { // 起始位置
            dp[i][len] = 1000000000;
            for (int j = 1; j < len; j++) { // 长度
                dp[i][len] = min(dp[i][len], dp[i][j]+dp[i+j][len-j]+sum[i][len]);
            }
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}