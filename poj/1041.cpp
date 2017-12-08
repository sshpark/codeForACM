#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int e[55][2005], edge[55][2005], num[55], top, path[2005];
bool vis[2005];
void dfs(int u) {
    for (int i = 1; i <= num[u]; i++) {
        int v = edge[u][i];
        if (!vis[v]) {
            vis[v] = true;
            dfs(e[u][v]);
            path[++top] = v;
        }
    }
}
int main(int argc, char const *argv[])
{
    int x, y, z, cnt, st;
    while (scanf("%d %d", &x, &y)) {
        memset(num, 0, sizeof num);
        if (x+y == 0) break;
        scanf("%d", &z);
        st = min(x, y);
        edge[x][++num[x]] = z;
        edge[y][++num[y]] = z;
        e[x][z] = y;
        e[y][z] = x;
        while (scanf("%d %d", &x, &y)) {
            if (x+y == 0) break;
            scanf("%d", &z);
            edge[x][++num[x]] = z;
            edge[y][++num[y]] = z;
            e[x][z] = y;
            e[y][z] = x;
        }
        int t;
        for (t = 1; ; t++)
            // num记录的是每个路口的度数
            if (!num[t] || num[t]&1)
                break;
        if (num[t]) {
            puts("Round trip does not exist.");
        } else {
            int ed = t-1;
            memset(vis, false, sizeof vis);
            top = 0;
            dfs(st);
            for (int i = top; i > 1; i--)
                printf("%d ", path[i]);
            printf("%d\n", path[1]);
        }
    }

    return 0;
}