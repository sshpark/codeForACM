#include <iostream>
#include <cstdio>
#include <string.h>
#define ll long long
using namespace std;
#define mod 10001 
void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b){d = a; x = 1; y = 0; return;}
    else {exgcd(b, a%b, d, y, x); y -= x*(a/b);return;}
}
int main(int argc, char const *argv[])
{
    int T;
    ll x[205], a, b;
    scanf("%d", &T);
    for (int i = 1; i < 2*T; i += 2) scanf("%lld", x+i);
    for (a = 0; ; a++) {
        ll k, b, d;
        ll t = x[3]-a*a*x[1];
        exgcd(mod, a+1, d, k, b);
        if (t % d) continue;
        b = b*t/d;
        int ok = 1;
        for (int i = 2; i <= 2*T; i++)
            if (i & 1) {
                if (x[i] != (a*x[i-1]+b)%mod) {
                    ok = 0;
                    break;
                }
            }
            else {
                x[i] = (a*x[i-1]+b)%mod;
            }
        if (ok) break;
    }
    for (int i = 2; i <= 2*T; i+=2) printf("%lld\n", x[i]);
    return 0;
}