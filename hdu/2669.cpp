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
// #define LOCAL

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	ll d, t;
	if (b == 0) {x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x - a/b*y;
	x = y;
	y = t;
	return d;
}	

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll a, b, nx, ny;
	while (~scanf("%lld %lld", &a, &b))
	{
		nx = 0, ny = 0;
		ll g = exgcd(a, b, nx, ny);
		if (1%g != 0)
			puts("sorry");
		else
		{
			nx = nx / g;
			ll minx = inf, miny = 0;
			nx = nx%b;
			if (nx < 0)
				nx += b;
			printf("%lld %lld\n", nx, (1-nx*a)/b);
		}
	}

    return 0;
}