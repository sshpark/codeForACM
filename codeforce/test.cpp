#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
vector<int> p[maxn];
int vis[maxn], nodes;
void dfs(int u) {
    vis[u] = 1;
    nodes++;
    for (auto i : p[u]) {
        if (!vis[i]) {
            dfs(i);
        }
    }

}
int main(int argc, char const *argv[])
{
    printf("%lf\n", pow(9, 9));
    int n, m, u, v;
    memset(vis, 0, sizeof vis);
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            nodes = 0;
            dfs(i);
            ans.push_back(nodes);
        }
    }
    ll ans1 = (ll)n*(n-1)/2, ans2 = 0;
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        ans2 += (*it)*((*it)-1)/2;
    }
    printf("%lld\n", ans1-ans2);

    // 另一种计算方法
    // int len = (int)ans.size();
    // ll ans1 = 0, ans2 = 0;
    // for (auto i : ans) {
    //     ans1 += r*i;
    //     ans2 += i;
    // }
    // printf("%lld\n", ans1);
    return 0;
}