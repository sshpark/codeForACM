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
const int maxn = 1<<16;
struct node {
    int next, to, w;
}edge[maxn<<1];
int head[maxn], path[maxn], cnt, id;
inline void init() {
    memset(head, -1, sizeof head);
    ms(path);
    id = cnt = 0;
}
inline void add(int x, int y, int w) {edge[id].to = y;edge[id].next = head[x];head[x] = id++;}
void fleury(int u) {
    for (int i = head[u]; i != -1; i = head[u]) {
        int v = edge[i].to;
        head[u] = edge[i].next;
        fleury(v);
    }
    path[++cnt] = u;
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int n;
    scanf("%d", &n);
    int len = 1<<(n-1);
    init();
    for (register int i = 0; i < len; i++) {
        int w = (i<<1)|1, v = w&((1<<(n-1))-1);
        add(i, v, w);
        w = i<<1, v = w&((1<<(n-1))-1);
        add(i, v, w);
    }
    fleury(0);
    for (register int i = cnt; i >= 2; i--)
        printf("%d", path[i]&1);
    return 0;
}