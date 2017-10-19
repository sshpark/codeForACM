#include <iostream>
#define ll long long
using namespace std;
const int maxn = 100005;
ll sum[maxn<<2], lazy[maxn<<2];
void build(int l, int r, int rt) {
	lazy[rt] = 0;
	if (l == r) {
		scanf("%lld", sum+rt);
		return ;
	}
	int m = (l+r) >> 1;
	build(l, m, rt<<1);
	build(m+1, r, rt<<1|1);
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void pushDown(int rt, int m) {
	if (lazy[rt]) {
		lazy[rt<<1] += lazy[rt];
		lazy[rt<<1|1] += lazy[rt];
		sum[rt<<1] += (m - (m >> 1))*lazy[rt];
		sum[rt<<1|1] += (m >> 1)*lazy[rt];
		lazy[rt] = 0;
	}
}
void update(int L, int R, int add, int l, int r, int rt) {
	if (L <= l && r <= R) {
		lazy[rt] += add;
		sum[rt] += add*(r-l+1);
		return ;
	}
	pushDown(rt, r-l+1);
	int m = (l+r)>>1;
	if (L <= m) update(L, R, add, l, m, rt<<1);
	if (R > m) update(L, R, add, m+1, r, rt<<1|1);
	sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
ll query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return sum[rt];
	pushDown(rt, r-l+1);
	int m = (l+r)>>1;
	ll ret = 0;
	if (L <= m) ret += query(L, R, l, m, rt<<1);
	if (R > m) ret += query(L, R, m+1, r, rt<<1|1);
	return ret;
}
int main(int argc, char const *argv[])
{
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	int n, q;
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	char op[5];
	int x, y, w;
	while (q--) {
		scanf("%s", op);
		if (op[0] == 'Q') {
			scanf("%d %d", &x, &y);
			printf("%lld\n", query(x, y, 1, n, 1));
		}
		else {
			scanf("%d %d %d", &x, &y, &w);
			update(x, y, w, 1, n, 1);
		}
	}
	return 0;
}