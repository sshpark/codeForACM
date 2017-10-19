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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, k, m, a[50];

	while (~scanf("%d %d %d", &n, &k, &m))
	{
		int sum = 0;
		REP(i, 0, k){cin >> a[i]; sum += a[i];}
		sort(a, a+n);
		int r2 = 0, f = 0;
		for (int i = 0; i < n; i++)
		{
			i %= (n-1);
			REP(j, 0, k)
			{
				m -= a[i];
				if (m < 0)
				{
					f = 1;
					break;
				}
				printf("%d\n", m);
				r2++;
			}
			if (f) break;
		}
		printf("%d\n", r2);
	}

    return 0;
}