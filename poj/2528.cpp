#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
const int maxn = 12222;
int vis[maxn], col[maxn<<4], l[maxn], r[maxn], san[maxn<<2], lazy[maxn<<4], ans;
void pushDown(int rt) {
	if (col[rt] != -1) {
		col[rt<<1] = col[rt<<1|1] = col[rt];
		col[rt] = -1;
	}
}
void update(int L, int R, int l, int r, int rt, int c) {
	if (L <= l && r <= R) {
		col[rt] = c;
		return ;
	}
	pushDown(rt);
	int m = (l+r)>>1;
	if (L <= m) update(L, R, l, m, rt<<1, c);
	if (R > m) update(L, R, m+1, r, rt<<1|1, c);
}
void query(int l, int r, int rt) {
	if (col[rt] != -1) {
		if (!vis[col[rt]]) ans++;
		vis[col[rt]] = 1;
		return;
	}
	if (l == r) return ;
	int m = (l+r)>>1;
	query(l, m, rt<<1);
	query(m+1, r, rt<<1|1);
}
int main(int argc, char const *argv[])
{
	int T, n;
	scanf("%d", &T);
	while (T--) {
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", l+i, r+i);
			san[cnt++] = l[i], san[cnt++] = r[i];
		}
		sort(san, san+cnt);
		int m = 1;
		for (int i = 1; i < cnt; i++) if (san[i] != san[i-1]) san[m++] = san[i];
		for (int i = m-1; i >= 1; i--) if (san[i] != san[i-1]+1) san[m++] = san[i-1]+1;
		sort(san, san+m);
		memset(col, -1, sizeof col);
		for (int i = 0; i < n; i++) {
			int ll = lower_bound(san, san+m, l[i]) - san;
			int rr = lower_bound(san, san+m, r[i]) - san;
			update(ll, rr, 0, m, 1, i);
		}
		memset(vis, 0, sizeof vis);
		ans = 0;
		query(0, m, 1);
		printf("%d\n", ans);
	}
	return 0;
}