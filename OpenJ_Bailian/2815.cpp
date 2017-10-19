#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int map[55][55];
int color[55][55];
int maxa = -1, cur;
void dfs(int x, int y) {
    if (color[x][y]) return;
    cur++;
    color[x][y]++;
    if ((map[x][y] & 1) == 0) dfs(x, y-1);
    if ((map[x][y] & 2) == 0) dfs(x-1, y);
    if ((map[x][y] & 4) == 0) dfs(x, y+1);
    if ((map[x][y] & 8) == 0) dfs(x+1, y);
}
int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
    memset(color, 0, sizeof color);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!color[i][j]) {
                ans++, cur = 0;
                dfs(i, j);
                maxa = max(maxa, cur);
            }
    printf("%d\n%d\n", ans, maxa);
    return 0;
}