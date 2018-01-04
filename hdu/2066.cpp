#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;
const int maxn = 1005;
struct node {
    int to, next, w;
}edge[maxn<<1];
int id;
int pre[maxn];
inline void init() {
    memset(pre, -1, sizeof pre);
    id = 0;
}
inline void add(int x, int y, int w) {
    edge[id].to = y;
    edge[id].w = w;
    edge[id].next = pre[x];
    pre[x] = id++;
}
int spfa(int st, int ed) {
    queue<int> q;
    int dis[maxn], vis[maxn];
    for (int i = 0; i < 1005; i++) {
        dis[i] = 1000000000;
        vis[i] = 0;
    }
    q.push(st);
    dis[st] = 0;
    vis[st] = 1;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        vis[top] = 0;
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
    return dis[ed];
} 
int main(int argc, char const *argv[])
{
    int T, S, D, u, v, w, st[maxn], to, ans;
    while (~scanf("%d %d %d", &T, &S, &D)) {
        init();
        ans = 1000000000;
        while (T--) {
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        for (int i = 0; i < S; i++) scanf("%d", st+i);
        for (int i = 0; i < D; i++) {
            scanf("%d", &to);
            for (int j = 0; j < S; j++)
                ans = min(ans, spfa(st[j], to));
        }
        printf("%d\n", ans);
    }
    return 0;
}