#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n;
    int f[55], vis[2005];
    memset(vis, 0, sizeof vis);
    vis[1] = vis[2] = f[1] = f[2] = 1;
    for (int i = 3; i <= 17; i++) {
        f[i] = f[i-1]+f[i-2];
        vis[f[i]] = 1;
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        printf("%c", vis[i] ? 'O' : 'o');
    printf("\n");
    return 0;
}