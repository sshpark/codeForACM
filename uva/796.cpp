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
    bool cut;
}edge[maxn];

int pre[maxn], st[maxn], in[maxn], out[maxn], dfn[maxn], low[maxn], sccno[maxn], sum[maxn];
int id, top, dfs_clock, col, bridge;
inline void init() {
    ms(st);ms(in); ms(sum);
    ms(out);ms(dfn);ms(low);ms(sccno);
    memset(pre, -1, sizeof pre);
    bridge = col = top = dfs_clock= id = 0;
}
inline void add(int x, int y) {edge[id].cut = false; edge[id].to = y; edge[id].next = pre[x];pre[x] = id++;}
void dfs(int u, int fa) {
    dfn[u] = low[u] = ++dfs_clock;
    int pre_num = 0;
    for (int i = pre[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        if (!dfn[v]) {
            pre_num++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
        }
        else if (dfn[v] < dfn[u])
            low[u] = min(low[u], dfn[v]);
    }
}

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int n, x, y, k;
    
    while (~scanf("%d", &n)) {
        init();
        rep(i, 0, n) {
            scanf("%d (%d)", &x, &k);
            x++;
            while (k--) {  
                scanf("%d", &y);
                y++;
                add(x, y);
                add(y, x);
            }
            
        }
        repp(i, 1, n)
            if (!dfn[i]) dfs(i, i);
        printf("%d critical links\n", bridge);
        vector<pair<int,int> > ans;
        for(int u = 1;u <= n;u++)
            for(int i = pre[u]; i != -1; i = edge[i].next)
                if(edge[i].cut && edge[i].to > u) {
                    ans.push_back(make_pair(u, edge[i].to));
                }
        sort(ans.begin(),ans.end());
        for(int i = 0;i < ans.size();i++)
            printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
        printf("\n");
    }

    return 0;
}