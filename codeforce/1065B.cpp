#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n, m;
    cin >> n >> m;
    ll mina, maxa;
    if (m*2 >= n) mina = 0;
    else mina = n-m*2;

    ll mid, l = 0, r = n, sum;
    while (l <= r) {
        mid = (l+r)>>1;
        // printf("%lld\n", mid);
        sum = mid*(mid-1)/2;
        if (sum > m) r = mid-1;
        else if (sum == m) {
            break;
        } else l = mid+1;
    }

    
    cout << mina << " " << n-l << endl;

    return 0;
}