#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
struct node {
    int x, val;
    friend bool operator < (node a, node b) {
        return a.x < b.x;
    }
}s[1005];
int sum[1005], dp[1005][1005][2];
int main(int argc, char const *argv[])
{
    int N, V, X;
    while (~scanf("%d %d %d", &N, &V, &X)) {
        for (int i = 1; i <= N; i++)
            scanf("%d %d", &s[i].x, &s[i].val);
        s[N+1].x = X, s[N+1].val = 0;
        N++;
        sort(s+1, s+N+1);
        memset(dp, 0x3f3f3f3f, sizeof dp);
        sum[0] = 0;
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i-1]+s[i].val;
            if (s[i].x == X && s[i].val == 0)
                dp[i][i][0] = dp[i][i][1] = 0;
        }
        for (int len = 2; len <= N; len++) {
            for (int i = 1; i+len-1 <= N; i++) {
                int j = i+len-1;
                dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][0]+(s[i+1].x-s[i].x)*(sum[i]+sum[N]-sum[j]));
                dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][1]+(s[j].x-s[i].x)*(sum[i]+sum[N]-sum[j]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][0]+(s[j].x-s[i].x)*(sum[i-1]+sum[N]-sum[j-1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1]+(s[j].x-s[j-1].x)*(sum[i-1]+sum[N]-sum[j-1]));
            }
        }
        printf("%d\n", min(dp[1][N][0], dp[1][N][1])*V);
    }
    return 0;
}