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
#define eps 1e-10
#define LOCAL

inline int s(int n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll w, m, k;

	while (~scanf("%lld%lld%lld", &w, &m, &k))
	{
		double len = (w+0.0)/k;
		double re = 0;
		int i = 0;
		while (re - len < eps)
		{
			re += s(m++);
			i++;
		}
		printf("%d\n", i-1);
	}

    return 0;
}