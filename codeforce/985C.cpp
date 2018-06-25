#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
ll a[maxn];
int main(int argc, char const *argv[])
{
    int n, k, l, temp;
    scanf("%d %d %d", &n, &k, &l);
    temp = n*k;
    for (int i = 1; i <= temp; i++) scanf("%lld", a+i);
    sort(a+1, a+temp+1);
    
    if (a[n]-a[1] > l) {
        puts("0");
    } else {
        ll ans = 0;
        int tmp = 0;
        for (int i = temp; i >= 1; i--) {
            tmp++;
            if (a[i]-a[1] <= l && tmp >= k) {
                ans += a[i];
                tmp -= k;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}