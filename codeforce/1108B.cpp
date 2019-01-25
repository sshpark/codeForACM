#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int main(int argc, char const *argv[])
{
    int n, x = 1;
    map<int, int> mm;
    int a[205], maxa = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        mm[a[i]]++;
        if (mm[a[i]] == 2) x = max(x, a[i]);
        maxa = max(maxa, a[i]);
    }
    int lcm = a[0];
    for (int i = 1; i < n; i++) {
        lcm = lcm/gcd(lcm, a[i])*a[i];
    }

    printf("%d %d\n", lcm*x/maxa, maxa);
    
    return 0;
}