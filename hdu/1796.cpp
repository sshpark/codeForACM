#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long

int main(int argc, char const *argv[])
{
    ll n, m;
    ll a[15];
    while (cin >> n >> m) {
        ll cnt = 0, x;
        for (ll i = 0; i < m; i++) {
            cin >> x;
            if (x > 0) a[cnt++] = x;
        }

        ll ans = 0, len = 1<<cnt;
        n--;
        for (ll i = 1; i < len; i++) {
            ll temp = 1;
            ll p = 0;
            for (ll j = 0; j < cnt; j++) {
                if (i&(1<<j)) {
                    temp *= a[j];
                    p++;
                }
            }
            if (p&1) ans += n/temp;
            else ans -= n/temp;
        }
        cout << ans << endl;
    }


    return 0;
}