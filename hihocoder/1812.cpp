#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
map<ll, ll> mm;
map<ll, ll>::iterator iter;
int main(int argc, char const *argv[])
{
    int n;
    ll x, y;
    ll w;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &x, &y, &w);
        mm[x*x+y*y] += w;
    }
    ll maxa = -1000000000, cur = 0;
    for (iter = mm.begin(); iter != mm.end(); iter++) {
        cur += (*iter).second;
        maxa = max(maxa, cur);
    }
    printf("%lld\n", maxa);
    return 0;
}