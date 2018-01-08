#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    ll a, b, x, y, z, na = 0, nb = 0, sum = 0;
    cin >> a >> b;
    cin >> x >> y >> z;
    na = x*2+y;
    nb = y+3*z;
    if (na-a >= 0) sum += na-a;
    if (nb-b >= 0) sum += nb-b;
    printf("%lld\n", sum);

    return 0;
}