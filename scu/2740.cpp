#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
int mx[50005][21], mi[50005][21];
int main(int argc, char const *argv[])
{
    int n, m, l, r;
    while (~scanf("%d %d", &n, &m)) {
        memset(mx, 0, sizeof mx);
        memset(mi, 0, sizeof mi);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &mx[i][0]);
            mi[i][0] = mx[i][0];
        }
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i <= n; i++)
                if (i+(1<<j)-1 <= n) {
                    mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
                    mi[i][j] = min(mi[i][j-1], mi[i+(1<<(j-1))][j-1]);
                }
        while (m--) {
            scanf("%d %d", &l, &r);
            int k = log(r-l+1)/log(2);
            printf("%d\n", max(mx[l][k], mx[r-(1<<k)+1][k])-min(mi[l][k], mi[r-(1<<k)+1][k]));
        }
    }
    return 0;
}