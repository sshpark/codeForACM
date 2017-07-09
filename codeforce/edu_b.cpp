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

int a[105], book[105], b[105];
int n, m;
int ans = 0;
void dfs(int step)
{
	if (step == n+1)
	{
		int flag = 1;
		for (int i = 0; i < m; i++)
		{
			if ((a[i]+b[a[i]])%n == 0)
				continue;
			if ((a[i]+b[a[i]])%n != a[i+1])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ans = 1;
			for (int i = 1; i <= n-1; i++)
				printf("%d ", b[i]);
			printf("%d\n", b[n]);
			exit(0);
		}
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!book[i])
		{
			b[step] = i;
			book[i] = 1;
			dfs(step+1);
			book[i] = 0;
		}
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	while (~scanf("%d %d", &n, &m))
	{
		ms(book);
		ms(b);
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		dfs(1);
		if (!ans)
			puts("-1");
	}
    return 0;
}
