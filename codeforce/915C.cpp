#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define ll long long
char a[20], b[20];
inline bool cmp(char a, char b) {
    return a > b;
}
inline ll getval(int n, char *a) {
    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += pow(10, n-i-1)*(a[i]-'0');
    return sum;
}
int main(int argc, char const *argv[])
{
    char c[20], temp_c[20];
    scanf("%s", a);
    scanf("%s", b);
    int lena = strlen(a), lenb = strlen(b);
    if (strcmp(a, b) == 0)
        return 0*printf("%s\n", a);
    ll nb = getval(lenb, b);
    if (lenb > lena) {
        sort(a, a+lena, cmp);
        printf("%lld\n", getval(lena, a));
    } else {
        int vis[20], cnt = 0;
        sort(a, a+lena, cmp);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < lena; i++) {
            for (int j = 0; j < lena; j++) {
                if (!vis[j]) {
                    if (a[j] == b[i]) {
                        vis[j] = 1;
                        c[cnt++] = a[j];
                        int temp_cnt = 0;
                        for (int i = 0; i < cnt; i++) temp_c[temp_cnt++] = c[i];
                        for (int k = lena-1; k >= 0; k--)
                            if (!vis[k]) temp_c[temp_cnt++] = a[k];
                        if (getval(lena, temp_c) > nb) {
                            cnt--;
                            vis[j] = 0;
                        } else {
                            break;
                        }
                    }
                    if (a[j] < b[i]) {
                        vis[j] = 1;
                        c[cnt++] = a[j];
                        for (int k = 0; k < lena; k++)
                            if (!vis[k]) c[cnt++] = a[k];
                        return 0*printf("%lld\n", getval(lena, c));
                    }
                }
            }

        }
    }
    return 0;
}

// 2723 2711