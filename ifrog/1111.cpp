#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 500005;
int a[maxn], b[maxn];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    for (int i = 0; i < n; i++)
        scanf("%d", b+i);
    sort(a, a+n);
    sort(b, b+n);
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += 1LL*a[i]*b[i];
    printf("%llu\n", sum);
    return 0;
}