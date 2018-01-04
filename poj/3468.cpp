#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
ll sum[maxn<<2], add[maxn<<2];
struct node {
    int l, r;
    int mid() {
        return (l+r)>>1;
    }
}tree[maxn<<2];

void pushUp(int rt) {
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void pushDown(int rt, int m) {
    if (add[rt]) {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt]*(m-(m>>1));
        sum[rt<<1|1] += add[rt]*(m>>1);
        add[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    tree[rt].l = l;
    tree[rt].r = r;
    add[rt] = 0;
    if (l == r) {
        scanf("%d", &sum[rt]);
        return ;
    }
    int m = tree[rt].mid();
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    pushUp(rt);
}

void update(int c, int l, int r, int rt) {
    if (tree[rt].l == l && tree[rt].r == r) {
        add[rt] += c;
        sum[rt] += (ll)c*(r-l+1);
        return ;
    }
    if (tree[rt].l == tree[rt].r) return;
    pushDown(rt, tree[rt].r-tree[rt].l+1);
    int m = tree[rt].mid();
    if (r <= m) update(c, l, r, rt<<1);
    else if (l > m) update(c, l, r, rt<<1|1);
    else {
        update(c, l, m, rt<<1);
        update(c, m+1, r, rt<<1|1);
    }
    pushUp();
}

ll query(int l, int r, int rt) {
     if (tree[rt].l == l &&  tree[rt].r == r)
        return sum[rt];
    pushDown(rt, tree[rt].r-tree[rt].l+1);
    int m = tree[rt].mid();
    ll res = 0;
    if (r <= m) res += query(l, r, rt<<1);
    else if (l > m) res += query(l, r, rt<<1|1);
    else {
        res += query(l, m, rt<<1);
        res += query(m+1, r, rt<<1|1);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n, m, a, b, c;
    char op[5];
    while (~scanf("%d %d", &n, &m)) {
        build(1, n, 1);
        while (m--) {
            scanf("%s", op);
            if (op[0] == 'Q') {
                scanf("%d %d" , &a, &b);
                printf("%lld\n", query(a, b, 1));
            } else {
                scanf("%d %d %d", &a, &b, &c);
                update(c, a, b, 1);
            }
        }
    }
    return 0;
}