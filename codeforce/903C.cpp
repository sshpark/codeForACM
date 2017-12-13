#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, vis[5005], sum = 0, temp, flag;
    ll a[5005];
    memset(vis, 0, sizeof vis);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = n-1; i >= 0; i--) {
        if (vis[i]) continue;
        flag = 0;
        temp = a[i];
        for (int j = i-1; j >= 0; j--) {
            if (!vis[j] && a[j] < temp) {
                temp = a[j];
                vis[j] = 1;
                flag = 1;
            }
        }
        if (flag) {
            sum++;
            vis[i] = 1;
        }
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]) sum++;
    printf("%d\n", sum);
    return 0;
}