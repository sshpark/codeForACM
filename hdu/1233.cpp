#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
struct node {
    int u;
    int v;
    int w;
}edge[10005];
int fa[105];
bool cmp(node a, node b) {
    return a.w < b.w;
}
int findfa(int u) {
    if (fa[u] != u) fa[u] = findfa(fa[u]);
    return fa[u];
}
void unin(int u, int v) {
    int fau = findfa(u);
    int fav = findfa(v);
    if (fau == fav) return;
    if (fav > fau) fa[fav] = fau;
    else fa[fau] = fav;
}
int main(int argc, char const *argv[])
{
    int n, x, y, z, ans;
    while (~scanf("%d", &n) && n) {
        ans = 0;
        for (int i = 0; i <= n; i++) fa[i] = i;
        n = n*(n-1)/2;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            edge[i].u = x, edge[i].v = y;
            edge[i].w = z;
        }
        sort(edge+1, edge+n+1, cmp);
        for (int i = 1; i <= n; i++) {
            if (findfa(edge[i].u) != findfa(edge[i].v)) {
                unin(edge[i].u, edge[i].v);
                ans += edge[i].w;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}