#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int e[35][35];
struct node {
    int x, y;
    int step;
    node() {
        step = 0;
    }
};
char a[5], b[5];
int nxt[8][2] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
void bfs(int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) {
        printf("To get from %s to %s takes 0 knight moves.\n", a, b);
        return;
    }
    memset(e, 0, sizeof e);
    queue<node> q;
    node x, temp;
    x.x = sx, x.y = sy;
    e[sx][sy] = 1;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x.x + nxt[i][0], ny = x.y + nxt[i][1];
            if (nx > 0 && ny > 0 && nx <= 8 && ny <= 8) {
                if (nx == ex && ny == ey) {
                    printf("To get from %s to %s takes %d knight moves.\n", a, b, x.step+1);
                    return;
                }
                e[nx][ny] = 1;
                temp.x = nx, temp.y = ny;
                temp.step = x.step + 1;
                q.push(temp);
            }
        }
    }
    printf("To get from %s to %s takes 0 knight moves.\n", a, b);
}
int main(int argc, char const *argv[])
{
    while (~scanf("%s %s", a, b)) {
        bfs(a[1]-'0', a[0]-'a'+1, b[1]-'0', b[0]-'a'+1);
    }
    return 0;
}