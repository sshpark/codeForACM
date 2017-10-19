#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, w, T, v[1005], wei[1005];
    long long dp[1005];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &w);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) scanf("%d", wei+i);
        for (int i = 0; i < n; i++) scanf("%d", v+i);
        for (int i = 0; i < n; i++)
            for (int j = w; j >= v[i]; j--)
                dp[j] = max(dp[j], dp[j-v[i]]+wei[i]);
        printf("%lld\n", dp[w]);
    }
    return 0;
}