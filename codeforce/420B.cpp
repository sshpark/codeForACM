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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int m, b;
	ll x, x1, d, xn;

	while (~scanf("%d %d", &m, &b))
	{
		x1 = 0;
		xn = 0;
		ll cur = 0, maxa = -inf;
		for (int i = b; i >= 0; i--)
		{
			x = m*(b-i);
			d = x+1;
			x1 = (x+1)*x/2;
			xn = x1 + i*d;
			cur = (i+1)*(x1+xn)/2;
			if (cur > maxa)
				maxa = cur;
		}
		printf("%lld\n", maxa);
	}

    return 0;
}