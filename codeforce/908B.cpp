#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 55;
char e[maxn][maxn];
int vis[maxn][maxn];
//u, d, l, r
int nxt[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //顺时针：右下左上
int dir[4];
int coun[4], check[4];
int n, m, ans = 0, f = 0;
void dfs(int x, int y) {
    if (f) return;
    if (e[x][y] == 'E') {
            int flag = 1;
            for (int i = 0; i < 4; i++)
                printf("%d%d\n", );
            for (int i = 0; i < 4; i++)
                if (coun[i] != check[i]) {
                    flag = 0;
                    break;
                }
            if (flag) {
                f = 1;
                ans++;
            }
            return ;
        }
    for (int i = 0; i < 4; i++) {
        int nx = x + nxt[dir[i]][0];
        int ny = y + nxt[dir[i]][1];
        if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        if (vis[nx][ny] == 0 && e[nx][ny] != '#') {
            ++coun[dir[i]];
            vis[nx][ny] = 1;
            dfs(nx, ny);
            vis[nx][ny] = 0;
            --coun[dir[i]];
        }
    }
}
int main(int argc, char const *argv[])
{
    
    char move[105];
    int sx, sy;
    cin >> n >> m;
    memset(check, 0, sizeof check);
    for (int i = 0; i < n; i++) scanf("%s", e[i]);
    scanf("%s", move);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (e[i][j] == 'S') {
                sx = i, sy = j;
                break;
            }
    
    int len = strlen(move);
    for (int i = 0; i < len; i++) check[move[i]-'0']++;
    for (int i = 0; i < 4; i++) dir[i] = i;

    do {
        f = 0;
        memset(vis, 0, sizeof vis);
        memset(coun, 0, sizeof coun);
        dfs(sx, sy);
    }while (next_permutation(dir, dir+4));
    printf("%d\n", ans);

    return 0;
}