#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int mod = 142857;
const int maxn = 100005;
vector<int> mm[maxn];
int e[maxn], in[maxn], st[maxn];
int main(int argc, char const *argv[])
{
    memset(e, 0, sizeof e);
    memset(in, 0, sizeof in);
    int n, m, k, x, u, v, top = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &x);
        e[x]++;
    }
    while (m--) {
        scanf("%d %d", &u, &v);
        in[v]++;
        mm[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (in[i] == 0) st[++top] = i;
    while (top) {
        int u = st[top];
        top--;
        for (auto i = mm[u].begin(); i != mm[u].end(); i++) {
            in[*i]--;
            e[*i] += e[u];
            e[*i] %= mod;
            if (in[*i] == 0) st[++top] = *i;
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum = (sum+e[i])%mod;
    printf("%d\n", sum);
    return 0;
}