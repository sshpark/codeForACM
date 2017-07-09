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

int power(int a, int b, int m)
{
	int ans = 1;
	a %= m;

	while (b)
	{
		if (b & 1)
			ans = ans * a % m;
		b >>= 1;
		a = a * a % m;
	}
	return ans;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, n, m;
	scanf("%d", &T);
	

	while (T--)
	{
		scanf("%d", &m);
		scanf("%d", &n);
		int a, b, re = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			re += power(a, b, m);
		}
		printf("%d\n", re%m);
	}

    return 0;
}