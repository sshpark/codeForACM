#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a+i);
    if (a[0]&1 && a[n-1]&1 && n&1) puts("Yes");
    else puts("No");
    return 0;
}
