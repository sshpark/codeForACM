#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<bitset>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef __int64 LL;
const int low(int x) { return x&-x; }
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int maxn = 8e2 + 10;
LL ans, dp[maxn];
int x[maxn], y[maxn], z[maxn];
int n, m, s;

struct pii
{
    int x, y;
    pii(int x = 0, int y = 0) :x(x), y(y) {}
    void read() { scanf("%d%d", &x, &y); }
}f[maxn];

pii operator +(pii a, pii b)
{
    return pii(a.x + b.x, a.y + b.y);
}

pii get(int X, int Y)
{
    dp[0] = 0;  f[0] = pii(0, 0);
    for (int i = 1; i <= s; i++) dp[i] = 1LL << 62;
    for (int i = 1; i <= n; i++)
    {
        LL v = (LL)y[i] * X + (LL)z[i] * Y;
        for (int j = s; j >= x[i]; j--)
        {
            if (dp[j] <= dp[j - x[i]] + v) continue;
            dp[j] = dp[j - x[i]] + v;
            f[j] = f[j - x[i]] + pii(y[i], z[i]);
        }
    }
    int k = m;
    for (int i = m; i <= s; i++) if (dp[i] < dp[k]) k = i;
    ans = min(ans, (LL)f[k].x*f[k].y);
    return f[k];
}

void solve(pii x, pii y)
{
    pii t = get(x.y - y.y, y.x - x.x);
    if (1LL * (x.x - y.x)*(t.y - y.y) <= 1LL * (x.y - y.y)*(t.x - y.x)) return;
    solve(x, t), solve(t, y);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        ans = 1LL << 62;    s = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &x[i], &y[i], &z[i]);
            s += x[i];
        }
        solve(get(1, 0), get(0, 1));
        printf("%I64d\n", ans);
    }
    return 0;
}