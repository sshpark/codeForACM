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

ll gcd(ll a, ll b)
{
	return b ? gcd(b, a%b) : a;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	ll d, t;
	if (b == 0){x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a/b*y;
	return d;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll a, b, n, m, mm, x, y;

	while (~scanf("%lld %lld", &n, &m))
	{
		ll mm = gcd(n, m);
		if (n == 1)
		{
			printf("%lld\n", m);
			continue;
		}
		if (m == 1)
		{
			puts("1");
			continue;
		}
		if (mm == 1)
		{
			m = min(n, m);
			printf("%lld\n", m);
			continue;
		}
		if (n > m)	
			printf("%lld\n", m/mm);
		else
		{
			printf("%lld\n", (m-n)/mm);
		}

	
	}

    return 0;
}

// 12 32
// 12 28
// 12 24
// 12 20
// 12 16
// 12 12
// 12 0

// 12 4
// 12 0

// 8 88
// 8 80
// 8 72
// 8 64
// 8 


// 88 - n*x  = a;
