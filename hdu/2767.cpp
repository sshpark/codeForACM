#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int emax = 50005;
const int pmax = 20005;
int dfn[pmax], low[pmax], st[pmax], pre[pmax], sccno[pmax], in_0[pmax], out[pmax];
int id, in, dfs_clock, col;
struct node {
	int to;
	int next;
}edge[emax];
inline bool scan_d(int &ret) {  
   char c; int sgn;  
   if(c=getchar(),c==EOF) return 0; //EOF  
   while(c!='-'&&(c<'0'||c>'9')) c=getchar();  
   sgn=(c=='-')?-1:1;  
   ret=(c=='-')?0:(c-'0');  
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');  
   ret*=sgn;  
   return 1;  
}
inline void init() {
	id = col = dfs_clock = in = 0;
	memset(pre, -1, sizeof pre);
	memset(dfn, 0, sizeof dfn);
	memset(low, 0, sizeof low);
	memset(out, 0, sizeof out);
	memset(in_0, 0, sizeof in_0);
	memset(st, 0, sizeof st);
	memset(sccno, 0, sizeof sccno);
}
inline void add(int x, int y) {
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
int main(int argc, char const *argv[])
{
	int n, m, x, y;
	int T;
	scan_d(T);
	while (T--) {
		init();
		scan_d(n), scan_d(m);
		while (m--) {
			scan_d(x), scan_d(y);
			add(x, y);
		}
		for (int i = 1; i <= n; i++)
			if (!dfn[i]) dfs(i);
		for (int i = 1; i <= n; i++)
			for (int j = pre[i]; j != -1; j = edge[j].next)
				if (sccno[i] != sccno[edge[j].to]) {
					in_0[sccno[edge[j].to]]++;
					out[sccno[i]]++;
				}
		if (col == 1) {
			puts("0");
			continue;
		}
		int ans = 0, ans1 = 0;
		for (int i = 1; i <= col; i++) {
			if (in_0[i] == 0) ans++;
			if (out[i] == 0) ans1++;
		}
		printf("%d\n", max(ans, ans1));
	}
	return 0;
}