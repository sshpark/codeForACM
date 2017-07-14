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
int flag[1000001];
int n;
void solve()
{
	ms(flag);
	int t = sqrt(n+0.0);
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= t; ++i)
	{
		for (int j = i+1; j <= t; ++j)
		{
			if (i*i+j*j > n)
				break;
			if (i%2 != j%2)
			{
				if (__gcd(i, j) == 1)
				{
					int x = j*j - i*i;
					int y = 2*i*j;
					int z = j*j + i*i;
					ans1++;
					for (int k = 1; ; k++)
					{
						if (k*z > n)
							break;
						flag[k*x] = 1;
						flag[k*y] = 1;
						flag[k*z] = 1;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!flag[i])
			ans2++;
	}
	printf("%d %d\n", ans1, ans2);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	
	while (~scanf("%d", &n))
	{
		solve();		
	}

    return 0;
}