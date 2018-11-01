#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll T, n, a, b, c;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b >> c;
        ll m = n%c; 
        ll temp = n/c; 
        ll _m = temp/a;
        ll _temp = temp%a;
        cout << temp+_m*b<< endl;

    }
    return 0;
}