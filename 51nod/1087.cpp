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

bool f(ll y)
{
	ll l = 1, r = 1e7;
	ll mid;

	bool flag = false;
	for (int i = 0; i < 200; i++)
	{
		mid = (l+r)/2;
		if ((mid*mid-mid+2)/2 == y)
		{
			flag = true;
			break;
		}
		if ((mid*mid-mid+2)/2 > y)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return flag;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T;
	ll n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (f(n))
			puts("1");
		else
			puts("0");
	}

    return 0;
}
// 110100100010000