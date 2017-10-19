#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int pmax = 105;
const int emax = 10005;
int id, dis[pmax], vis[pmax], pre[pmax];
int n, m;
struct node {
	int to;
	int w;
	int next;
}edge[emax<<2];
void add(int x, int y, int w) {
	edge[id].to = y;
	edge[id].w = w;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void spfa() {
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		dis[i] = 0x3f3f3f;
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	dis[1] = 0;
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
}
int main(int argc, char const *argv[])
{
	while (cin >> n >> m && n+m) {
		memset(pre, -1, sizeof pre);
		int x, y, w;
		for (int i = 0; i < m; i++) {
			cin >> x >> y >> w;
			add(x, y, w);
			add(y, x, w);
		}
		spfa();
		printf("%d\n", dis[n]);
	}
	return 0;
}