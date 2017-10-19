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
#define LOCAL

bool ok(ll a, ll b, ll p)
{
	a %= p;
	ll d = 1;
	if (a == 0)
		return true;
	while (b)
	{
		if (b&1) d = d*a%p;
		b /= 2;
		a = a*a%p;
	}
	if (d == 1)
		return true;
	else
		return false;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll n, p;

	while (~scanf("%lld %lld", &n, &p) && n != -1 && p != -1)
		if (ok(n, (p-1)/2, p)) puts("YES");
		else puts("NO");
    return 0;
}