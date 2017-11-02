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
char s[100005];
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        scanf("%s", s+1);
        if (m == 1 || m == n) {
            puts("0");
            continue;
        }
        int l, r, ans1 = 0, ans2 = 0;
        for (int i = 2; i <= m-1; i++)
            if (s[i] == 'R') ans1++;
        for (int i = m+1; i < n; i++)
            if (s[i] == 'L') ans2++;
        if (s[m] == 'L')
            printf("%d\n", min(ans1, ans2+1));
        else
            printf("%d\n", min(ans1+1, ans2));
    }

    return 0;
}