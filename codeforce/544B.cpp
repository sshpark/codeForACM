#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int e[105][105];
inline bool ok(int x, int y) {
    if (e[x-1][y] == 1 || e[x+1][y] == 1 || e[x][y-1] == 1 || e[x][y+1] == 1) 
        return false;
    return true;
}
int main(int argc, char const *argv[])
{
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    memset(e, 0, sizeof e);
    for (int i = 1; i <= n; i++) {
        if (cnt == k) break;
        for (int j = 1; j <= n; j++) {
            if (cnt == k) break;
            if (ok(i, j)) {
                e[i][j] = 1;
                cnt++;
            }
        }
    }
    if (cnt < k) puts("NO");
    else {
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%c", e[i][j] ? 'L' : 'S');
            printf("\n");
        }
    }
    return 0;
}