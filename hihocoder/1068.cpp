#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int f[10000005][21];
int main(int argc, char const *argv[])
{
    int n, m, l, r, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &f[i][0]);
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            if (i+(1<<j)-1 <= n) f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &l, &r);
        k = log(r-l+1)/log(2);
        printf("%d\n", min(f[l][k], f[r-(1<<k)+1][k]));
    }
    return 0;
}