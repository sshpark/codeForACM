#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
#define ll long long
const int maxn = 10005;
vector<int> p[maxn];
int vis[maxn], col[maxn];
int ans = 0;
void dfs(int u) {
    for (auto i : p[u]) {
        if (!vis[i]) {
            vis[i] = 1;
            if (col[u] == col[i]) ++ans;
                dfs(i);
        }
    }
}
int main(int argc, char const *argv[])
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        p[min(x, i+2)].push_back(max(x, i+2));
    }
    for (int i = 1; i <= n; i++) cin >> col[i];
    dfs(1);
    printf("%d\n", n-ans);
    return 0;
}