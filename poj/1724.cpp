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
int K, N, R;
struct Rode {
    int d, L, t;
};

vector<vector<Rode> > cityMap(110);
int minLen, totalCost, totalLen;
int dp[105][10005], vis[105];
void dfs(int s) {
    if (s == N) {
        minLen = min(minLen, totalLen);
        return;
    }
    for (int i = 0; i < cityMap[s].size(); i++) {
        int d = cityMap[s][i].d;
        if (!vis[d]) {
            int cost = totalCost + cityMap[s][i].t;
            if (cost > K) continue;
            if (totalLen + cityMap[s][i].L >= minLen || totalLen + cityMap[s][i].L >= dp[d][cost])
                continue;
            totalLen += cityMap[s][i].L;
            totalCost += cityMap[s][i].t;
            dp[d][cost] = totalLen;
            vis[d] = 1;
            dfs(d);
            vis[d] = 0;
            totalLen -= cityMap[s][i].L;
            totalCost -= cityMap[s][i].t;
        }
    }
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    scanf("%d %d %d", &K, &N, &R);
    int x, y, w, z;
    for (int i = 0; i < R; i++) {
        int s;
        Rode r;
        scanf("%d %d %d %d", &s, &r.d, &r.L, &r.t);
        if (s != r.d)
            cityMap[s].push_back(r);
    }
    ms(vis);
    vis[1] = 1;
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 10005; j++)
            dp[i][j] = 100000000;
    totalLen = totalCost = 0;
    minLen = 100000000;
    dfs(1);
    if (minLen < 100000000) printf("%d\n", minLen);
    else puts("-1");
    return 0;
}