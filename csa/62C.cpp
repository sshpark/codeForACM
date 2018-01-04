#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int maxn = 1005;
vector<int> p[maxn];
int ans;
bool vis[maxn];
void dfs(int s, int t) {
    if (ans > 1) return;
    vis[s] = true;
    for (auto i : p[s]) {
        if (i == t) {
            ans++;
        } else if (!vis[i])
            dfs(i, t);
    }
    vis[s] = false;
}
int main(int argc, char const *argv[])
{
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    int n, m, q, u, v;
    cin >> n >> m >> q;
    while (m--) {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    while (q--) {
        cin >> u >> v;
        memset(vis, false, sizeof vis);
        ans = 0;
        dfs(u, v);
        puts(ans > 1 ? "0" : "1");
    }
    return 0;
}