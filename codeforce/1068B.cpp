#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
inline int getsum(ll x) {
    int sum = 2;
    ll len = sqrt(x);
    for (ll i = 2; i <= len; i++) {
        if (x % i == 0) {
            sum++;
            if (x/i != i) sum++;
        }
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    ll n;
    while (cin >> n) {
        if (n == 1) cout << 1 << endl;
        else cout << getsum(n) << endl;
    }
    return 0;
}