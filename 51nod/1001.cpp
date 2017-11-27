#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define ll long long
using namespace std;
int a[50005];
int main(int argc, char const *argv[])
{
    int k, n, flag = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n);
    for (int i = 0; a[i] < k/2; i++) {
        int nxt = lower_bound(a+i, a+n, k-a[i]) - a;
        if (k-a[i] == a[nxt] && a[i] != a[nxt] && a[nxt] + a[i] == k) {
            flag = 1;
            printf("%d %d\n", a[i], a[nxt]);
        }
    }
    if (!flag) puts("No Solution");
    return 0;
}