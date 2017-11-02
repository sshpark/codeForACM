#include <iostream>
#include <string.h>
using namespace std;
int vis[30][50], e[30][50];
int n, ans = 0;

void dfs(int step, int x, int y) {
    if (step == n) {
        ans++;
        return;
    }
    vis[x][y] = 1;
    if (!vis[x+1][y])
        dfs(step+1, x+1, y);
    if (!vis[x][y+1])
        dfs(step+1, x, y+1);
    if (!vis[x][y-1])
        dfs(step+1, x, y-1);
    vis[x][y] = 0;
}
int main(int argc, char const *argv[])
{
    
    scanf("%d", &n);
    memset(e, 0, sizeof e);
    memset(vis, 0, sizeof vis);
    dfs(0, 1, 20);
    printf("%d\n", ans);
    return 0;
}