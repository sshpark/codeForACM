#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
struct node {
    int next;
    int to;
}edge[100005];
int head[1005], id, mark_count;
int mat[1005], mark[1005];
inline void init() {
    memset(head, -1, sizeof head);
    id = 0;
}
inline void add(int x, int y) {
    edge[id].to = y;
    edge[id].next = head[x];
    head[x] = id++;
}
bool augmenet(int u) {
    for (int k = head[u]; k != -1; k = edge[k].next) {
        int v = edge[k].to;
        if (mark[v] == mark_count) continue;
        mark[v] = mark_count;
        if (mat[v] == 0 || augmenet(mat[v])) {
            mat[v] = u;
            return true;
        }
    }
    return false;
}
int match(int n) {
    mark_count = 0;
    int count = 0;
    memset(mat, 0, sizeof mat);
    memset(mark, 0, sizeof mark);
    for (int u = 1; u <= n; u++) {
        ++mark_count;
        if (augmenet(u))
            ++count;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int n, m, k, x;

    while (~scanf("%d %d", &n, &m)) {
        init();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &x);
                add(i, x+n);
                add(x+n, i);
            }
        }
        printf("%d\n", match(n));
    }

    return 0;
}