#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll cnt, num[1000005];
const ll mod = 1000000007;
void euler(ll n) {
    cnt = 0;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            num[cnt++] = i;
            while(n%i == 0)
                n /= i;
        }
    }
    if (n > 1) num[cnt++] = n;
}

ll get1(ll n) {
    return 
}

ll solve(ll n, ll m) {
    euler(m);
    ll ans = 0;
    for (ll i = 1; i < (1<<cnt); i++) {
        ll temp = 1, lop = 0;
        for (ll j = 0; j < cnt; j++) {
            if (i&(1<<j)) {
                lop++;
                temp *= num[j];
            }
        }

        if (lop&1) ans = 

    }
}

int main(int argc, char const *argv[])
{
    int n, m;

    return 0;
}