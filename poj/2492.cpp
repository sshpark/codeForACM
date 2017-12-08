#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 2005;
int n, m;
int pre[maxn], rk[maxn];
inline void init() {
    for (int i = 0; i <= n; i++) pre[i] = i;
    memset(rk, 0, sizeof rk);
}
int findx(int x) {
    if (x == pre[x]) return pre[x];
    int t = findx(pre[x]);
    rk[x] = (rk[x]+rk[pre[x]])%2;
    pre[x] = t;
    return pre[x];
}
inline bool unit(int x, int y) {
    int fx = findx(x), fy = findx(y);
    if (fx == fy) {
        if (rk[x] == rk[y]) return false;
        return true;
    }
    pre[fy] = fx;
    rk[fy] = (rk[y] - rk[x] + 1) % 2;
    return true;
}
int main(int argc, char const *argv[])
{
    int T, u, v;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &n, &m);
        init();
        bool flag = true;
        while (m--) {
            scanf("%d %d", &u, &v);
            if (!unit(u, v))
                flag = false;
        }
        if (flag)
            printf("Scenario #%d:\nNo suspicious bugs found!\n\n", t);
        else
             printf("Scenario #%d:\nSuspicious bugs found!\n\n", t);
    }
    return 0;
}