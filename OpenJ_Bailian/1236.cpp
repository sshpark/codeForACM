#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int pmax = 105;
const int emax = 20005;
int n, m, id, dfs_clock, col, in;
int pre[pmax], sccno[pmax], low[pmax], dfn[pmax], st[pmax], in_0[pmax], out[pmax];
struct node {
	int to;
	int next;
}edge[emax];
void add(int x, int y) {
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
		else if (!sccno[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		col++;
		in--;
		while(true) {
			sccno[st[in]] = col;
			if (st[in] == u) break;
			in--;
		}
	}
}
int main(int argc, char const *argv[])
{
	int x;
	while (~scanf("%d", &n)) {
		memset(pre, -1, sizeof pre);
		memset(sccno, 0, sizeof sccno);
		memset(dfn, 0, sizeof dfn);
		memset(in_0, 0, sizeof in_0);
		memset(out, 0, sizeof out);
		memset(low, 0, sizeof low);
		id = 0, dfs_clock = 0, col = 0, in = 0;
		for (int i = 1; i <= n; i++) {
			while (~scanf("%d", &x) && x)
				add(i, x);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) dfs(i);
		if (col == 1) {
			printf("1\n0\n");
			return 0;
		}
		for (int i = 1; i <= n; i++)
			for (int j = pre[i]; j != -1; j = edge[j].next)
				if (sccno[i] != sccno[edge[j].to]) {
					in_0[sccno[edge[j].to]]++;
					out[sccno[i]]++;
				}
		int ans = 0, ans1 = 0;
		for (int i = 1; i <= col; i++) {
			if (out[i]==0) ans++;
			if (in_0[i]==0) ans1++;
		}
		printf("%d\n%d\n", ans1, max(ans1, ans));		
	}
	return 0;
}