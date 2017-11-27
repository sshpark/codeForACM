#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
bool isp[20005];
int p[20005], cnt = 0;
struct node {
    int x;
    int mp;
}a[5005];

void shai() {
    memset(isp, true, sizeof isp);
    for (int i = 2; i < 20005; i++)
        if (isp[i]) {
            p[cnt++] = i;
            for (int j = i*i; j < 20005; j+=i)
                isp[j] = false;
        }
}

inline int getMaxPrime(int n) {
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        if (p[cnt] > n) break;
        while (n%p[i] == 0) {
            ans = max(ans, p[i]);
            n /= p[i];
        }
    }
    if (n > 1) ans = max(ans, n);
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    shai();
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i].x);
            a[i].mp = getMaxPrime(a[i].x);
        }
        int res = 1, ans = 1;
        for (int i = 0; i < n; i++)
            if (a[i].mp > res) {
                ans = a[i].x;
                res = a[i].mp;
            }
        printf("%d\n", ans);
    }
    return 0;
}