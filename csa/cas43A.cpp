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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
//#define LOCAL
const int maxn = 100005;
ll a[maxn+10], b[maxn+10], c[maxn+10];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int h, w, n, m;
	ll x = 0;
	ms(a);
	ms(b);
	cin >> h >> w >> n >> m;
	c[0] = 0;
	REPP(i, 1, n) scanf("%lld", c+i);
	sort(c+1, c+n+1);
	REPP(i, 1, n) a[c[i]-c[i-1]]++;
	a[h-c[n]]++;
	REPP(i, 1, m) scanf("%lld", c+i);
	sort(c+1, c+m+1);
	REPP(i, 1, m) b[c[i]-c[i-1]]++;
	b[w-c[m]]++;
	REPP(i, 1, maxn) x += a[i]*b[i];
	printf("%lld\n", x);
    return 0;
}