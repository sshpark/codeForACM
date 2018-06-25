#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[1005];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++)
        a[i] = (a[i-1]+a[i-2])%1000000007;
    printf("%d\n", a[n]);
    return 0;
}