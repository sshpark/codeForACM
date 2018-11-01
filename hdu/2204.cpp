#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const ll inf = 1e18+5;
ll num[70];
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) {
            if (a > 1.0*inf/ans) return -1;
            ans *= a;
        }
        b >>= 1;
        if (a > 1.0*inf/a && b > 0) return -1; 
        a *= a;
    }
    return ans;
}
ll getk(ll n, ll k) {
    ll ans = pow(n, 1.0/k);
    ll temp = qpow(ans, k);
    if (temp == n) return ans;
    if (temp > n || temp == -1) ans--;
    else {
        temp = qpow(ans+1, k);
        if (temp != -1 && temp <= n) ans++;
    }
    return ans;
}
ll getsum(ll n) {    
    if (n <= 3) return n;
    num[1] = n;
    int k = 1;
    while (num[k] > 0) {
        k++;
        num[k] = getk(n, k)-1;
    }
    for (int i = k-1; i > 0; i--) {
        for (int j = i<<1; j < k; j++) {
            if (j%i == 0) num[i] -= num[j];
        }
    }
    ll ans = 0;
    for (int i = 1; i < k; i++) ans += i*num[i];
    return ans;

}
int main(int argc, char const *argv[])
{
    ll a, b;
    while (~scanf("%lld %lld", &a, &b) && a && b) {
        printf("%lld\n", getsum(b)-getsum(a-1));
    }
    return 0;
}