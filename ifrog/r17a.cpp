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

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	while (~scanf("%d", &n))
	{
		double re = -9;

		for (int i = 1; i <= 1000; i++)
			for (int j = 1; j <= 1000; j++)
			{
				if (n-j-j >= 1)
					re = 2*sin((i+j)/2)*cos((i-j)/2)+sin(n-i-j) > re ? 2*sin((i+j)/2)*cos((i-j)/2)+sin(n-i-j) : re;
				if (n-j-j < 1)
					break;
			}
			printf("%.9lf\n", re);
	}

    return 0;
}