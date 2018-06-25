#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <map> 
using namespace std;

typedef long long ll; 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define nmax 100010
#define mmax 100010

int n, m, q, x, y;
int color[nmax];
int p[nmax], fs[nmax];
vector < int > comp[nmax];
map < int, int > d[nmax];

int get(int a) {
    return a == p[a] ? a : p[a] = get(p[a]);
}

int main() {
   // freopen("/Users/huangjiaming/Desktop/小C的周末(难)/data.in", "r", stdin);
   // freopen("/Users/huangjiaming/Desktop/小C的周末(难)/data.out", "w", stdout);
    // freopen("data.out", "w", stdout);
    //freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
    while (~scanf("%d%d%d", &n, &m, &q)) {
        for (int i = 0; i <= m; i++) comp[i].clear();
        for (int i = 0; i <= n; i++) d[i].clear();
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &color[i]);
        comp[color[i]].pb(i);
        d[i][color[i]] = 1;
        p[i] = i;
    }
    memset(fs, -1, sizeof fs);
    for(int i = 1; i <= m; ++i)
        if(comp[i].size() == 1)
            fs[i] = 0;

    for(int iter = 1; iter <= q; ++iter) {
        scanf("%d%d", &x, &y);
        int a = get(x), b = get(y);
        if(a != b) {
            map <int, int> & u = d[a], & v = d[b];
            if(u.size() < v.size())
                u.swap(v), swap(a, b);
            for(map < int, int > :: iterator it = v.begin(); it != v.end(); ++it) {
                u[it->fs] += it->sd; // 
                if(u[it->fs] == comp[it->fs].size()) // 如果满足游戏开始条件
                    if(fs[it->fs] == -1)
                        fs[it->fs] = iter;
            }
            p[b] = a;
        }
    }
    for(int i = 1; i <= m; ++i)
        printf("%d\n", fs[i]);
    }
    return 0;
}