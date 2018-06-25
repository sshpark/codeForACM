#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[100005];
int main(int argc, char const *argv[])
{
    int n;
    ll sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        sum += a[i];
    }
    sort(a, a+n);
    if (a[n-1]-a[0] <= 1) {
        printf("%d\n", n);
        for (int i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");
        return 0;
    }
    int l = 0, r = 0, m = 0, same = n, mincnt = l;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[0]) l++;
        if (a[i] == a[0]+1) m++;
        if (a[i] == a[n-1]) r++;
    }
    for (int cntmin = 0; cntmin <= n; cntmin++) {
        ll leftsum = sum-cntmin*a[0];
        ll x = (ll)(n-cntmin)*a[n-1]-leftsum;
        ll y = n-cntmin-x;
        if (x >= 0 && y >= 0) {
            int cnt = min(l, cntmin)+min((ll)m, x)+min((ll)r, y);
            if (cnt < same) {
                same = cnt;
                mincnt = cntmin;
            }
        }
    }
    printf("%d\n", same);
    for (int i = 0; i < mincnt; i++) printf("%d ", a[0]);
    m = (n-mincnt)*a[n-1]-(sum-mincnt*a[0]);
    for (int i = 0; i < m; i++) printf("%d ", a[0]+1);
    for (int i = 0; i < n-m-mincnt; i++) printf("%d ", a[0]+2);
    return 0;
}

// 6
// -1 1 1 0 0 -1