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
const int N = 50005;
int c[N], _hash[N], n;
pair<int, int> a[N];

inline int lowbit(int n)
{
	return n & (-n);
}

void add(int i, int val)
{
	while (i <= n)
	{
		c[i] += val;
		i += lowbit(i);
	}
}

int gsum(int k)
{
	int sum = 0;
	while(k)
	{
		sum += c[k];
		k -= lowbit(k);
	}
	return sum;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	while (~scanf("%d", &n))
	{
		ms(c);
		int x, ans = 0;
		for (int i = 1;i <= n;i++)
		{ 
			scanf("%d",&a[i].first);
			a[i].second = i;
		}
		sort(a+1, a+n+1);
		for (int i = 1; i <= n; ++i)
			_hash[a[i].second] = i;
		for (int i = 1; i <= n; i++)
		{
			add(_hash[i], 1);
			ans += i - gsum(_hash[i]);
		}
		printf("%d\n", ans);
	}

    return 0;
}