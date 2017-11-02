#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int maxn = 100005;
int in[maxn], st[maxn], re[maxn];
int n, m, top, cnt;
vector<int> mp[maxn];
int main(int argc, char const *argv[])
{
    int T, u, v;
    scanf("%d", &T);
    while (T--) {
        memset(in, 0, sizeof in);
        for (int i = 0; i < maxn; i++) mp[i].clear();
        cnt = top = 0;
        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            in[v]++;
            mp[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
            if (in[i] == 0) st[++top] = i;
        while(top) {
            u = st[top];
            top--;
            for (auto i = mp[u].begin(); i != mp[u].end(); i++) {
                in[*i]--;
                if (in[*i] == 0) st[++top] = *i;
            }
            re[++cnt] = u;
        }
        puts(cnt == n ? "Correct" : "Wrong");
    }
    return 0;
}