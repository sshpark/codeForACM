#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
ll p[maxn], cnt = 0;
void getp(int x) {
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) {
            p[cnt++] = i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) p[cnt++] = x;
}
ll getsum(int n, int m) {
    ll ans = 0;
    getp(m);
    for (int i = 1; i < (1<<cnt); i++) {
        ll tmep = 1, lop = 0;
        for (int j = 0; j < cnt; j++) {
            if (i&(1<<j)) {
                tmep *= p[j];
                lop++;
            }
        }
        if (lop&1) ans += n/tmep;
        else ans -= n/tmep;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int T, a, b, c, d, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        b /= k;
        d /= k;
        if (b > d) swap(b, d);
        ll ans = 0;
        for (int i = 1; i <= d; i++) {
            int k = min(i, b);
            ans += k;
            
        }
        printf("%lld\n", ans);

    }
    return 0;
}