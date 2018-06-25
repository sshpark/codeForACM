#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
char str[100005];
int vis[100005];
int main(int argc, char const *argv[])
{
    int n, m, flag = 0;
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    scanf("%s", str);
    int sum = 0;
    for (int i = 0; i < n-1; i++) {
        if (str[i] != str[i+1]) sum++;
        if (str[i] == 'a') flag = 1;
    }
    if (!flag) return 0*printf("0\n");
    if (sum <= m) {
        printf("%d\n", n);
    } else {
        sum = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'a') break;
            if (str[i] == 'b') vis[i] = 1;
        }
        for (int i = 0; i < n-1; i++) {
            if (!vis[i] && str[i] != str[i+1]) {
                sum++;
                if (sum > m) {
                    sum--;
                    if (i+2 < n && str[i+2] == str[i]) vis[i+1] = 1;
                    else vis[i] = 1;
                }
            }
        }
        sum = 0;
        // for (int i = 0; i < n; i++) printf("%d ", vis[i]);
        //     printf("\n");
        for (int i = 0; i < n; i++)
            if (!vis[i]) sum++;
        printf("%d\n", sum);
    }

    return 0;
}