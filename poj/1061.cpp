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
const int inf = 0x3f3f3f3f;
#define LOCAL

long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long d, t;
    if (b == 0) { x = 1; y = 0; return a; }
    d = extgcd(b, a % b, x, y);
    t = x - a / b * y; x = y; y = t;
    return d;
}



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

    long long x, y, m, n, L, X, Y, d, r;
    while (cin >> x >> y >> m >> n >> L)
    {
        d = extgcd(n - m, L, X, Y); r = L / d;
        if ((x - y) % d) puts("Impossible");
        else cout << ((x - y) / d * X % r + r) % r << endl;
    }
    return 0;
}