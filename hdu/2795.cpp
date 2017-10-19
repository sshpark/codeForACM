#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 200005;
int n, w, h, x;
struct node {
    int l, r;
    int w;
}tree[maxn<<2];
void build(int l, int r, int rt) {
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].w = w;
    if (l == r) return;
    int mid = (l+r) >> 1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}
int query(int x, int rt) {
    if (tree[rt].l == tree[rt].r) {
        tree[rt].w -= x;
        return tree[rt].l;
    }
    int s1 = 0, s2 = 0;
    if (x <= tree[rt<<1].w) s1 = query(x, rt<<1);
    else if (x <= tree[rt<<1|1].w) s2 = query(x, rt<<1|1);
    tree[rt].w = max(tree[rt<<1].w, tree[rt<<1|1].w);
    return s1+s2;
}

int main(int argc, char const *argv[])
{
    while (~scanf("%d %d %d", &h, &w, &n)) {
        if (h > n) h = n;
        build(1, h, 1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x <= tree[1].w) printf("%d\n", query(x, 1));
            else puts("-1");
        }
    }
    return 0;
}