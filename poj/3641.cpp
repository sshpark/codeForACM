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

bool is(ll n)
{
	if (n == 0 || n == 1)
		return false;
	for (ll i = 2; i*i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

ll qmod(ll a, ll b, ll c)
{
	ll ans = 1;
	while(b)
	{
		if (b&1)
		{
			ans = (ans*a) % c;
			b--;
		}
		b >>= 1;
		a = a*a%c;
	}
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll p, a;

	while (~scanf("%lld%lld", &p, &a) && a+p)
	{
		if (is(p))
			puts("no");
		else
		{
			ll ans = 1;
			ans = qmod(a, p, p);
			if (ans == a)
				puts("yes");
			else
				puts("no");
		}
	}

    return 0;
}