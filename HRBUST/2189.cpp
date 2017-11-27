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
int n, m;
vector<int> p[1005];
int vis[1005], ans;
void getNodes(int st) {
    for (int i = 0; i < p[st].size(); i++) {
        if (!vis[p[st][i]]) {
            ans++;
            vis[p[st][i]] = 1;
            getNodes(p[st][i]);
            vis[p[st][i]] = 0;
        }
    }
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int T, op, u, v;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 1005; i++)
            p[i].clear();
        scanf("%d %d", &n, &m);
        rep(i, 0, m) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d %d", &u, &v);
                p[u].push_back(v);
                p[v].push_back(u);
            } else {
                ms(vis);ans = 0;
                scanf("%d", &u);
                getNodes(u);
                printf("%d\n", ans ? ans : 1);
            }
        }
    }

    return 0;
}