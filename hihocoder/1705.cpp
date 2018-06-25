#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int dp[45][25];
int a[25];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[0][i] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 40; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1];
            if (i-a[j] >= 0) dp[i][j] += dp[i-a[j]][j-1];
        }
    }
    printf("%d\n", dp[40][n]);
    return 0;
}