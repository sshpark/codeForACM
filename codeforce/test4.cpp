#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
vector<int> p[maxn], ans;
int maxa = 0, vis[maxn], cnt, col[maxn];
void dfs(int u) {
    col[u] = ++cnt;
    maxa = max(cnt, maxa);
    for (auto i : p[u]) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i); 
        }
    }
    --cnt;
}
int main(int argc, char const *argv[])
{
    int n, x, st;
    cin >> n;
    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == -1) st = i;
        else {
            p[x].push_back(i);
            p[i].push_back(x);
        }
    }
    cnt = 0; vis[st] = 1;
    dfs(st);
    printf("%d\n", maxa);
    bool first = true;
    for (int i = 1; i <= n; i++)
        if (col[i] == maxa) {
            if (first) {
                printf("%d", i);
                first = false;
            } else {
                printf(" %d", i);
            }
        }
    printf("\n");
    return 0;
}