#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct node {
    int f;
    int w;
    int t;
}edge[maxn*maxn];
int pre[maxn];
int findxy(int x) {
    int r = x;
    while(r != pre[r])
        r = pre[r];
    return r;
}
bool cmp(node x, node y) {
    return x.w < y.w;
}
void unin(int x, int y) {
    int nx = findxy(x);
    int ny = findxy(y);
    if (nx != ny)
        pre[nx] = ny;
}
int main(int argc, char const *argv[])
{
    int n, x;
    while (~scanf("%d", &n)) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                scanf("%d", &x);
                if (i != j) edge[cnt].f = i, edge[cnt].w = x, edge[cnt++].t = j;
            }
        for (int i = 0; i <= n; i++)
            pre[i] = i;
        sort(edge, edge+cnt, cmp);
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            if (findxy(edge[i].f) != findxy(edge[i].t)) {
                unin(edge[i].f, edge[i].t);
                sum += edge[i].w;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}