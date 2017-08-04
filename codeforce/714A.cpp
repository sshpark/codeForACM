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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll  l1, r1, l2, r2, k;

	while (~scanf("%lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k))
	{
		if (l2 > r1 || (l2 == r2 && l1 != r1) || l1 > r2)
		{
			puts("0");
			continue;
		}
		if (l1 == r1)
		{
			puts("1");
			continue;
		}
		if (r2 >= l1 && l2 <= l1 && r2 <= r1)
		{
			if (k >= l1 && k <= r2)
				printf("%lld\n", k-l1+r2-k);
			else
				printf("%lld\n", r2 - l1+1);
		}
		else if (l1 <= l2 && r2 <= r1)
		{
			if (k >= l2 && k <= r2)
				printf("%lld\n", k-l2+r2-k);
			else
				printf("%lld\n", r2 - l2+1);	
		}
		else if (r2 >= r1 && l2 >=l1 && l2 <= r1)
		{
			if (k >= l2 && k <= r1)
				printf("%lld\n", k-l2+r1-k);
			else
				printf("%lld\n", r1 - l2+1);	
		}
		else if (r2 >= r1 && l2 <= l1)
		{
			if (k >= l1 && k <= r1)
				printf("%lld\n", k-l1+r1-k);
			else
				printf("%lld\n", r1-l1+1);
		}
	}

    return 0;
}