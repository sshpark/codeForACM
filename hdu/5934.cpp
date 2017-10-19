#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn = 1005;
#define ll long long
ll id, dfs_clocks, in, col;
ll pre[maxn], sccno[maxn], dfn[maxn], low[maxn], st[maxn], cost[maxn], in_0[maxn];
struct node {
    ll to;
    ll next;
}edge[maxn*maxn];
struct node1 {
    ll x, y;
    ll r, c;
}e[maxn];
inline void init() {
    memset(pre, -1, sizeof pre);
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(st, 0, sizeof st);
    memset(sccno, 0, sizeof sccno);
    memset(in_0, 0, sizeof in_0);
    for (ll i = 0; i < maxn; i++) cost[i] = 1000000009;
    col = in = id = dfs_clocks = 0;
}
inline void add(ll x, ll y) {
    edge[id].to = y;
    edge[id].next = pre[x];
    pre[x] = id++;
}
void dfs(ll u) {
    dfn[u] = low[u] = ++dfs_clocks;
    st[in++] = u;
    for (ll i = pre[u]; i != -1; i = edge[i].next) {
        ll v = edge[i].to;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        col++;
        in--;
        while (true) {
            sccno[st[in]] = col;
            cost[col] = min(cost[col], e[st[in]].c);
            if (st[in] == u) break;
            in--;
        }
    }
}
int main(int argc, char const *argv[])
{
    ll n, T;
    scanf("%lld", &T);
    for (ll t = 1; t <= T; t++) {
        init();
        scanf("%lld", &n);
        for (ll i = 1; i <= n; i++)
            scanf("%lld %lld %lld %lld", &e[i].x, &e[i].y, &e[i].r, &e[i].c);
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
                if (i != j) {
                    long long tem = e[i].x - e[j].x;
                    long long tem1 = e[i].y - e[j].y;
                    long long dis = tem1*tem1+tem*tem;
                    long long dis2 = e[i].r*e[i].r;
                    if (dis <= dis2)
                        add(i, j);
                }
        for (ll i = 1; i <= n; i++)
            if (!dfn[i]) dfs(i);
        for(ll i = 1; i <= n; i++)
            for(ll j = pre[i]; j != -1; j = edge[j].next) {
                ll v = edge[j].to;
                if(sccno[i] != sccno[v]) in_0[sccno[v]]++;
            }
        ll ans = 0;
        for(ll i = 1; i <= col; i++)
            if(!in_0[i]) ans += cost[i];
        printf("Case #%lld: %lld\n", t, ans);
    }
    return 0;
}