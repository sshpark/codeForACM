#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const ll maxn = 1e18+100;
ll a[1000005], cnt = 0;
void init() {
    for (ll i = 1; i < maxn; i *= 2)
        for (ll j = 1; j*i < maxn; j *= 3)
            for (ll k = 1; i*j*k < maxn; k *= 5)
                a[cnt++] = i*j*k;
}
int main(int argc, char const *argv[])
{
    int T, l, r, mid;
    ll n;
    init();
    sort(a, a+cnt);
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        mid = 0, l = 1, r = cnt;
        while (l <= r) {
            mid = (l+r) >> 1;
            if (a[mid] >= n) r = mid-1;
            else l = mid+1;
        }
        printf("%lld\n", a[mid]);
    }
    return 0;
}