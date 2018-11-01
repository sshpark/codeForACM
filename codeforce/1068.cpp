#include <iostream>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
ll n, m, k, l;

inline bool ok()  {
    if (m > n) return false;
    if (k+l > n) return false;
    return true;
}
int main(int argc, char const *argv[])
{
 //   cout << (77777777777777777+8888888888888888)/3 << endl;
    cin >> n >> m >> k >> l;
    if (ok()) {
        ll ans = (k+l)/m;
        if ((k+l)%m != 0) ans++;
        if (ans*m <= n)
            cout << ans << endl;
        else
            cout << -1 << endl;
    } else {
        cout << "-1" << endl;
    }


    return 0;
}
