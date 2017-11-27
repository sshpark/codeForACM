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
const int maxn = 100005;
int n, m;
vector<int> p[maxn];
ll cost[maxn], cur;
bool vis[maxn];

void dfs(int u) {
    cur = min(cur, cost[u]);
    for (int i = 0; i < p[u].size(); i++) {
        if (!vis[p[u][i]]) {
            vis[p[u][i]] = true;
            dfs(p[u][i]);
        }
    }
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    int u, v;
    memset(vis, false, sizeof vis);
    cin >> n >> m;
    repp(i, 1, n) cin >> cost[i];
    while (m--) {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cur = 100000000000000000;
        if (!vis[i]) {
            dfs(i);
            ans += cur;
        }
    }
    printf("%lld\n", ans);
    return 0;
}