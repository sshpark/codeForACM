#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll f[20];
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ll n;

    for (int i = 1; i <= 6; i++) f[i] = 1LL*i;
    f[7] = 9, f[8] = 12, f[9] = 16;
    f[10] = 20, f[11] = 27, f[12] = 36;
    f[13] = 48, f[14] = 64, f[15] = 81;

    cin >> n;
    if (n < 16) {
        cout << f[n] << endl;
    } else {
        if ((n-15)%5 == 0) {
            cout << (f[15]*qpow(1LL*4, (n-15)/5))%mod << endl;
        } else {
            cout << (f[n-((n-15)/5+1)*5]*qpow(1LL*4, (n-15)/5+1))%mod << endl;
        }   
    }
    
    

    return 0;
}