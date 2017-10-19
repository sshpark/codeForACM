#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 1000005;
int main(int argc, char const *argv[])
{
    int n;
    while (~scanf("%d", &n)) {
        char op[5];
        int x, dp[n+10], sum[n+10], a[n+10], b[n+10], cnt = 0, cnt2 = 0;
        memset(dp, 0, sizeof dp);
        sum[0] = 0, dp[0] = -0x3f3f3f;
        for (int i = 1; i <= n; i++) {
            scanf("%s", op);
            if (op[0] == 'I') {
                cnt++;
                scanf("%d", a+cnt);
                sum[cnt] = sum[cnt-1]+a[cnt];
                dp[cnt] = max(dp[cnt-1], sum[cnt]);
            }
            else if (op[0] == 'D') {
                if (cnt == 0) continue;
                cnt--;
            }
            else if (op[0] == 'L') {
                if (cnt == 0) continue;
                b[++cnt2] = a[cnt--];
            }
            else if (op[0] == 'R') {
                if (cnt2 == 0) continue;
                a[++cnt] = b[cnt2--];
                sum[cnt] = sum[cnt-1]+a[cnt];
                dp[cnt] = max(dp[cnt-1], sum[cnt]);
            }
            else {
                scanf("%d", &x);
                printf("%d\n", dp[x]);
            }
        }
    }
    return 0;
}