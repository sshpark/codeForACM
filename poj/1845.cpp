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

int exgcd(int a, int b, int &x, int &y)
{
	int d, t;
	if (b == 0){x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a/b*y;
	return d;
}

int mul(int x, int y)
{
	x %= 9901;
	if (x == 0)
		return 9900;
	if (x == 1)
		return 0;
	int m = 1;
	y %= 9900;
	while(y)
	{
		if (y & 1)
			m = m*x%9901;
		x = x*x%9901;
		y >>= 1;
	}
	return m - 1;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int a, b;
	int su[101][2];

	while (~scanf("%d %d", &a, &b))
	{
		if (a == 0)
		{
			puts("0");
			continue;
		}
		if (a == 1 || b == 0)
		{
			puts("1");
			continue;
		}
		int p = 0;
		for (int i  = 2; i*i <= a; i++)
		{
			if (a % i == 0)
			{
				su[p][0] = i;
				su[p][1] = 0;
				do
				{
					a /= i;
					su[p][1]++;
				}while(a%i == 0);
				p++;
			}
		}
		if (a > 1)
		{
			su[p][0] = a;
			su[p][1] = 1;
			p++;
		}
		for (int i = 0; i < p; i++)
			su[i][1] *= b;
		ll m = 1;
		int x, y;
		for (int i = 0; i < p; i++)
		{
			if (su[i][0]%9901 == 0)	continue;
			if (su[i][0]%9901 == 1)
			{
				m = m*(su[i][1] + 1)%9901;
				continue;
			}
			m = m*mul(su[i][0], su[i][1]+1)%9901;
			int g = exgcd(su[i][0] - 1, 9901, x, y);
			x = (x%9901 + 9901)%9901;
			m = m*x%9901;
		}
		printf("%lld\n", m);
	}

    return 0;
}