#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
#define rep(i, k, n) for (int i = k; i < n; i++)
#define repp(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
char str[200005];
int vis[200005];
inline bool ok(char a, char b, char c) {
    if (a == 'C' and b == 'C' and c == 'C') return true;
    if (a == 'C' and b == 'P' and c == 'C') return true;
    if (a == 'C' and b == 'C' and c == 'P') return true;
    return false;
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int T, n, ans;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        scanf("%s", str+1);
        for (int i = 1; i <= n; i++) vis[i] = 0;
        for (int i = 1; i <= n-3; i++)
            if (str[i+2] == 'P' && str[i] == 'C' && str[i+1] == 'C' && str[i+3] == 'C') {
                ans++;
                vis[i+1] = vis[i+2] = 1;
            }
        for (int i = 1; i <= n-2; i++)
            if (vis[i] == 0 && vis[i+1] == 0 && vis[i+2] == 0 && ok(str[i], str[i+1], str[i+2])) {
                ans++;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}
