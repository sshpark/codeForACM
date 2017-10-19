#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int pmax = 10005;
const int emax = 100005;
int n, m, id, dfs_clock, in, col;
struct node {
	int to;
	int next;
}edge[emax];
int pre[pmax], dfn[pmax], low[pmax], s[pmax], sccno[pmax];
inline void scan_d(int &ret) {
    char c; 
    ret = 0;
    while ((c = getchar()) < '0' || c > '9');
    while (c >= '0' && c <= '9')
    { 
        ret = ret * 10 + (c - '0'), c = getchar();
    }
}
inline void add(int x, int y) {
	edge[id].to = y;
	edge[id].next = pre[x];
	pre[x] = id++;
}
inline void init() {
	id = 0;
	col = 0;
	dfs_clock = 0;
	in = 0;
	memset(pre, -1, sizeof pre);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(sccno, 0, sizeof sccno);
}
void dfs(int u) {
	dfn[u] = low[u] = dfs_clock++;
	s[in++] = u;
	for (int i = pre[u]; i != -1; i = edge[i].next) {
		if (!dfn[edge[i].to]) {
			dfs(edge[i].to);
			low[u] = min(low[u], low[edge[i].to]);
		}
		else if (!sccno[edge[i].to])
			low[u] = min(low[u], dfn[edge[i].to]);
	}
	if (low[u] == dfn[u]) {
		col++;
		while (true) {
			sccno[s[in]] = col;
			if (s[in] == u) break;
			in--;
		}
	}
}
int main(int argc, char const *argv[])
{
	while(true) {
		init();
		scan_d(n), scan_d(m);
		if (n+m == 0) break;
		int x, y;
		while (m--) {
			scan_d(x), scan_d(y);
			add(x, y);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) dfs(i);
		puts(col <= 1 ? "Yes" : "No");
	}
	return 0;
}