#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, x, sum = 0, a[25], dp[3005];
    memset(dp, 0, sizeof dp);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    if (sum < x) return 0*printf("-1\n");
    int d = sum-x;
    for (int i = 0; i < n; i++)
        for (int j = d; j >= a[i]; j--)
            if (dp[j-a[i]]+a[i] <= d)
                dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
    int ans = 0;
    for (int i = 0; i <= d; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", sum-ans);
    return 0;
}