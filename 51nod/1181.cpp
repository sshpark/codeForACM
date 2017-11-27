#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
bool isp[1000005];
int cnt, p[1000005];
void shai(int n) {
    memset(isp, true, sizeof isp);
    for (ll i = 2; i < n; i++)
        if (isp[i]) {
            p[cnt++] = i;
            for (ll j = i*i; j < n; j+=i)
                isp[j] = false;
        }
}
int shai1(int n) {
    for (int i = 1; i < cnt; i++) {
        if (p[p[i]] >= n)
            return p[p[i]];
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int n;
    cnt = 1;
    shai(1000004);
    scanf("%d", &n);
    printf("%d\n", shai1(n));
    return 0;
}