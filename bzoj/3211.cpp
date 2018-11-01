#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

ll sum[maxn<<2];
int flag[maxn<<2];
void putup(int rt) {
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
    flag[rt] = flag[rt<<1]&flag[rt<<1|1];
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%lld", &sum[rt]);
        if (sum[rt] <= 1) flag[rt] = 1;
        else flag[rt] = 0;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    putup(rt);
}
void update(int L, int R, int l, int r, int rt) {
    if (flag[rt] == 1) return;
    if (l == r) {
        sum[rt] = floor(sqrt(sum[rt]));
        if (sum[rt] <= 1) flag[rt] = 1;
        return ;
    }

    int m = (l+r)>>1;

    if (L <= m) update(L, R, lson);
    if (R > m) update(L, R, rson);
    putup(rt);
}
ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    int m = (l+r)>>1;
    ll ans = 0;
    if (L <= m) ans += query(L, R, lson);
    if (R > m) ans += query(L, R, rson);
    return ans;

}

int main(int argc, char const *argv[])
{
    int n, m, l, r, op;
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) printf("%lld\n", query(l, r, 1, n, 1));
        else if (op == 2) update(l, r, 1, n, 1);
    }
    return 0;
}