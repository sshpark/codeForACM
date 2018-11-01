#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
#define mod 998244353
int a[maxn];
ll dp[maxn][205][3];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);

    for (int i = 1; i <= 200; i++) {
        if (a[1] == -1 || a[1] == i) {
            dp[1][i][0] = 1;
        } else {
            dp[1][i][0] = 0;
        }
    }
    ll sum;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 200; j++) {
            if (a[i] == -1 || a[i] == j) {
                dp[i][j][1] = (dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
            } else {
                dp[i][j][1] = 0;
            }
        }
        sum = 0;
        for (int j = 1; j <= 200; j++) {
            if (a[i] == -1 || a[i] == j) {
                dp[i][j][0] = sum;
            } else {
                dp[i][j][0] = 0;
            }
            sum = (sum+dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
        }
        sum = 0;
        for (int j = 200; j >= 1; j--) {
            if (a[i] == -1 || a[i] == j) {
                dp[i][j][2] = sum;
            } else {
                dp[i][j][2] = 0;
            }
            sum = (sum+dp[i-1][j][1]+dp[i-1][j][2])%mod;
        }
    }
    sum = 0;
    for (int i = 1; i <= 200; i++) {
        sum = (sum + dp[n][i][1]+dp[n][i][2])%mod;
    }
    printf("%lld\n", sum);

    return 0;
}