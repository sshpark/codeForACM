#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int pmax = 10005;
const int emax = 50005;
int n, m, id, dfs_clock, in, col;
int pre[pmax], sccno[pmax], dfn[pmax], low[pmax], st[pmax], sum[pmax], out[pmax];
struct node {
	int to;
	int next;
}edge[emax];

inline void add(int x, int y) {
	edge[id].to = y;
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
		else if  (!sccno[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		int cnt = in;
		in--;
		col++;
		while (true) {
			sccno[st[in]] = col;
			if (st[in] == u) break;
			in--;
		}
		sum[col] = cnt - in;
	}
}
 
int main(int argc, char const *argv[])
{
	int x, y;
	scanf("%d %d", &n, &m);
	memset(pre, -1, sizeof pre);
	memset(sccno, 0, sizeof sccno);
	memset(sum, 0, sizeof sum);
	memset(out, 0, sizeof out);
	id = 0, dfs_clxock = 0, in = 0, col = 0;
	while (m--) {	
		scanf("%d %d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		for (int j = pre[i]; j != -1; j = edge[j].next) {
			if (sccno[i] != sccno[edge[j].to]) out[sccno[i]]++;
		}
	int r = 0, pos = 0;
	for (int i = 0; i <= col; i++) {
		if (!out[i]) {
			if (r > 0) {
				puts("0");
				return 0;
			}
			r = sum[i];
		}
	}

	printf("%d\n", r);
	return 0;
}