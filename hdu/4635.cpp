#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
#define rep(i, k, n) for (int i = k; i < n; i++)
#define repp(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
#define LOCAL
struct node {
    int next;
    int to;
}edge[maxn];
int pre[maxn], st[maxn], in[maxn], out[maxn], dfn[maxn], low[maxn], sccno[maxn], sum[maxn];
int id, top, dfs_clock, col;
inline void init() {
    ms(st);ms(in); ms(sum);
    ms(out);ms(dfn);ms(low);ms(sccno);
    memset(pre, -1, sizeof pre);
    col = top = dfs_clock= id = 0;
}
inline void add(int x, int y) { edge[id].to = y; edge[id].next = pre[x];pre[x] = id++;}
void dfs(int u) {
    low[u] = dfn[u] = ++dfs_clock;
    st[top++] = u;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!dfn[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!sccno[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        col++;
        while (true) {            
            sccno[st[--top]] = col;
            sum[col]++;
            if (st[top] == u) break;
        }
    }
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int n, m, T, x, y;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        init();
        scanf("%d %d", &n, &m);
        rep(i, 0, m) {
            scanf("%d %d", &x, &y);
            add(x, y);
        }
        repp(i, 1, n)
            if (!dfn[i]) dfs(i);
        printf("Case %d: ", t);
        if (col == 1) {
            puts("-1");
        } else {
            repp(i, 1, n)
                for (int j = pre[i]; j != -1; j = edge[j].next)
                    if (sccno[edge[j].to] != sccno[i]) {
                        out[sccno[i]]++;
                        in[sccno[edge[j].to]]++;
                    }
            int ans = -1;
            repp(i, 1, col) {
                if (!in[i] || !out[i])
                    ans = max(ans, n*(n-1)-m-sum[i]*(n-sum[i]));
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}