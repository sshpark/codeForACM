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

unsigned f(unsigned n, unsigned m)
{
	unsigned a = m+n;
	unsigned b = min(m, n);
	double r = 1.0;
	while(b > 0)
		r *= (double)(a--)/(double)(b--);
	return (unsigned)(r+0.5);
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	unsigned n, m;

	while (~scanf("%u %u", &n, &m) && n+m)
	{
		printf("%u\n", f(n, m));
	}

    return 0;
}