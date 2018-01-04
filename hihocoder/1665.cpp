#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 100005;
int maxa[maxn<<2], lazy[maxn<<2];
inline void pushUp(int rt) {
    maxa[rt] = max(maxa[rt<<1], maxa[rt<<1|1]);
}
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    if (l == r) {
        maxa[rt] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}

inline void pushDown(int rt) {
    if (lazy[rt]) {
        maxa[rt<<1] = lazy[rt];
        maxa[rt<<1|1] = lazy[rt];
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
}

void update(int val, int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        lazy[rt] = val;
        maxa[rt] = val;
        return ;
    }
    pushDown(rt);
    int m = (l+r)>>1;
    if (L <= m) update(val, L, R, lson);
    if (R > m) update(val, L, R, rson);
    pushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return maxa[rt];
    pushDown(rt);
    int m = (l+r)>>1;
    int res = 0;
    if (L <= m) res = max(res, query(L, R, lson));
    if (R > m) res = max(res, query(L, R, rson));
    return res;
}

int main(int argc, char const *argv[])
{
    // freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    int n, a, b;
    scanf("%d", &n);
    build(1, 100000, 1);
    while (n--) {
        scanf("%d %d", &a, &b);
        int ans = query(a, b, 1, 100000, 1);
        printf("%d\n", ans+1);
        update(ans+1, a, b, 1, 100000, 1);
    }
    return 0;
}