#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int n, m;
int e[1005][1005], st[100005], top;
bool first = true;
void dfs(int u) {
    st[top++] = u;
    for (int i = 1; i <= n; i++) {
        if (e[u][i]) {
            e[u][i]--;
            e[i][u]--;
            dfs(i);
            break;
        }
    }
}
void fleury(int u) {
    int bridge;
    top = 0;
    st[top++] = u;
    while (top) {
        bridge = 1;
        for (int i = 1; i <= n; i++) {
            if (e[st[top-1]][i]) {
                bridge = 0;
                break;
            }
        }
        if (bridge) {
            if (first) {
                printf("%d", st[--top]);
                first = false;
            } else
                printf(" %d", st[--top]);
        } else {
            dfs(st[--top]);
        }
    }
}
int main(int argc, char const *argv[])
{
    int u, v;
    scanf("%d %d", &n, &m);
    memset(e, 0, sizeof e);
    while (m--) {
        scanf("%d %d", &u, &v);
        e[u][v]++;
        e[v][u]++;
    }
    fleury(3);
    printf("\n");
    return 0;
}