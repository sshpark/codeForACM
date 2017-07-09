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

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	ll d, t;
	if (b == 0){x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x - (a/b)*y;
	x = y;
	y = t;
	return d;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll n;

	while (~scanf("%lld", &n))
	{
		ll flag = 1;
		ll a, b, c, a1, c1, a2, c2, x, y;
		scanf("%lld %lld", &a1, &c1);
		for (ll i = 1; i < n; i++)
		{
			scanf("%lld %lld", &a2, &c2);
			a = a1, b = a2, c = c2 - c1;
			ll g = exgcd(a, b, x, y);
			if (c % g != 0)
			{
				flag = 0;
			}
			ll t = b/g;
			x = (x*(c/g)%t + t)%t;
			c1 = a1 * x + c1;
			a1 = a1 * (a2/g);
			
		}
		if (flag)
		{
			printf("%lld\n", c1);
		}
		else
		{
			puts("-1");
		}
	}

    return 0;
}