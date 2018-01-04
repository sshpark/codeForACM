#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int l[maxn], r[maxn], a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    l[0] = r[n+1] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        a[i] = 1;
    }
    for (int i = 1; i <= n; i++) cin >> r[i];
    for (int i = 1; i <= n; i++)
        if (l[i]) {
            if (l[i] > l[i-1])
                a[i-1] = 0;
        }
    for (int i = n; i >= 1; i--)
        if (r[i]) {
            if (r[i] > r[i+1])
                a[i+1] = 0;
        }
    for (int i = 1; i <= n; i++)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}