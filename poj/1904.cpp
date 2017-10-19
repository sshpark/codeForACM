#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
const int pmax = 4005;
const int emax = 2000005;
int pre[pmax], dfn[pmax], low[pmax], sccno[pmax], st[pmax];
int id, n, m, dfs_clock, in, col;
struct node {
    int to;
    int next;
}edge[emax];

void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = pre[x];
    pre[x] = id++;
}

void dfs(int u) {
    low[u] = dfn[u] = ++dfs_clock;
    st[in++] = u;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        in--;
        col++;
        while (true) {
            sccno[st[in]] = col;
            if (st[in] == u) break;
            in--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int k, x;
    scanf("%d", &n);
    memset(pre, -1, sizeof pre);
    memset(sccno, 0, sizeof sccno);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(st, 0, sizeof st);
    id = dfs_clock = in = col = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            add(i, x+n);           
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        add(x+n, i);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
    vector<int> ans;
    vector<int>::iterator iter;
    for (int i = 1; i <= n; i++) {
        ans.clear();
        for (int j = pre[i]; j != -1; j = edge[j].next)
            if (edge[j].to > n && sccno[i] == sccno[edge[j].to])
                ans.push_back(edge[j].to-n);
        sort(ans.begin(), ans.end());
        printf("%d", (int)ans.size());
        for (iter = ans.begin(); iter != ans.end(); iter++)
            printf(" %d", *iter);
        puts("");
    }
    return 0;
}