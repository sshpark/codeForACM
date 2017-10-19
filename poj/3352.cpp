#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 1005;
int pre[maxn], dfn[maxn], low[maxn], st[maxn], deg[maxn];
int id, col, dfs_clock, in;
struct node {
	int to;
	int next;
}edge[maxn*2];
void add(int x, int y) {
	edge[id].to = y;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void dfs(int u, int fa) {
	low[u] = dfn[u] = ++dfs_clock;
	st[in++] = u;
	for (int i = pre[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if (dfn[v] < dfn[u] && v != fa)
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		while (in > 0 && st[in] != u) {
			low[st[--in]] = low[u];
		}
	}
}
int main(int argc, char const *argv[])
{
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	memset(pre, -1, sizeof pre);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(st, 0, sizeof st);
	memset(deg, 0, sizeof deg);
	id = dfs_clock = in = 0;
	while (m--) {
		scanf("%d %d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs(i, -1);
	for (int i = 1; i <= n; i++)
		for (int j = pre[i]; j != -1; j = edge[j].next)
			if (low[i] != low[edge[j].to]) {
				deg[low[i]]++;
				deg[low[edge[j].to]]++;
			}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i]/2 == 1) ans++;
	printf("%d\n", (ans+1)/2);
	return 0;
}