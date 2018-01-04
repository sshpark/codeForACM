#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
int main(int argc, char const *argv[])
{
    int a[105], cnt = 2, lop = 0;
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= 101; i++) {
        a[i] = a[i-1]+cnt;
        lop++;
        if (lop == 2) {
            lop = 0;
            cnt++;
        }
    }
    printf("%d\n", a[47]);
    for (int n = 1; n <= 100; n++) {
        int cnt = 0;
        int b[105][105];
        memset(b, 0, sizeof b);
        for (int i = 0; i <= n; ++i)
        {
            for (int j = i+1; j <= n; ++j)
            {
                if (i == 0 && j == n) cnt++;
                else if (b[i][j] == 0) {
                    b[i][j] = 1;
                    b[j][n-i] = 1;
                    cnt++;
                }
            }
        }
        if (cnt != a[n])
            printf("%d\n", n);
    }
 
    return 0;
}