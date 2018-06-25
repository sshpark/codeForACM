#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
ll a[maxn];
int main(int argc, char const *argv[])
{
    int n, m;
    ll x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    for (int i = 1; i < n; i++) a[i] += a[i-1];
    while (m--) {
        scanf("%lld", &x);
        int pos = lower_bound(a, a+n, x)-a;
        printf("%d", pos+1);
        if (pos == 0) {
            printf(" %lld\n", x);
        } else printf(" %lld\n", x-a[pos-1]);
    }
    return 0;
}