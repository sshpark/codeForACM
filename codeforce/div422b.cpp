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

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m;
	int book[1005], re[1005];
	char s[1005], t[1005];
	while (~scanf("%d %d", &n, &m))
	{
		scanf("%s %s", s, t);
		ms(book);
		ms(re);
		int minx = inf;
		for (int i = 0; i < m-n+1; i++)
		{
			int k = 0, cur = 0;
			ms(book);
			for (int j = 0; j < n; j++)
			{
				if (s[j] != t[i+k])
				{
					book[j] = 1;
					cur++;
				}
				k++;
			}
			if (minx > cur)
			{
				minx = cur;
				for (int q = 0; q < n; q++)
					re[q] = book[q];
			}
		}
		printf("%d\n", minx);
		int kase = 0;
		if (minx != 0)
		{
			for (int i = 0; i < n; i++)
				if (re[i] != 0)
				{
					if (kase == 0)
						printf("%d", i+1);
					else
						printf(" %d", i+1);
					kase++;
				}
			printf("\n");
		}
	}

    return 0;
}