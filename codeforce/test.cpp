#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1005;
struct node {
    int s, t;
}a[maxn*maxn];
ll c[maxn];
inline bool cmp(node a, node b) {
    if (a.t == b.t) return a.s > b.s;
    return a.t > b.t;
}
inline int lowbit(int x) {
    return x & (-x);
}
inline void add(int x, int val) {
    for (int i = x; i < maxn; i += lowbit(i))
        c[i] += val;
}
inline ll getsum(int x) {
    ll ans = 0;
    for (int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}
int main(int argc, char const *argv[])
{
    int T, n, m, k, u, v;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        memset(c, 0, sizeof c);
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < k; i++)
            scanf("%d %d", &a[i].s, &a[i].t);
        sort(a, a+k, cmp);
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            sum += getsum(a[i].s-1);
            add(a[i].s, 1);
        }
        printf("Test case %d: %lld\n", t, sum);
    }
    return 0;
}