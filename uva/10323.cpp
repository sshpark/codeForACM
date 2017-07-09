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

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	while (~scanf("%d", &n))
	{
		ll sum = 1;
		if (n > 13 || (n < 0 && (-n) % 2 == 1))
		{
			puts("Overflow!");
			continue;
		}
		if (n < 8 || (n < 0 && (-n) % 2 == 0))
		{
			puts("Underflow!");
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			sum *= i;
		}
		printf("%lld\n", sum);
	}
    return 0;
}