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

pair<int, int> a[100005];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, c, x, k;

	while (~scanf("%d%d", &c, &n) && n+c)
	{
		ll sum = 0;
		k = -1;
		REP(i, 0, n)
		{
			scanf("%d", &x);
			sum += x;
			a[i].first = sum%c;
			a[i].second = i+1;
			if (k == -1 && a[i].first == 0){k = i;}
		}
		if (k == -1)
		{
			int r = 0;
			sort(a, a+n, cmp);
			REP(i, 0, n-1)
			if (k == -1 && a[i].first == a[i+1].first)
			{
				k = a[i].second;
				r = a[i+1].second;
				break;
			}
			if (k == -1) puts("no sweets");
			else
			{
				REP(i, k+1, r) printf("%d ", i);
				printf("%d\n", r);
			}

		}
		else
		{
			REP(i, 0, k) printf("%d ", i+1);
			printf("%d\n", k+1);
		}

	}

    return 0;
}