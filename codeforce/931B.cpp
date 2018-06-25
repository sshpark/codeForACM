#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int n, a, b, rounds = 1, j;
    int vis[300];
    memset(vis, 0, sizeof vis);
    cin >> n >> a >> b;
    if (a > b) swap(a, b);
    while (true) {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                j = i+1;
                while (vis[j]) ++j;
                if (i == a && j == b) {
                    int flag = 0;
                    for (int k = 1; k <= n; k++)
                        if (!vis[k]) flag++;
                    if (flag == 2) puts("Final!");
                    else printf("%d\n", rounds);
                    return 0;
                }
                if (i == a || i == b) vis[j] = 1;
                else vis[i] = 1;
                i = j;
            }
        }
        rounds++;
    }
    return 0;
}