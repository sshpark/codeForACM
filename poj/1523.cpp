#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int pmax = 1005;
struct node {
    int to;
    int next;
}edge[pmax*pmax];
int id, pre[pmax], n, dfn[pmax], low[pmax], dfs_colck, blo[pmax];

inline void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = pre[x];
    pre[x] = id++;
}
void tarjan(int u) {
    low[u] = dfn[u] = ++dfs_colck;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v])
                blo[u]++;
        }
        else low[u] = min(low[u], dfn[v]);
    }
}
int main(int argc, char const *argv[])
{
    int x, y, kase = 0;
    while (~scanf("%d", &x)) {
        id = dfs_colck = 0;
        if (x == 0) break;
        n = 0;
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(pre, -1, sizeof pre);
        scanf("%d", &y);
        n = max(n, max(x, y));
        add(x, y); add(y, x);
        while (scanf("%d", &x) && x) {
            scanf("%d", &y);
            add(x, y); add(y, x);
            n = max(n, max(x, y));
        }
        for(int i = 1; i <= n; i++)blo[i] = 1;
        blo[1] = 0;
        tarjan(1);
        printf("Network #%d\n", ++kase);
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (blo[i] > 1) {
                printf("  SPF node %d leaves %d subnets\n",i , blo[i]);
                flag = 1;
            }
        }
        if(!flag) puts("  No SPF nodes");
        puts("");
    }
    return 0;
}