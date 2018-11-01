#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 1000005;
bool isp[maxn];
ll p[maxn];
ll cnt = 0;
void shai() {
    memset(isp, true, sizeof isp);

    for (ll i = 2; i < maxn; i++) {
        if (isp[i]) p[cnt++] = i;
        for (ll j = i*i; j < maxn; j += i)
            isp[j] = false;
    }
}
ll phi(ll n) {
    ll res = n;

    for (ll i = 0; p[i]*p[i] <= n; i++) {
        if (n % p[i] == 0) {
            res -= res/p[i];
            while (n%p[i]==0) n /= p[i];
        }
    }
    if (n > 1) res -= res/n;
    return res;
}
int main(int argc, char const *argv[])
{
    ll n;
    shai();
    while (~scanf("%lld", &n)) {
        ll ans = 0;
        for (ll i = 1; i*i <= n; i++) {
            if (i*i == n) {
                ans += i*phi(n/i);
            } else if (n%i == 0) {
                ans += i*phi(n/i)+(n/i)*phi(i);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}