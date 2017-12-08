#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int emax = 50005;
struct _Edge {
    int to, next;
    bool vis;
    _Edge() {
        vis = false;
    }
}edge[emax*3];
int id = 0, cnt = 0, pre[10005<<1];
inline void add(int x, int y) {edge[id].to = y;edge[id].next = pre[x]; pre[x] = id++;}
void dfs(int u) {
    for (int i = pre[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (!edge[i].vis) {
            edge[i].vis = true;
            dfs(v);
        }
    }
    printf("%d\n", u);
}
int main(int argc, char const *argv[])
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) pre[i] = -1;
    while (m--) {
        scanf("%d %d", &u, &v);
        add(u, v);add(v, u);
    }
    dfs(1);
    return 0;
}