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
//#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, a, b;

	while (~scanf("%d%d%d", &n, &a, &b))
	{
		int x, nb = b, c = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			if (x == 1)
			{
				if (a > 0)
					a--;
				else if (a == 0)
				{
					
					if (nb > 0)
					{
						c++;
						nb--;
					}
					else if (c > 0)
						c--;
					else
						ans++;
				}
			}
			else
			{
				if (nb > 0)
					nb--;
				else
					ans += 2;
			}
		}
		printf("%d\n", ans);
	}

    return 0;
}