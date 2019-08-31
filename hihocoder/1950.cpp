#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define ll long long
const int maxn = 100005;
int n;
int su[maxn];
vector<int> g[maxn];
vector<int> res;


void dfs(int u, int v) {
    su[u] = 1;
    int maxa = 0;
    for (int i = 0; i < (int)g[u].size(); i++) {
        int e = g[u][i];
        if (e == v) continue;
        dfs(e, u);
        su[u] += su[e];
        maxa = max(maxa, su[e]);
    }
    maxa = max(maxa, n-su[u]);
    if (maxa < n-maxa)
        res.push_back(u);
}

int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x) {
            g[x].push_back(i);
            g[i].push_back(x);
        }
    }
    dfs(1, 0);
    sort(res.begin(), res.end());
    printf("%d\n", (int)res.size());
    for (int i = 0; i < (int)res.size(); i++)
        printf("%d\n", res[i]);
    return 0;
}