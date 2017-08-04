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
#define ms(s) memset(s, 1, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
const int maxn = 100000;
bool same(int a, int b)
{
	set<int> s;
	while (a)
	{
		s.insert(a%10);
		a /= 10;
	}
	while (b)
	{
		if (s.find(b%10) != s.end())
			return true;
		b /= 10;
	}
	return false;
}

int solve(int n)
{
	int re = 0;
	int tem = n;
	int len = sqrt(n);
	for (int i = 1; i <= len; i++)
	{
		if (n % i == 0)
		{
			if (same(tem, i))
				re++;
			if (same(tem, n/i) && ((n/i) != i))
				re++;
		}
	}
	return re;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	while (~scanf("%d", &n))
	{
		if (n != 1)
		{
			printf("%d\n", solve(n));
		}
		else
			puts("1");
	}

    return 0;
}