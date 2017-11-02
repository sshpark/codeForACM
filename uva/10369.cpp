#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 505;
int pre[maxn];
struct node {
    int x, y;
}p[maxn];
struct edge {
    int u, v;
    double len;
}e[maxn*maxn];
int findxy(int x) {
    return x == pre[x] ? x : findxy(pre[x]);
}
inline bool unin(int x, int y) {
    int nx = findxy(x), ny = findxy(y);
    if (nx == ny) return false;
    if (nx > ny) pre[nx] = ny;
    else pre[ny] = nx;
    return true;
}
bool cmp(edge a, edge b) {
    return a.len < b.len;
}
bool cmp1(int a, int b) {
    return a > b;
}
int main(int argc, char const *argv[])
{
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &m, &n);
        memset(e, 0, sizeof(e));
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        int num = 0;
        for (int i = 0; i < n; i++)
            for (int j= i+1; j < n; j++) {
                e[num].u = i;
                e[num].v = j;
                e[num++].len = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            }
        sort(e, e+num, cmp);
        for (int i = 0; i <= n; i++)
            pre[i] = i;
        int temp[maxn*maxn], k = 0;
        for (int i = 0; i < num; i++)
            if (unin(e[i].u, e[i].v))
                temp[k++] = i;
        sort(temp, temp+k, cmp1);
        printf("%.2lf\n", e[temp[m-1]].len);
    }
    return 0;
}