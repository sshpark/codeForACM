#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll solve(ll n, ll x) {
    ll mul = 1, ans = 0;
    ll t = n;
    while (t) {
        ll m = t%10;
        if (m < x) ans += (t/10)*mul;
        else if (m == x) ans += (t/10)*mul+n%mul+1;
        else if (m > x) ans += (t/10+1)*mul;
        if (x == 0) ans -= mul;
        t /= 10;
        mul *= 10;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; i++)
        printf("%lld\n", solve(b, i)-solve(a-1, i));
    return 0;
}