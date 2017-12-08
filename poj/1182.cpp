#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int pre[50005*3], rk[50005*3];
int findx(int x) {
    if (pre[x] == -1) return x;
    return pre[x] = findx(pre[x]);
}

void unit(int x, int y) {
    x = findx(x), y = findx(y);
    if (x == y) return;
    // 路径压缩
    if (rk[x] < rk[y])
        pre[x] = y;
    else {
        pre[y] = x;
        if (rk[x] == rk[y])
            rk[x]++;
    }
}
bool same(int x, int y) {
    return findx(x) == findx(y);
}
int main(int argc, char const *argv[])
{
    int n, k, c, x, y;
    int ans = 0;
    memset(pre, -1, sizeof pre);
    memset(rk, 0, sizeof rk);
    scanf("%d %d", &n, &k);
    while (k--) {
        scanf("%d %d %d", &c, &x, &y);
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (c == 1) {
            // 出现不同类
            if (same(x, y+n) || same(x, y+2*n)) ans++;
            else {
                unit(x, y);
                unit(x+n, y+n);
                unit(x+2*n, y+2*n);
            }
        } else {
            if (same(x, y) || same(x, y+2*n)) ans++;
            else {
                unit(x, y+n);
                unit(x+n, y+2*n);
                unit(x+2*n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}