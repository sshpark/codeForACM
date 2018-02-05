#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int n, c[maxn], cnt[maxn];
struct node {
    int id, s, e;
}a[maxn];

inline bool cmp(node a, node b) {
    if (a.e == b.e) return a.s < b.s;
    return a.e > b.e;
}

inline int lowbit(int x) {
    return x & (-x);
}
inline void add(int x, int val) {
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += val;
}
inline int getsum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
int main(int argc, char const *argv[])
{
    int s, e;
    while (~scanf("%d", &n) && n) {
        memset(c, 0, sizeof c);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a[i].s, &a[i].e);
            a[i].s++, a[i].e++;
            a[i].id = i;
        }
        sort(a, a+n, cmp);
        cnt[a[0].id] = getsum(a[0].s); add(a[0].s, 1);
        for (int i = 1; i < n; i++) {
            // printf("%d %d\n", a[i].s, a[i].e);
            if (a[i].s == a[i-1].s && a[i].e == a[i-1].e) cnt[a[i].id] = cnt[a[i-1].id];
            else cnt[a[i].id] = getsum(a[i].s);
            add(a[i].s, 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", cnt[i], " \n"[i==n-1]);
    }
    return 0;
}