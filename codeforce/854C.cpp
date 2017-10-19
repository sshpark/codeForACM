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
#include <bitset>
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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
pair<int, int> a[300005];
int h[300005], r[300005];

bool cmp(pair<int, int> f, pair<int, int> s)
{
	return f.first < s.first;
}
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, k;

	while (~scanf("%d %d", &n, &k))
	{
		REPP(i, 1, n)
		{
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		sort(a+1, a+1+n, cmp);
		REPP(i, 1, n) h[i] = a[i].second;
		set<int> s;
		REPP(i, 1, n)
		{
			if (n+k-i+1-i >= 0)
			{
				r[h[i]] = n+k-i+1;
			}
			else
			{
				r[h[i-1]] = n+k-i+1;
				r[h[i]] = n+k-i+2;
				i++;
			}
		}
		REPP(i, 1, n-1)
		printf("%d ", r[i]);
		printf("%d\n", r[n]);


	}

    return 0;
}