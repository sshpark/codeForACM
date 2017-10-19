#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <queue>
const int pmax = 50005;
const int emax = 150005;
using namespace std;
int pre[pmax], vis[pmax], dis[pmax];
int n, id;
struct node {
	int to;
	int w;
	int next;
}edge[emax];
void add(int x, int y, int w) {
	edge[id].to = y;
	edge[id].w = w;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void spfa(int start, int end) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(start);
	dis[start] = 0;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].to;
			if (dis[e] < edge[i].w + dis[top]) {
				dis[e] = edge[i].w + dis[top];
				if (!vis[e]) {
					q.push(e);
					vis[e] = 1;
				}
			}
		}
	}
	printf("%d\n", dis[end]);
}
int main() {
	int x, y, w, s = 0x3f3f3f, t = -0x3f3f3f;
	scanf("%d", &n);
	id = 0;
	memset(pre, -1, sizeof pre);
	for (int i = 0; i < n+1; i++) dis[i] = -0x3f3f3f;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &y, &w);
		add(x, y+1, w);
		s = min(s, x);
		t = max(t, y+1);
	}
	for (int i = s; i <= t; i++) add(i, i+1, 0), add(i+1, i, -1);
	spfa(s, t);
	return 0;
}