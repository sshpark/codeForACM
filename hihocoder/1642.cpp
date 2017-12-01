#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn = 100005;
struct node {
    int l, r;
}p[maxn];
inline bool cmp(node a, node b){return a.l < b.l;}
int main(int argc, char const *argv[])
{
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        p[i].l = x-y;p[i].r = x+y;
    }
    sort(p, p+n, cmp);
    double ans = 0;
    int right = -100000000;
    for (int i = 0; i < n; i++) {
        if (p[i].r > right) {
            ans += (double)(p[i].r-p[i].l)*(double)(p[i].r-p[i].l)*0.25;
            if (p[i].l < right) ans -= (double)(right-p[i].l)*(double)(right-p[i].l)*0.25;
            right = max(right, p[i].r);
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}