#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct edge {
    double l, r;
    double h;
    int f;
}e[maxn<<1];
bool cmp(edge a, edge b) {
    return a.h < b.h;
}
struct node {
    int l, r;
    int s;
    double len;
}q[maxn*8];
double x[maxn<<1];
void build(int rt, int l, int r) {
    q[rt].l = l, q[rt].r = r;
    q[rt].s = 0, q[rt].len = 0;
    if (l == r) return;
    int mid = (q[rt].l+q[rt].r) >> 1;
    build(rt<<1, l, mid);
    build(rt<<1|1, mid+1, r);
}
void pushUp(int i) {
    if (q[i].s) //已经被覆盖
        q[i].len = x[q[i].r+1] - x[q[i].l];
    else if (q[i].l == q[i].r) q[i].len = 0; //这是一个点
    else q[i].len = q[i<<1].len+q[i<<1|1].len;
}
void update(int rt, int l, int r, int xx) {
    if (q[rt].l == l && q[rt].r == r) {
        q[rt].s += xx;
        pushUp(rt);
        return ;
    }
    int mid = (q[rt].l+q[rt].r) >> 1;
    if (r <= mid) update(rt<<1, l, r, xx);
    else if (l > mid) update(rt<<1|1, l, r, xx);
    else {
        update(rt<<1, l, mid, xx);
        update(rt<<1|1, mid+1, r, xx);
    }
    pushUp(rt);
}

int main(int argc, char const *argv[])
{
    int n, kase = 0;
    while (~scanf("%d", &n) && n) {
        int tot = 0;
        double x1, x2, y1, y2;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            edge &t1 = e[tot]; edge &t2 = e[1+tot];
            t1.l = t2.l = x1, t1.r = t2.r = x2;
            t1.h = y1, t1.f = 1;
            t2.h = y2, t2.f = -1;
            x[tot] = x1, x[tot+1] = x2;
            tot+=2;
        }
        sort(e, e+tot, cmp);
        sort(x, x+tot);
        int k = 1;
        for (int i = 1; i < tot; i++) {
            if (x[i] != x[i-1]) x[k++] = x[i]; //去重
        }
        build(1, 0, k-1); //离散化后的区间是0, k-1
        double ans = 0;
        for (int i = 0; i < tot; i++) {
            int l = lower_bound(x, x+k, e[i].l)-x;
            int r = lower_bound(x, x+k, e[i].r)-x-1;
            update(1, l, r, e[i].f);
            ans += q[1].len*(e[i+1].h-e[i].h);
        }
        printf("Test case #%d\n", ++kase);
        printf("Total explored area: %.2lf\n\n", ans);
    }
    return 0;
}