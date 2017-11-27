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
#define LOCAL
const int pmax = 100005;
int id = 0, pre[pmax], cost[pmax], vis[pmax], ans[pmax];
set<int> s[pmax];
struct node {
    int to;
    int next;
}edge[pmax];

inline void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = pre[x];
    pre[x] = id++;
}

void dfs(int u) {
    vis[u] = 1;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            dfs(v);
            ans[v] += cost[v];
            vis[u] = 0;
        }
    }
}
x
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int n, m, u, v;
    scanf("%d %d", &n, &m);
    memset(pre, -1, sizeof pre);
    ms(cost);
    ms(vis);
    ms(ans);
    rep(i, 0, n-1) {
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    rep(i, 0, m) {
        scanf("%d %d", &u, &v);
        s[u].insert(v);
    }
    repp(i, 1, n) cost[i] = (int)s[i].size();

    dfs(1);
    printf("%d", ans[1]);
    repp(i, 2, n) printf(" %d", ans[i]);
    printf("\n");
    return 0;
}