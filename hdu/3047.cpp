#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 50005;
int n, m, u, v, w;
int pre[maxn], dis[maxn];
inline void init() {
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        dis[i] = 0;
    }
}
int findx(int x) {
    if (pre[x] == x) return x;
    int t = pre[x];
    pre[x] = findx(pre[x]);
    dis[x] += dis[t];
    return pre[x];
}
void unin(int a, int b, int ra, int rb, int w) {
    pre[rb] = ra;
    dis[rb] = dis[a]+w-dis[b];
}
int main(int argc, char const *argv[])
{
    int x, y;
    int ans;
    while (~scanf("%d %d", &n, &m)) {
        init();
        ans = 0;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            x = findx(u);
            y = findx(v);
            if (x == y) {
                if (dis[v]-dis[u] != w) ans++;
            } else unin(u, v, x, y, w);
        }
        printf("%d\n", ans);
    }
    return 0;
}