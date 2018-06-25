#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int a[200005];
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    if (k == 0) {
        if (a[0] > 1) printf("%d\n", a[0]-1);
        else printf("-1\n");
        return 0;
    }
    if (a[k-1] != a[k]) printf("%d\n", a[k-1]);
    else printf("-1\n");
    return 0;
}