#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1000005;
int vis[maxn];
inline void init(int n) {
    memset(vis, 0, sizeof vis);
}
int main(int argc, char const *argv[])
{
    int n, x;
    while (~scanf("%d", &n)) {
        init(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            vis[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                ans += vis[i]/2;
                vis[i] = vis[i] % 2;
            }
            if (vis[i] && vis[i+1] % 2 == 1 && vis[i+2]) {
                ans++;
                vis[i]--;
                vis[i+1]--;
                vis[i+2]--;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}