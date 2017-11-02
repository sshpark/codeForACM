#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 100005;
int mina[maxn<<2];
void init(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", mina+rt);        
        return ;
    }
    int m = (l+r) >> 1;
    init(l, m, rt<<1);
    init(m+1, r, rt<<1|1);
    mina[rt] = min(mina[rt<<1], mina[rt<<1|1]);
}
void update(int p, int val, int l, int r, int rt) {
    if (l == r) {
        mina[rt] = val;
        return ;
    }
    int m = (l+r) >> 1;
    if (p <= m) update(p, val, l, m, rt<<1);
    else update(p, val, m+1, r, rt<<1|1);
    mina[rt] = min(mina[rt<<1], mina[rt<<1|1]);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return mina[rt];
    int m = (l+r) >> 1;
    int ret = 1000000000;
    if (L <= m) ret = min(ret, query(L, R, l, m, rt<<1));
    if (m < R) ret = min(ret, query(L, R, m+1, r, rt<<1|1));
    return ret;
}
int main(int argc, char const *argv[])
{
    int n, m, l, r, op;
    scanf("%d", &n);
    init(1, n, 1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &op, &l, &r);
        if (op) update(l, r, 1, n, 1);
        else printf("%d\n", query(l, r, 1, n, 1));
    }
    return 0;
}