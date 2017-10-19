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
		{
			scanf("%d", &a[i].first);
			a[i].second = i;
		}
		sort(a+1, a+n+1);		
		ll sum = 0;
		REPP(i, 1, n-1)
			sum += min(abs(a[i].second-a[i+1].second), n-max(a[i].second, a[i+1].second)+min(a[i].second, a[i+1].second));
		printf("%lld\n", sum);
		

	}

    return 0;
}