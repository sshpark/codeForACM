#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
#define ll long long
const int pmax = 1000005;
const int emax = 1000005;
int id, id1, col, dfs_colcks, top;
int pre[pmax], pre1[pmax], scc[pmax], st[pmax], dfn[pmax], low[pmax], in[pmax];
ll sum[pmax], dp[pmax];
struct node {int to, next; ll w;}edge[emax], edge1[emax];
inline void add(int x, int y, ll w) {edge[id].to = y; edge[id].w = w; edge[id].next = pre[x]; pre[x] = id++;};
inline void add1(int x, int y, ll w) {edge1[id1].to = y; edge1[id1].w = w; edge1[id1].next = pre1[x]; pre1[x] = id1++;};
inline void init() {
    memset(pre, -1, sizeof pre);
    memset(pre1, -1, sizeof pre1);
    memset(dfn, 0, sizeof dfn);
    memset(scc, 0, sizeof scc);
    memset(low, 0, sizeof low);
    memset(sum, 0, sizeof sum);
    memset(in, 0, sizeof in);
    id1 = top = col = id = dfs_colcks = 0;
}
void dfs(int u) {
    dfn[u] = low[u] = ++dfs_colcks;
    st[top++] = u;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!scc[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        col++;
        while (true) {
            scc[st[--top]] = col;
            if (st[top] == u) break;
        }
    }
}
inline ll calc(ll w) {
    
}
int main(int argc, char const *argv[])
{
    int n, m, u, v, w, s;
    queue<int> q;
    init();
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    scanf("%d", &s);
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
    for (int i = 1; i <= n; i++)
        for (int j = pre[i]; j != -1; j = edge[j].next) {
            if (scc[i] != scc[edge[j].to]) continue;
            sum[scc[i]] += calc(edge[j].w);
        }
    for (int i = 1; i <= n; i++)
        for (int j = pre[i]; j != -1; j = edge[j].next)
            if (scc[i] != scc[edge[j].to])
                add1(scc[i], scc[edge[j].to], edge[j].w + sum[scc[edge[j].to]]);
    for (int i = 1; i <= col; i++) dp[i] = -100000000007;
    dp[scc[s]] = sum[scc[s]];
    for (int i = 1; i <= col; i++)
        for (int j = pre1[i]; j != -1; j = edge1[j].next)
            in[edge1[j].to]++;
    for (int i = 1; i <= col; i++)
        if (!in[i]) q.push(i);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        for (int i = pre1[top]; i != -1; i = edge1[i].next) {
            in[edge1[i].to]--;
            if (in[edge1[i].to] == 0) q.push(edge1[i].to);
            if (dp[top] != -100000000007)
                dp[edge1[i].to] = max(dp[edge1[i].to], dp[top] + edge1[i].w);
        }
    }
    ll ans = -100000000007;
    for(int i = 1;i <= col; ++i)
        ans = max(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}