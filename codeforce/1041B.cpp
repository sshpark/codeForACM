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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    cout << min(a/x, b/y) << endl;

    return 0;
}