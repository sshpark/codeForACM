#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int emax = 100005;
const int pmax = 1005;
struct node {
    int to, next, w;
}edge[emax], edge1[emax];
int head[pmax], head1[pmax], id, id1, dis[pmax], dis1[pmax], vis[pmax];
inline void add(node *edge, int *head, int &id, int x, int y, int w) {
    edge[id].to = y;
    edge[id].w = w;
    edge[id].next = head[x];
    head[x] = id++;
}
void spfa(node *edge, int *head, int st, int dis[]) {
    queue<int> q;
    for (int i = 0; i < pmax; i++) {
        vis[i] = 0;
        dis[i] = 100000000;
    }
    vis[st] = 1;
    dis[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int top = q.front(); q.pop();
        vis[top] = 0;
        for (int i = head[top]; i != -1; i = edge[i].next) {
            int v = edge[i].to;
            if (dis[v] > dis[top] + edge[i].w) {
                dis[v] = dis[top] + edge[i].w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
         }
    }
}
int main(int argc, char const *argv[])
{
    int n, m, x, a, b, c;
    memset(head, -1, sizeof head);
    memset(head1, -1, sizeof head1);
    id1 = id = 0;
    scanf("%d %d %d", &n, &m, &x);
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        add(edge, head, id, a, b, c);
        add(edge1, head1, id1, b, a, c);
    }
    int maxa = -1;
    spfa(edge, head, x, dis);
    spfa(edge1, head1, x, dis1);
    for (int i = 1; i <= n; i++)
        maxa = max(maxa, dis[i]+dis1[i]);
    printf("%d\n", maxa);
    return 0;
}