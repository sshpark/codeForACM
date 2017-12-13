#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
ll a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    ll sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", a+i);
    
    printf("%lld\n", sum);
    return 0;
}
