#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int pmax = 1005;
const int emax = 1000005;
int n, m, dfs_clock, id, top, union_num, min_num;
int pre[pmax], dfn[pmax], low[pmax], scnno[pmax], st[pmax];
struct node {
    int next;
    int to;
    int w;
}edge[emax];
inline void init() {
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(pre, -1, sizeof pre);
    dfs_clock = id = top = 0;
    min_num = 1000000;
    union_num = 1;
}

inline void add(int x, int y, int w) {
    edge[id].to = y;
    edge[id].w = w;
    edge[id].next = pre[x];
    pre[x] = id++;
    edge[id].to = x;
    edge[id].w = w;
    edge[id].next = pre[y];
    pre[y] = id++;
}
void dfs(int u, int fa) {
    dfn[u] = low[u] = ++dfs_clock;
    int pre_num = 0;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (pre_num == 0 && v == fa) {
            pre_num++;
            continue;
        }
        if (!dfn[v]) {
            union_num++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                min_num = min(min_num, edge[i].w);
        }
        else if (dfn[v] < dfn[u])
            low[u] = min(low[u], dfn[v]);
    }
}
int main(int argc, char const *argv[])
{
    int x, y, w;
    while (~scanf("%d %d", &n, &m) && n+m) {
        init();
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &w);
            add(x, y, w);
        }
        dfs(1, 1);
        if (union_num < n)
            puts("0");
        else {
            if (min_num == 0) puts("1");
            else if (min_num == 1000000) puts("-1");
            else
                printf("%d\n", min_num);
        }
    }
    return 0;
}