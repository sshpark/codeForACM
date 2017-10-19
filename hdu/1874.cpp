#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int emax = 1005;
const int pmax = 205;
struct node {
    int to;
    int w;
    int next;
}edge[emax];
int n, m, id, pre[pmax], dis[pmax], vis[pmax];
inline void add(int x, int y, int w) {
    edge[id].to = y;
    edge[id].w = w;
    edge[id].next = pre[x];
    pre[x] = id++;
}
void spfa(int st, int ed) {
    for (int i = 0; i < pmax; i++) {
        dis[i] = 0x3f3f3f;
        vis[i] = 0;
    }
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        vis[top] = 0;
        for (int j = pre[top]; j != -1; j = edge[j].next) {
            int e = edge[j].to;
            if (dis[e] > dis[top] + edge[j].w) {
                dis[e] = dis[top] + edge[j].w;
                if (!vis[e]) {
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
    }
    if (dis[ed] != 0x3f3f3f) printf("%d\n", dis[ed]);
    else puts("-1");
}
int main(int argc, char const *argv[])
{
    int x, y, z, s, t;
    while (~scanf("%d %d", &n, &m)) {
        memset(pre, -1, sizeof pre);
        id = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        scanf("%d %d", &s, &t);
        spfa(s, t);
    }
    return 0;
}