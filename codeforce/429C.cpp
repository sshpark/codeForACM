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
int a[200005], h[200005];

pair<int, int> b[200005];
bool cmp(int a, int b)
{
	return a > b;
}

bool cmp1(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
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

		REPP(i, 1, n)
		scanf("%d", a+i);
		REPP(i, 1, n)
		{
			scanf("%d", &b[i].first);
			b[i].second = i;
		}
		sort(a+1, a+n+1, cmp);
		sort(b+1, b+n+1, cmp1);		
		REPP(i, 1, n)
		h[b[i].second] = i;
		REPP(i, 1, n)
		printf("%d ", a[h[i]]);
		
		printf("\n");
	}

    return 0;
}