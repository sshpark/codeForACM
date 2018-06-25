#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    int c = min(a, b);
    ll ans = 1;
    for (int i = 1; i <= c; i++) ans *= i;
    printf("%lld\n", ans);

    return 0;
}