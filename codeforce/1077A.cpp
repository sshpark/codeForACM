#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll T, a, b, k;
    ll ans;
    cin >> T;
    while (T--) {
        cin >> a >> b >> k;

        if (k&1) {
            cout << (a-b)*(k/2)+a << endl;
        } else {
            cout << (a-b)*(k/2) << endl;
        }

    }
    return 0;
}