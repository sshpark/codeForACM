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

	ll a, b, p, x, y;

	while (~scanf("%lld%lld%lld", &a, &b, &p))
	{
		exgcd(b, p, x, y);
		x = (x%p+p)%p;
		printf("%lld\n", ((a%p)*(x%p))%p);
	}

    return 0;
}