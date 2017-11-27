#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int n, m;
char e[1005][1005];
int dis[1005][1005], vis[1005][1005];
int nxt[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
struct node {
    int x, y;
    int step;
    node() {
        step = 0;
    }
};
void bfs(int sx, int sy, int ex, int ey, int k) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[i][j] = 100000000;
    queue<node> q;
    node x, temp;
    int step = 0;
    x.x = sx-1, x.y = sy-1;
    x.step = 0;
    q.push(x);
    dis[sx-1][sy-1] = 0;
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= k; j++) {
                int nx = x.x + j*nxt[i][0];
                int ny = x.y + j*nxt[i][1];
                step = x.step + 1;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || e[nx][ny] == '#' || (vis[nx][ny] && x.step >= dis[nx][ny]))
                    break;
                if (!vis[nx][ny] && step < dis[nx][ny]) {
                    vis[nx][ny] = true;
                    dis[nx][ny] = step;
                    temp.x = nx, temp.y = ny;
                    temp.step = step;
                    q.push(temp);
                }
            }
        }
    }
    printf("%d\n", dis[ex-1][ey-1] == 100000000 ? -1 : dis[ex-1][ey-1]);
}
int main(int argc, char const *argv[])
{
    int sx, sy, ex, ey, k;
    memset(e, 0, sizeof e);
    memset(vis, 0, sizeof vis);
    memset(dis, -1, sizeof dis);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", e[i]);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    bfs(sx, sy, ex, ey, k);
    return 0;
}