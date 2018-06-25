#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int a[maxn];
int main(int argc, char const *argv[])
{
    int n, k;
    bool first = true;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = k; i < n; i++)
        if (first) {
            printf("%d", a[i]);
            first = false;
        } else printf(" %d", a[i]);
    for (int i = 0; i < k; i++)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}