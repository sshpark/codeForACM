#include <iostream>
#include <stdio.h>
using namespace std;
char a[200005];
int main(int argc, char const *argv[])
{
    int n, t, dot = n+1;
    scanf("%d %d", &n, &t);
    scanf("%s", a+1);
    for (int i = 1; i <= n; i++)
        if (a[i] == '.') dot = i;
    int p = -1;
    for (int i = dot+1; i <= n; i++)
        if (a[i] >= '5' && a[i] <= '9') {
            p = i;
            break;
        }
    while (p > dot && t >= 1 && a[p] >= '5' && a[p] <= '9') {
        a[p] = 0;
        if (p-1 != dot) a[p-1]++;
        else a[p-2]++;
        t--, p--;
    }
    if (p == dot) a[p] = 0, p--;
    while (a[p] == '9'+1) {
        if (p == 1) putchar('1');
        a[p] = '0', a[p-1]++;
        p--;
    }
    printf("%s\n", a+1);
    return 0;
}