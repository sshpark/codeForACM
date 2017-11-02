#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int pmax = 20005;
const int emax = 100005;
int col, dfs_clock, top;
int sccno[pmax], wei[pmax], dfn[pmax], low[pmax], st[pmax], in[pmax], vis[pmax], from[emax], to[emax];
long long nwei[pmax], maxa = 0;
vector<int> p[pmax], new_p[pmax];
void dfs(int u) {
    dfn[u] = low[u] = ++dfs_clock;
    st[top++] = u;
    for (auto i = p[u].begin(); i != p[u].end(); i++) {
        if (!dfn[*i]) {
            dfs(*i);
            low[u] = min(low[u], low[*i]);
        }
        else if (!sccno[*i]) low[u] = min(low[u], dfn[*i]);
    }
    if (low[u] == dfn[u]) {
        col++;
        while (true) {
            sccno[st[--top]] = col;
            if (st[top] == u) break;
        } 
    }
}
void getsum(int u, long long sum) {
    maxa = max(maxa, sum);
    for (auto j = new_p[u].begin(); j != new_p[u].end(); j++)
        if (!vis[*j]) {
            vis[*j] = 1;
            getsum(*j, sum+nwei[*j]);
            vis[*j] = 0;
        }
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dfn, 0, sizeof dfn); memset(nwei, 0, sizeof nwei); memset(low, 0, sizeof low);
    memset(sccno, 0, sizeof sccno); memset(in, 0, sizeof in); memset(vis, 0, sizeof vis);
    top = dfs_clock = col = 0;
    for (int i = 1; i <= n; i++) scanf("%d", wei+i);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", from+i, to+i);
        p[from[i]].push_back(to[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
    for (int i = 1; i <= n; i++) nwei[sccno[i]] += wei[i];
    for (int i = 1; i <= m; i++)
        if (sccno[from[i]] != sccno[to[i]]) 
            new_p[sccno[from[i]]].push_back(sccno[to[i]]);
    getsum(sccno[1], nwei[sccno[1]]);
    printf("%lld\n", maxa);
    return 0;
}