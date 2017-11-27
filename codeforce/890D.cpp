#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define ll long long
const int maxn = 100005;
char s[maxn], ans[maxn], top;
vector<int> mp[30];
bool f[30], g[30][30], vis[30];
int ind[30], outd[30];
void dfs(int u) {
    if (vis[u]) return;
    ans[top++] = u + 'a';
    vis[u] = 1;
    for (int i = 0, sz = mp[u].size(); i < sz; i++)
        dfs(mp[u][i]);
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        f[s[0] - 'a'] = 1;
        int l, r;
        // 建图
        for (int j = 1, sz = strlen(s); j < sz; j++) {
            l = s[j-1] - 'a';
            r = s[j] - 'a';
            if (!g[l][r]) {
                g[l][r] = 1;
                mp[l].push_back(r);
                ind[r]++, outd[l]++;
            }
            f[l] = f[r] = 1;
        }
    }
    for (int i = 0; i < 26; i++)
        if (ind[i] > 1 || outd[i] > 1) // 如果出度或者入度不是1，不成立
            return puts("NO"), 0;
    for (int i = 0; i < 26; i++)
        if (f[i] && !ind[i]) dfs(i);
    for (int i = 0; i < 26; i++)
        if (f[i] != vis[i])
            return puts("NO"), 0;
    puts(ans);
    return 0;
}