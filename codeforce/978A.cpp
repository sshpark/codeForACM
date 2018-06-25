#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int vis[1005], a[1005];
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    memset(vis, 0, sizeof vis);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (vis[a[i]] > 1) {
            vis[a[i]]--;
            a[i] = 0;
            sum++;
        }
    }
    printf("%d\n", n-sum);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0)
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}