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
#define m 10000
int cache[10005];
int a0, a1, p, q, k;

int f(int n)
{
	if (n == 0)
		return a0;
	if (n == 1)
		return a1;
	if (cache[n] != 0)
		return cache[n];
	return cache[n] = p*f(n-1)%m + q*f(n-2)%m;
}



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif


	while (~scanf("%d %d %d %d %d", &a0, &a1, &p, &q, &k))
	{
		ms(cache);
		printf("%d\n", f(k)%m);
	}

    return 0;
}