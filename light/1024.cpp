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
	return b == 0 ? a : gcd(b, a%b);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, n, x, kase = 0;
	scanf("%d", &T);


	while (T--)
	{
		scanf("%d", &n);
		ll re = 1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			re = re*x/gcd(re, x);
		}
		printf("Case %d: %lld\n", ++kase, re);
	}

    return 0;
}