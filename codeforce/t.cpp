#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}
ll mod_inverse(ll a, ll m)
{
    ll x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

ll qmod(ll a, int b) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = (res*a)%mod;
    a = (a*a)%mod;
    b >>= 1;
  }
  return res;
}
int main(int argc, char const *argv[])
{
    printf("%lld\n", (25*qmod(6, mod-2))%mod);
    return 0;
}