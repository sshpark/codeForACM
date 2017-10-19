#include <iostream>
#include <queue>
#include <string.h>
#include <stdio.h>
using namespace std;
const int pmax = 105;
const int emax = 505;
int pre[pmax], vis[pmax], dis[pmax], id;
int n, m;
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
void spfa() {
	queue<int> q;
	int cnt[pmax];
	memset(vis, 0, sizeof vis);
	for (int i = 0; i <= n+1; i++){dis[i] = 0x3f3f3f; cnt[i] = 0;}
	q.push(n+1);
	vis[n+1] = 1;dis[n+1] = 0;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = 0;
		cnt[top]++;
		if (cnt[top] > n+1) {
			printf("successful conspiracy\n");  
			return ; 
		}
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].to;
			if (dis[e] > edge[i].w + dis[top]) {
				dis[e] = edge[i].w + dis[top];
				if (!vis[e]) {
					q.push(e);
					vis[e] = 1;
				}
			}
		}
	}
	printf("lamentable kingdom\n"); 
}

int main() {
	while (cin >> n && n) {
		cin >> m;
		id = 0;
		int x, y, w;
		char op[5];
		memset(pre, -1, sizeof pre);
		
		for (int i = 0; i < m; i++) {
			scanf("%d %d %s %d", &x, &y, op, &w);
			if (op[0] == 'g')
				add(x+y, x-1, -w-1);
			else
				add(x-1, x+y, w-1);
		}
		for (int i = 0; i <= n; i++) add(n+1, i, 0);
		spfa();
	}
	return 0;
}