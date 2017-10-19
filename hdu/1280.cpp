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
#define rep(i, k, n) for (int i = k; i < n; i++)
#define repp(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m, a[3005], sum[10005];

	while (~scanf("%d %d", &n, &m)) {
		ms(sum);
		rep(i, 0, n) scanf("%d", a+i);
		if (n == 1) {printf("%d\n", a[0]);continue;}
		rep(i, 0, n-1)
		rep(j, i+1, n) sum[a[i]+a[j]]++;
		for (int i = 10000; i >= 0; i--)
		{
			while (sum[i])
			{
				if (m == 1) {printf("%d\n", i); m--;break;}
				else printf("%d ", i);
				m--;
				sum[i]--;
			}
			if (m == 0)
				break;
		}
	}

	return 0;
}