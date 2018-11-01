#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 200005;
struct node {
    int x, id;
}a[maxn];
int ans[maxn], g[maxn];
inline bool cmp(node a, node b) {
    return a.x < b.x;
}
int main(int argc, char const *argv[])
{
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].x);
        a[i].id = i;
    }
    sort(a, a+n, cmp);

    int cnt = 0, days = 0;
    for (int i = 0; i < n; i++) {
        if (i <= cnt || a[i].x - a[cnt].x <= d) {
            g[i] = days++;
        } else {
            g[i] = g[cnt];
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) ans[a[i].id] = g[i];

    printf("%d\n", days);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", ans[i]+1);
    }
    printf("\n");


    return 0;
}