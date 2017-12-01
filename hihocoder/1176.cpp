#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10005;
int pre[maxn], deg[maxn];
int findxy(int x) {
    return x == pre[x] ? x : findxy(pre[x]);
}
void unin(int x, int y) {
    int nx = findxy(x), ny = findxy(y);
    if (nx == ny) return;
    if (nx > ny) pre[nx] = ny;
    if (nx < ny) pre[ny] = nx;
}

int main(int argc, char const *argv[])
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    memset(deg, 0, sizeof deg);
    for (int i = 0; i <= n; i++) pre[i] = i;
    while (m--) {
        scanf("%d %d", &u, &v);
        deg[u]++, deg[v]++;
        unin(u, v);
    }
    int conn = 0;
    for (int i = 1; i <= n; i++)
        if (pre[i] == i) conn++;
    if (conn > 1) puts("Part");
    else {
        int odd = 0;
        for (int i = 1; i <= n; i++)
            if (deg[i] & 1) odd++;
        puts((odd == 2 || odd == 0) ? "Full" : "Part");
    }
    return 0;
}