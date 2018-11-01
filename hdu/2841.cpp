#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const ll maxn = 100005;
ll p[maxn], a[maxn];
ll cnt = 0;

void euler(ll n)
{
    cnt = 0;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            a[cnt++] = i;
            while(n%i == 0)
                n /= i;
        }
    }
    if(n > 1) a[cnt++] = n;
}




ll getsum(ll x, ll y) {
    ll id = 0;
    euler(x);
    
    
    ll ans = y;
    for (ll i = 1; i < (1<<cnt); i++) {
        ll temp = 1;
        ll lop = 0;
        for (ll j = 0; j < cnt; j++) {
            if (i&(1<<j)) {
                lop++;
                temp *= a[j];
            }
        }
        if (lop&1) ans -= y/temp;
        else ans += y/temp;

    }
    return ans;
}
ll solve(ll x, ll y) {
    ll ans = 0;
    for (ll i = 1; i <= x; i++) {
        ans += getsum(i, y);        

    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ll n, m;
    ll T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld %lld", &n, &m);
        printf("%lld\n", solve(n, m));
    }

    return 0;
}