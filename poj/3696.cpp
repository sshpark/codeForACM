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
ll gcd(ll a, ll b){ return a == 0 ? b : gcd(b % a, a); } 
ll mo;
ll mul(ll a, ll b)
{
	ll n = 0;
	while (b)
	{
		if (b & 1)
			n = (n + a)%mo;
		a = a * 2 % mo;
		b >>= 1;
	}
	return n;
}

ll mul(ll x)
{
	ll n = 1, m = 10;
	while (x)
	{
		if (x & 1)
			n = mul(n, m);
		m = mul(m, m);
		x >>= 1;
	}
	return n;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int ca = 0;

	while (~scanf("%lld", &mo) && mo)
	{
		printf("Case %d: ", ++ca);
		mo = mo * 9 /gcd(mo, 8);
		if (gcd(mo, 10) != 1)
		{
			printf("0\n");
			continue;
		}
		ll rear = mo, n = mo;
		ll p[50][2];
		int k = 0;
		for (ll i = 2; i * i <=n; i++)
			if (n % i == 0)
			{
				rear = rear - rear/i;
				do
				{
					n /= i;
				}while(n%i == 0);
			}
		if (n > 1)
			rear = rear - rear/n;
		n = rear;
		for (ll i = 2; i * i <= n; i++)
			if (n % i == 0)
			{
				p[k][0] = i;
				p[k][1] = 0;
				do{
					n /= i;
					p[k][1]++;
				}while(n%i == 0);
				k++;
			}
		if (n > 1)
		{
			p[k][0] = n;
			p[k][1] = 1;
			k++;
		}
		for (int i = 0; i < k; i++)
			for (int j = 1; j <= p[i][1]; j++)
				if (mul(rear/p[i][0]) == 1)
					rear /= p[i][0];
				printf("%lld\n", rear);
	}

    return 0;
}