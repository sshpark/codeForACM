#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int T, n;
    double run;
    double dp[10005], lv[105];
    int m[105];
    scanf("%d", &T);
    while (T--) {
        scanf("%lf %d", &run, &n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %lf", m+i, lv+i);
            sum += m[i];
        }
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = sum; j >= m[i]; j--)
                dp[j] = max(dp[j], dp[j-m[i]]*(1-lv[i]));
        for (int i = sum; i >= 0; i--)
            if (dp[i] > (1-run)) {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}