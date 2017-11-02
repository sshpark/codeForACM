#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define ll long long
using namespace std;
int cnt = 0, p[10005], re[100005], rec = 0;
bool isp[10005];
inline void shai() {
    memset(isp, true, sizeof isp);
    for (int i = 2; i < 10005; i++)
        if (isp[i]) {
            p[cnt++] = i;
            for (ll j = i*i; j < 10005; j += i)
                isp[j] = false;
        }
}
inline void fenJie(ll x) {
    for (int i = 0; i < cnt; i++) {
        if (p[i]*p[i] > x) break;
        while (x % p[i] == 0) re[rec++] = p[i], x /= p[i];
    }
    if (x > 1) re[rec++] = x;
}
int main(int argc, char const *argv[])
{
    int T, n;
    ll x;
    shai();
    scanf("%d", &T);
    while (T--) {
        rec = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &x);
            fenJie(x);
        }
        if (rec < 2) {
            puts("-1");
            continue;
        }
        sort(re, re+rec);
        if (re[1] < 2) {
            puts("-1");
            continue;
        }
        printf("%lld\n", 1LL*re[0]*re[1]);
    }
    return 0;
}