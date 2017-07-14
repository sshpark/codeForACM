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
int sum[10005];
int qmod(int a, int b, int c)
{
	int ans = 1;
	a %= c;
	while (b)
	{
		if (b & 01)
			ans = (ans * a) % c;
		a = (a*a)%c;
		b >>= 1;
	}
	return ans;
}

bool MillerRabin(int x, ll n)
{
	ll y = n - 1;
	while (!(y&1)) y >>= 1;
	x = qmod(x, y, n);
	while(y < n-1 && x != 1 && x != n-1)
		x = (x*x)%n, y <<= (ll)1;
	return (x == n-1) || ((y&1) == 1);
}

bool isprime(ll n)
{
	if (n == 2 || n == 7 || n == 61)
		return 1;
	if (n == 1 || (n&1) == 0)
		return 0;
	return MillerRabin(2, n) && MillerRabin(7, n) && MillerRabin(61, n);
}

ll pollard(ll n, int c)
{
	ll x, y, d, i = 1, k = 2;
	x = rand
}

int main()
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	ll n;
	int T;
	cin >> T;
	while(T--)
	{
		scanf("%lld", &n);
		if (isprime(n))
			puts("Prime");
		else
		{
			int i;
			for (i = 2; ; i++)
				if (n % i == 0)
					break;
			printf("%d\n", i);
		}
	}
}