#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int e[1005][1005], psum[1005][1005];
int main(int argc, char const *argv[])
{
    int n, m, x, y, T;
    scanf("%d", &T);
    while (T--) {
        memset(psum, 0, sizeof psum);
        scanf("%d %d %d %d", &n, &m, &x, &y);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &e[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                psum[i][j] = e[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        int maxa = -0x7ffff;
        for (int i = 1; i <= n && i+x-1 <= n; i++)
            for (int j = 1; j <= m && j+y-1 <= m; j++)
                maxa = max(maxa, psum[i+x-1][j+y-1] - psum[i+x-1][j-1] - psum[i-1][j+y-1] + psum[i-1][j-1]);
        printf("%d\n", maxa);
    }
    return 0;
}