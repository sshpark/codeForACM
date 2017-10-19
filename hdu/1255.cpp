#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
double pos[maxn<<1];
int n;
struct node {
    double l, r, h;
    int v;
}s[maxn<<1];
struct node1 {
    int l, r, cnt;
    double s, ss;
    int mid()
    {return (l+r)>>1;}
}t[maxn*8];
bool cmp(node a, node b) {
    return a.h < b.h;
}
void build(int l, int r, int rt) {
    t[rt].l = l, t[rt].r = r;
    t[rt].cnt = t[rt].s = t[rt].ss = 0;
    if (l == r) return ;
    int mid = t[rt].mid();
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}
void cal(int rt) {
    if (t[rt].cnt)
        t[rt].s = pos[t[rt].r+1] - pos[t[rt].l];
    else if (t[rt].l == t[rt].r) t[rt].s = 0;
    else t[rt].s = t[rt<<1].s+t[rt<<1|1].s;
    
    if (t[rt].cnt > 1)
        t[rt].ss = pos[t[rt].r+1] - pos[t[rt].l];
    else if (t[rt].l == t[rt].r) t[rt].ss = 0;
    else if (t[rt].cnt == 1) t[rt].ss = t[rt<<1].s+t[rt<<1|1].s;
    else t[rt].ss = t[rt<<1].ss+t[rt<<1|1].ss;
}
void update(int l, int r, int v, int rt) {
    if (t[rt].l == l && t[rt].r == r) {
        t[rt].cnt += v;
        cal(rt);
        return ;
    }
    int mid = t[rt].mid();
    if (r <= mid) update(l, r, v, rt<<1);
    else if (l > mid) update(l, r, v, rt<<1|1);
    else {
        update(l, mid, v, rt<<1);
        update(mid+1, r, v, rt<<1|1);
    }
    cal(rt);
}
int bfind(double key, int low, int high) {
    while  (low <= high) {
        int mid = (low+high)>>1;
        if (pos[mid] == key)
            return mid;
        else if (pos[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int i, k;
        for (i = 0, k = 0; i < n; i++, k+=2) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            pos[k] = x1, pos[k+1] = x2;
            s[k].l = x1, s[k].r = x2;
            s[k].h = y1, s[k].v = 1;
            s[k+1].l = x1, s[k+1].r = x2;
            s[k+1].h = y2, s[k+1].v = -1;
        }
        sort(pos, pos+k);
        sort(s, s+k, cmp);
        int m = 1;
        for (int i = 1; i < k; i++)
            if (pos[i] != pos[i-1])
                pos[m++] = pos[i];
        build(0, m-1, 1);
        double res = 0;
        for (i = 0; i < k-1; i++) {
            int l = bfind(s[i].l, 0, m-1);
            int r = bfind(s[i].r, 0, m-1)-1;
            update(l, r, s[i].v, 1);
            res += t[1].ss*(s[i+1].h-s[i].h);
        }
        printf("%.2lf\n", res);
    }
    return 0;
}