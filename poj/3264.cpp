#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 500005;
int maxa[maxn<<2], mina[maxn<<2];
int x;
void pushUp(int rt) {
	maxa[rt] = max(maxa[rt<<1], maxa[rt<<1|1]);
	mina[rt] = min(mina[rt<<1], mina[rt<<1|1]);
}
void build(int l, int r, int rt) {
	if (l == r) {
		scanf("%d", &x);
		maxa[rt] = x;
		mina[rt] = x;
		return;
	}
	int m = (l+r) >> 1;
	build(l, m, rt<<1);
	build(m+1, r, rt<<1|1);
	pushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return maxa[rt];
	int m = (l+r)/2, ret = -1;
	if (L <= m) ret = max(ret, query(L, R, l, m, rt<<1));
	if (R > m) ret = max(ret, query(L, R, m+1, r, rt<<1|1));
	return ret;
}
int query1(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return mina[rt];
	int m = (l+r)/2, ret = 0x3f3f3f;
	if (L <= m) ret = min(ret, query1(L, R, l, m, rt<<1));
	if (R > m) ret = min(ret, query1(L, R, m+1, r, rt<<1|1));
	return ret;
}
int main(int argc, char const *argv[])
{
	int n, q, y;
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	while (q--) {
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x, y, 1, n, 1)-query1(x, y, 1, n, 1));
	}
	return 0;
}