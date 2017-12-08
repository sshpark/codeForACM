#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
struct node {
    int u, v;
    string name;
}edge[1005];
bool vis[1005];
int n, path[1005], cnt, pre[123], in[123], out[123];
inline bool cmp(struct node a, struct node b) {
    return a.name.compare(b.name) < 0;
}
void dfs(int u) {
    for (int i = 0; i < n; i++) {
        if (!vis[i] && edge[i].u == u) {
            vis[i] = true;
            dfs(edge[i].v);
            path[++cnt] = i;
        }
    }
}
int findxy(int x) {
    return x == pre[x] ? x : findxy(pre[x]);
}
void unit(int x, int y) {
    int nx = findxy(x), ny = findxy(y);
    if (nx == ny) return ;
    if (nx > ny) pre[nx] = ny;
    else pre[ny] = nx;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(vis, false, sizeof vis);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        set<int> s;
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i <= 122; i++) pre[i] = i;
        for (int i = 0; i < n; i++) {
            cin >> edge[i].name;
            edge[i].u = edge[i].name[0];
            edge[i].v = edge[i].name[edge[i].name.size()-1];
            out[edge[i].u]++;
            in[edge[i].v]++;
            unit(edge[i].u, edge[i].v);
            s.insert(edge[i].u), s.insert(edge[i].v);
        }
        int cut = 0, flag = 0, st = 0, even = 0;
        for (auto i : s) {
            if (abs(in[i]-out[i]) > 1) flag++;
            if (in[i] != out[i]) even = 1;
            if (out[i]-in[i] == 1) st = i;
            if (pre[i] == i) cut++;
        }
        if (cut > 1 || flag) {
            puts("***");
            continue;
        }
        sort(edge, edge+n, cmp);
        if (!even) st = *s.begin();
        dfs(st);
        for (int i = cnt; i > 1; i--)
            cout << edge[path[i]].name << ".";
        cout << edge[path[1]].name << endl;
    }
    return 0;
}