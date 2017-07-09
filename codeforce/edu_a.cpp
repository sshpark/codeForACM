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
//#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll n, bn, k, dip, cer;
	
	while (~scanf("%lld %lld", &n, &k))
	{
		ll sn = n/2;
		
		while (true)
		{
			if (sn % (1+k) == 0)
				break;
			sn = sn - 1;
			if (sn == 0)
				break;
		}
		if (sn == 0)
		{
			printf("0 0 %lld\n", n);
			continue;
		}
		cer = sn/(1+k)*k;
		dip = sn/(1+k);
	
		printf("%lld %lld %lld\n", dip, cer, n - sn);
	}

    return 0;
}

