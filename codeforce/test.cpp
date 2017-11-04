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

int a[1000005], b[1000005];

int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif

    int n, m, num[60], x, sum = 0;
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> num[i];
        sum += num[i];
    }
    int cnt = 0;
    rep(i, n, n+n) num[i] = -num[cnt++];
    n = n << 1;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= sum; j++)
            for(int k = 0; k <= 1 && k*num[i]+j<=sum && k*num[i]+j >= 0;k++)
                b[k*num[i]+j] += a[j];
        for(int j = 0; j <= sum; j++){
                a[j] = b[j];
                b[j] = 0; 
            }
    }
    rep(i, 0, m) {
        cin >> x;
        puts(a[x] ? "YES" : "NO");
    }
    return 0;
}