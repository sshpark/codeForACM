#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int emax = 5505;
const int pmax = 505;
int pre[pmax], dis[pmax], vis[pmax], cnt[pmax];
int id, n, m;
struct node {
    int to;
    int next;
    int w;
}edge[emax];
void add(int x, int y, int w) {
    edge[id].to = y;
    edge[id].w = w;
    edge[id].next = pre[x];
    pre[x] = id++;
}
int spfa() {
    for (int i = 0; i <= n; i++) {
        dis[i] = 0x3f3f3f3f;
        vis[i] = 0;
        cnt[i] = 0;
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    vis[1] = 1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        vis[top] = 0;
        cnt[top]++;
        if (cnt[top] > n)
            return 0;
        for (int i = pre[top]; i != -1; i = edge[i].next) {
            int e = edge[i].to;
            if (dis[e] > dis[top] + edge[i].w) {
                dis[e] = dis[top] + edge[i].w;
                if (!vis[e]) {
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    int T;
    int x, y, z, w;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &w);
        memset(pre, -1, sizeof pre);
        id = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        for (int i = 0; i < w; i++) {
            scanf("%d %d %d", &x, &y, &z);
            add(x, y, -z);
        }
        puts(spfa() ? "NO" : "YES");
    }
    return 0;
}