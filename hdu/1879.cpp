#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct node {
    int from;
    int to;
    int w;
    int f;
}edge[maxn*maxn];
int pre[maxn];
int findxy(int x) {
    return x == pre[x] ? x : findxy(pre[x]);
}
void unin(int x, int y) {
    int nx = findxy(x);
    int ny = findxy(y);
    if (nx == ny) return ;
    if (nx > ny) pre[nx] = ny;
    else pre[ny] = nx;
}
bool cmp(node a, node b) {
    return a.w < b.w;
}
int main(int argc, char const *argv[])
{
    int n;
    while (~scanf("%d", &n) && n) {
        int m = n*(n-1)/2;
        for (int i = 0; i <= n; i++) pre[i] = i;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &edge[i].from, &edge[i].to, &edge[i].w, &edge[i].f);
            if (edge[i].f) unin(edge[i].from, edge[i].to);
        }
        sort(edge, edge+m, cmp);
        int sum = 0;
        for (int i = 0; i < m; i++)
            if (findxy(edge[i].from) != findxy(edge[i].to)) {
                unin(edge[i].from, edge[i].to);
                sum += edge[i].w;
            }
        printf("%d\n", sum);
    }
    return 0;
}