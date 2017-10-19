#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m, kase = 0;
    double dp[105][105];
    while (~scanf("%d",&n)) {
        if (n == -1) break;
        scanf("%d", &m);
        memset(dp, 0, sizeof dp);
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = dp[i-1][j]*(j*1.0/m)+dp[i-1][j-1]*((m-j+1)*1.0/m);
        printf("Case %d: %.7lf\n", ++kase, 1-dp[n][m]);
    }

    return 0;
}