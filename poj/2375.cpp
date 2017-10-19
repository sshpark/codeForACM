#include <iostream>
using namespace std;
const int maxn = 300005;
int w, l, id, col, in, dfs_clock;
int pre[maxn], dfn[maxn], low[maxn], map[505][505], sccno[maxn], st[maxn];
int out[maxn], in_0[maxn];
int nxt[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node
{
	int to;
	int next;
}edge[maxn<<2];
void add(int x, int y) {
	edge[id].to = y;
	edge[id].next = pre[x];
	pre[x] = id++;
}
void dfs(int u) {
	low[u] = dfn[u] = ++dfs_clock;
	st[in++] = u;
	for (int i = pre[u]; i != -1; i = edge[i].next) {
		int v = edge[i].to;
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if (!sccno[v]) low[u] = min(low[u], dfn[v]);
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

int main(int argc, char const *argv[])
{
	scanf("%d %d", &w, &l);
	for (int i = 0; i < l; i++) 
		for (int j = 0; j < w; j++)
			scanf("%d", &map[i][j]);
	memset(pre, -1, sizeof pre);
	memset(sccno, 0, sizeof sccno);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	dfs_clock = in = id = col = 0;
	for (int i = 0; i < l; i++)
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + nxt[k][0];
				int ny = j + nxt[k][1];
				if (nx >= 0 && ny >= 0 && nx < l && ny < w) {
					if (map[i][j] >= map[nx][ny]) {
						int u = i*w+j;
						int v = nx*w+ny;
						add(u, v);
					}
				}
			}
		}
	int n = w*l;
	for (int i = 0; i < n; i++)
		if (!dfn[i]) dfs(i);
	if (col <= 1) {
		printf("0\n");
		return 0;
	}
	memset(out, 0, sizeof out);
	memset(in_0, 0, sizeof in_0);
	for (int i = 0; i < n; i++)
		for (int j = pre[i]; j != -1; j = edge[j].next)
			if (sccno[i] != sccno[edge[j].to]) {
				in_0[sccno[edge[j].to]]++;
				out[sccno[i]]++;
			}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= col; i++) {
		if (!in_0[i]) ans1++;
		if (!out[i]) ans2++;
	}
	printf("%d\n", max(ans1, ans2));
	return 0;
}