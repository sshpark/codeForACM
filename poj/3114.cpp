#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int pmax = 505;
const int emax = 500005;
int n, m, id, col, dfs_clock, in;
int pre[pmax], dfn[pmax], low[pmax], st[pmax], sccno[pmax], dis[pmax];
struct node {
	int to;
	int w;
	int next;
}edge[emax];
void init() {
	memset(pre, -1, sizeof pre);
	memset(low, 0, sizeof low);
	memset(dfn, 0, sizeof dfn);
	memset(st, 0, sizeof st);
	memset(sccno, 0, sizeof sccno); 
	in = id = col = dfs_clock = 0;
}
void add(int x, int y, int w) {
	edge[id].to = y;
	edge[id].w = w;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void dfs(int u) {
	dfn[u] = low[u] = ++dfs_clock;
	st[in++] = u;
	for (int i = pre[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!sccno[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		col++;
		in--;
		while (true) {
			sccno[st[in]] = col;
			if (st[in] == u) break;
			in--;
		}
	}
}
int spfa(int start, int end) {
	if (start == end)
		return 0x3f3f3f3f;
	queue<int> q;
	int vis[pmax];
	for (int i = 0; i <= n; i++) {
		vis[i] = 0;
		dis[i] = 0x3f3f3f3f;
	}
	q.push(start);
	vis[start] = 1;
	dis[start] = 0;
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		vis[top] = 0;
		for (int i = pre[top]; i != -1; i = edge[i].next) {
			int e = edge[i].to;
			if (sccno[e] == sccno[top])
				edge[i].w = 0;
			if (dis[e] > dis[top] + edge[i].w) {
				dis[e] = dis[top] + edge[i].w;
				if (!vis[e]) {
					q.push(e);
					vis[e] = 1;
				}
			}
		}		
	}
	return dis[end];
}
int main(int argc, char const *argv[])
{
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj//data.in", "r", stdin);
	while (~scanf("%d %d", &n, &m) && n+m) {
		init();
		int x, y, w;
		while (m--) {
			scanf("%d %d %d", &x, &y, &w);
			add(x, y, w);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) dfs(i);
		int k;
		scanf("%d", &k);
		while (k--) {
			scanf("%d %d", &x, &y);
			int len = spfa(x, y);
			if (len != 0x3f3f3f3f) printf("%d\n", len);
			else puts("Nao e possivel entregar a carta");
		}
		printf("\n");
	}
	return 0;
}