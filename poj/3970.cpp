#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
    return a == 0 ? b : gcd(b%a, a);
}
int main(int argc, char const *argv[])
{
    int n;
    ll x;
    while (~scanf("%d", &n) && n) {
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            ans = ans*x/gcd(ans, x);
        }
        if (ans >= 1000000) puts("Too much money to pay!");
        else printf("The CEO must bring %lld pounds.\n", ans);
    }

    return 0;
}