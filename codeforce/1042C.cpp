#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
int a[maxn], vis[maxn];
int main(int argc, char const *argv[])
{
    int n, cnt = 1;
    scanf("%d", &n);
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) scanf("%d", a+i);

    int zero = 0, fu = 0, pos = -1;
    
    for (int i = 1; i <= n; i++) {
        if (a[i] < 0) {
            fu++;
            if (pos == -1 || a[pos] > a[i]) pos = i;
        }
        if (a[i] == 0) {
            vis[i] = 1;
            zero++;
        }
    }
    if (fu & 1) {
        printf("2 %d\n", pos);
        cnt++;
        int st = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                st = i;
                break;
            }
        }
        for (int i = st+1; i <= n; i++) {
            if (vis[i]) {
                if (cnt <= n-1) {
                    printf("1 %d %d\n", st, i);
                    st = i;
                    cnt++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                st = i;
                break;
            }
        }
        for (int i = st+1; i <= n; i++) {
            if (!vis[i]) {
                if (cnt <= n-1) {
                    printf("1 %d %d\n", st, i);
                    st = i;
                    cnt++;
                }
            }
        }

    } else {
        int st = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == 0) {
                st = i;
                break;
            }
        if (zero == 1) {
            printf("2 %d\n", st);
            cnt++;
        } else {
            for (int i = st+1; i <= n; i++) {
                if (a[i] == 0) {
                    if (cnt <= n-1) {
                        printf("1 %d %d\n", st, i);
                        cnt++;
                        st = i;
                    }
                }
            }
            if (cnt <= n-1) {
                printf("2 %d\n", st);
                cnt++;
            }
        }
        for (int i = 1; i <= n; i++)
            if (a[i]) {
                st = i;
                break;
            }
        for (int i = st+1; i <= n; i++)
            if (a[i]) {
                if (cnt <= n-1) {
                    printf("1 %d %d\n", st, i);
                    st = i;
                    cnt++;
                }
            }
    }
    return 0;
}