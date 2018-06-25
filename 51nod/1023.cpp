#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 50005;
int a[maxn];
int t, n;
ll ans = 0;
void combine(int k) {
    int tem = a[k]+a[k-1];
    ans += tem;
    for (int i = k; i < t-1; i++)
        a[i] = a[i+1];
    t--;
    int j = 0;
    for (j = k-1; j > 0 && a[j-1] < tem; j--)
        a[j] = a[j-1];
    a[j] = tem;
    while (j >= 2 && a[j] >= a[j-2]) {
        int d = t-j;
        combine(j-1);
        j = t-d;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    t = 1;
    for (int i = 1; i < n; i++) {
        a[t++] = a[i];
        while (t >= 3 && a[t-3] <= a[t-1]) combine(t-2);
    }
    while (t > 1) combine(t-1);
    printf("%lld\n", ans);
    return 0;
}