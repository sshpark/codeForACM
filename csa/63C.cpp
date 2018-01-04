#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
ll a[maxn], b[maxn], c[maxn];
ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int flag = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) {
            flag = 1;
            break;
        }
    if (!flag) return 0*printf("1\n");
    for (int i = 0; i < n; i++) {
        c[i] = a[i]-b[i];
        if (c[i] == 0) 
            return 0*printf("-1\n");
    }

    ll ans = c[0];
    for (int i = 1; i < n; i++)
        ans = gcd(ans, c[i]);
    if (ans == 0 || ans == 1 || ans < 0) printf("-1\n");
    else printf("%lld\n", ans);
    return 0;
}