#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
#define ll long long
const int maxn = 2005;
int pre[maxn], scnno[maxn], dfn[maxn], low[maxn], st[maxn], in_0[maxn], vis[maxn];
ll cost1[maxn];
int id, dfs_colck, col, in;
struct node {
	int to;
	int next;
}edge[maxn*maxn];
struct pos {
	ll x, y, r, cost;
}bomb[maxn];
void init() {
	in = id = dfs_colck = col = 0;
	memset(pre, -1, sizeof pre);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(scnno, 0, sizeof scnno);
	memset(in_0, 0, sizeof in_0);
	memset(st, 0, sizeof st);
	for (int i = 0; i < 2000; i++)
		cost1[i] = 100000;
}
void add(int x, int y) {
	edge[id].to = y;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void tarjan(int u) {
	low[u] = dfn[u] = ++dfs_colck;
	st[in++] = u;
	vis[u] = 1;
	for (int i = pre[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!scnno[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		col++;
		int v;
        do{
            v = st[--in];
            scnno[v] = col;
            cost1[col] = min(cost1[col], bomb[v].cost);
            vis[v] = 0;
        }while(u != v);
	}
}
int main(int argc, char const *argv[])
{
	int T, n, kase = 1;
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld %lld %lld %lld", &bomb[i].x, &bomb[i].y, &bomb[i].r, &bomb[i].cost);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if ((bomb[i].x-bomb[j].x)*(bomb[i].x-bomb[j].x)+(bomb[i].y-bomb[j].y)*(bomb[i].y-bomb[j].y) <= (bomb[i].r*bomb[i].r))
					add(i, j);
				}
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) tarjan(i);
		for (int i = 1; i <= n; i++)
		for (int j = pre[i]; j != -1; j = edge[j].next)
			if (scnno[i] != scnno[edge[j].to])
				in_0[scnno[edge[j].to]]++;
		int sum = 0;
		for (int i = 1; i <= col; i++)
			if (in_0[i] == 0)
				sum += cost1[i];
		printf("Case #%d: %d\n", kase++, sum);
	}
	return 0;
}