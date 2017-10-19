#include <iostream>
#define ll long long
using namespace std;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0){x = 1; y = 0; return a;}
    ll d, t;
    d = exgcd(b, a%b, x, y);
    t = x;
    x = y;
    y = t-a/b*y;
    return d;
}
int main(int argc, char const *argv[])
{
    int a, b, c, k;
    while (~scanf("%d %d %d %d", &a, &b, &c, &k) && a+b+c+k) {
        ll x, y;
        ll nk = 1LL<<k;
        ll d = exgcd(c, nk, x, y);
        if ((b-a)%d != 0) {
            puts("FOREVER");
            continue;
        }
        x = x*(b-a)/d;
        x %= nk;
        printf("%lld\n", (x%(nk/d)+(nk/d))%(nk/d));
    }
    return 0;
}