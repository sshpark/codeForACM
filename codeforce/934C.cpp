#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 2005;
int a[maxn], dp[maxn], n;
int getdp() {
    int len = 0;
    memset(dp, 0, sizeof dp);
    dp[1] = a[1];
    len = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] >= dp[len]) dp[++len] = a[i];
        else {
            int pos = lower_bound(dp, dp+len, a[i]) - dp;
            dp[pos] = a[i];
        }
    }
    return len+1;
}
int main(int argc, char const *argv[])
{
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/codeforce/data.out", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    srand(66666);
    int maxa = 0, l, r;
    for (int t = 0; t <= 505055; t++) {
        l = rand()%n+1;
        r = rand()%(n-l+1)+l;
        reverse(a+l, a+r+1);
        maxa = max(getdp(), maxa);
        reverse(a+l, a+r+1);
    }
    printf("%d\n", maxa);
    return 0;
}