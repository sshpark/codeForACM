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

ll solve(ll n)
{
	ll l = 1, r = 50005;
	ll mid;
	for (int i = 0; i < 100; i++)
	{
		mid = (l+r) >> 1;
		ll re = mid*(1+mid)/2;
		if (re > n)
			r = mid - 1;
		else if (re < n)
			l = mid + 1;
		else
			return ;
	}
	if (mid*(mid+1)/2 < n)
		return n - mid*(mid+1)/2;
	else
		return mid*(mid+1)/2 - n;
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
		printf("%lld\n", solve(n));
	}

    return 0;
}

11212312341234512345612345671234567812345678912345678910123456789101112345678910