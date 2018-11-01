#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
const int maxn = 1005;
int a[maxn<<2];

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

void putup(int rt) {
    a[rt] = gcd(a[rt<<1], a[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", a+rt);
        return ;
    }
    int m =(l+r)>>1;
    build(lson);
    build(rson);
    putup(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return a[rt];
    }
    int m = (l+r) >> 1;
    int ans = 0;
    if (L <= m) ans = query(L, R, lson);
    if (R > m) ans = gcd(ans, query(L, R, rson));
    return ans;
}



int main(int argc, char const *argv[])
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    build(1, n, 1);
    while (m--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", query(u, v, 1, n, 1));
    }
    return 0;
}