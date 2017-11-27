#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
bool isp[10005];
void shai(int n) {
    memset(isp, true, sizeof isp);
    for (int i = 2; i < n; i++)
        for (int j = i*i; j < n; j+=i)
            if (isp[j])
                isp[j] = false;
}
int main(int argc, char const *argv[])
{
    int n, maxa = -1;
    scanf("%d", &n);
    shai(n);
    for (int i = 1; i < n; i++)
        if (isp[i] && isp[n-i])
            maxa = max(maxa, i*(n-i));
    printf("%d\n", maxa);
    return 0;
}