#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}
int main(int argc, char const *argv[])
{
    int n, m;
    int a[20];
    while (~scanf("%d %d", &n, &m)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", a+i);
        }
        int ans = 0;
        for (int i = 1; i < (1<<n); i++) {
            int temp = 1, cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i&(1<<j)) {
                    temp = temp*a[j]/gcd(temp, a[j]);
                    cnt++;
                }
            }
            if (cnt&1) ans += m/temp;
            else ans -= m/temp;
        }
        printf("%d\n", ans);
    }

    return 0;
}