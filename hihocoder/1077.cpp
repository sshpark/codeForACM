#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1000005;
int mina[maxn<<2];
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", mina+rt);
        return ;
    }
    int m = (l+r) >> 1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    mina[rt] = min(mina[rt<<1], mina[rt<<1|1]);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return mina[rt];
    int mid = (l+r) >> 1, ret = 1000000;
    if (L <= mid) ret = min(ret, query(L, R, l, mid, rt<<1));
    if (R > mid) ret = min(ret, query(L, R, mid+1, r, rt<<1|1));
    return ret;
}
void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
        mina[rt] = val;
        return ;
    }
    int mid = (l+r) >> 1;
    if (p <= mid) update(p, val, l, mid, rt<<1);
    else update(p, val, mid+1, r, rt<<1|1);
    mina[rt] = min(mina[rt<<1], mina[rt<<1|1]);
}
int main(int argc, char const *argv[])
{
    int n, m, op, l, r;
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &op, &l, &r);
        if (op) update(l, r, 1, n, 1);
        else printf("%d\n", query(l, r, 1, n, 1));
    }
    return 0;
}