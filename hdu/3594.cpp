#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int emax = 50005;
const int pmax = 20005;

struct _Edge {
    int from, to, nxt, id;
}e[emax];

int head[pmax], pre[pmax], low[pmax], sccno[pmax], stack[pmax], stack2[emax];
int queue[emax];
bool vis[emax], flag;

int tot, n, scc_cnt, dfs_clock, top, top2;

inline void add(int x, int y) {
    e[tot].from = x;
    e[tot].to = y;
    e[tot].nxt = head[x];
    e[tot].id = tot;
    head[x] = tot++;
}

inline void init() {
    scanf("%d", &n);
    memset(head, -1, sizeof head);
    tot = 0;
    int u, v;
    while (scanf("%d %d", &u, &v) && u+v) {
        add(u, v);
    }
}

void dfs(int u) {
    pre[u] = low[u] = ++dfs_clock;
    stack[++top] = u;

    for (int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].to;
        stack2[++top2] = e[i].id;
        if (!pre[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!sccno[v]) {
            low[u] = min(low[u], pre[v]);
            int tmp = top2;
            while (true) {
                int id = stack2[top2--];
                if (vis[id]) flag = true;
                vis[id] = true;
                if (e[id].from == v)
                    break;
            }
            top2 = tmp;
        }
        top2--;
    }
    int x;
    if (pre[u] == low[u]) {
        scc_cnt++;
        while (true) {
            x = stack[top--];
            sccno[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

void solve() {
    memset(pre, 0, sizeof pre);
    memset(sccno, 0, sizeof sccno);
    memset(vis, 0, sizeof vis);
    dfs_clock = top = top2 = scc_cnt = 0;
    flag = false;
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (sccno[i] != 1) {
            printf("NO\n");
            return ;
        }
    }
    if (flag) printf("NO\n");
    else printf("YES\n");
}

int main(int argc, char const *argv[])
{
    int test;
    scanf("%d", &test);
    while (test--) {
        init();
        solve();
    }
    return 0;
}