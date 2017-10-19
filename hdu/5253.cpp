#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1005;
int e[maxn][maxn];
struct node {
    int from, to, w;
}edge[5000005];
int pre[5000005];
bool cmp(node a, node b) {
    return a.w < b.w;
}
int findxy(int x) {
    return x == pre[x] ? x : pre[x] = findxy(pre[x]);
}
inline void unin(int x, int y) {
    int nx = findxy(x), ny = findxy(y);
    if (nx == ny) return;
    if (nx > ny) pre[nx] = ny;
    else pre[ny] = nx;
}
int main(int argc, char const *argv[])
{
    int n, m, T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &e[i][j]);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < m; j++)
                edge[cnt].from = (i-1)*m+j, edge[cnt].to = (i-1)*m+j+1, edge[cnt++].w = abs(e[i][j]-e[i][j+1]);
        for (int i = 1; i <= m; i++)
            for (int j = 1; j < n; j++)
                edge[cnt].from = (j-1)*m+i, edge[cnt].to = j*m+i, edge[cnt++].w = abs(e[j][i]-e[j+1][i]);
        for (int i = 0; i <= n*m; i++) pre[i] = i;
        sort(edge, edge+cnt, cmp);
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            int fx = findxy(edge[i].from), fy = findxy(edge[i].to);
            if (fx != fy) {
                if (fx > fy) pre[fx] = fy;
                else pre[fy] = fx;
                sum += edge[i].w;
            }
        }
        printf("Case #%d:\n%d\n", t, sum);
    }
    return 0;
}