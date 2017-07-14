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
char e[105][105], str[105];


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int l, r, u, d;
	int n, m, cal = 0;

	while (~scanf("%d%d", &n, &m))
	{
		l = r = l = d = 0; 
		cal = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < m; j++)
			{
				e[i][j] = str[j];
				if (str[j] == 'B')
					cal++;
			}
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				if (e[i][j] == 'B')
				{
					flag = 1;
					u = i;
					break;
				}
			if (flag)
				break;
		}
		flag = 0;
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < m; j++)
				if (e[i][j] == 'B')
				{
					flag = 1;
					d = i;
					break;
				}
			if (flag)
				break;
		}
		flag = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				if (e[j][i] == 'B')
				{
					flag = 1;
					l = i;
					break;
				}
			if (flag)
				break;
		}
		flag = 0;
		for (int i = m-1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
				if (e[j][i] == 'B')
				{
					flag = 1;
					r = i;
					break;
				}
			if (flag)
				break;
		}
		int h = d-u+1, w = r-l+1;
		// printf("%d %d\n", h, w);
		if (h == 0 && w == 0)
		{
			puts("1");
			continue;
		}
		if (h == w)
			printf("%d\n", h*w-cal);
		else if (h > w && h <= m)
			printf("%d\n", h*h-cal);
		else if (h < w && w <= n)
			printf("%d\n", w*w-cal);
		else
			puts("-1");

	}

    return 0;
}