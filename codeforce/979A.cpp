#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll n;
    cin >> n;
    if (n == 0) {
        return 0*printf("0\n");
    }
    if (n&1) {
        cout << ((n+1)>>1) << endl;

    } else {
        cout << n+1 << endl;
    }
    return 0;
}