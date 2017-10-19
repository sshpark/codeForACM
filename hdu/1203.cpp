#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int main(int argc, char const *argv[])
{
    int n, m;
    while (~scanf("%d %d", &n, &m) && n+m != 0) {
        double dp[maxn], w[maxn];
        int v[maxn];
        for (int i = 1; i <= m; i++) {
            scanf("%d %lf", &v[i], &w[i]);
            w[i] = 1 - w[i];
        }
        for (int i = 0; i < maxn; i++) dp[i] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n; j >= v[i]; j--)
                dp[j] = min(dp[j-v[i]]*w[i], dp[j]);
        printf("%.1lf%%\n", 100*(1-dp[n]));
    }
    return 0;
}