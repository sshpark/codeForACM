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
    ll n, sum = 0;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++) {
        scanf("%lld", a+i);
        sum += a[i];
    }
    sort(a, a+n);
    
    ll temp = 0, i = 0, temp_n = n, cnt = 0;
    temp = a[0];
    while (true) {
        cnt += temp;
        sum -= temp_n*temp;
        printf("%lld\n", sum);
        if (sum == 0) break;
        while (a[i]-cnt == 0) {
            i++;
            temp_n--;
        }
        temp = a[i]-cnt;
    }

    return 0;
}