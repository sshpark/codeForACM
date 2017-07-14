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
#include <set>j
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
#define M 8191
typedef struct
{
	int m[4][4];
}matrax;

matrax per, d;
int n;
int x, y, D;

void search()
{
	y = 1;
	while (true)
	{
		x = sqrt(D*y*y+1);
		if (x*x - D*y*y == 1)
			break;
		y++;
	}
}

void init()
{
	d.m[0][0] = x%M;
	d.m[0][1] = D*y%M;
	d.m[1][0] = y%M;
	d.m[1][1] = x%M;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			per.m[i][j] = (i == j);
}

matrax multi(matrax a, matrax b)
{
	matrax c;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < n; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			c.m[i][j] %= M;
		}
	return c;
}

matrax power(int k)
{
	matrax p, ans = per;
	p = d;
	while (k)
	{
		if (k&1)
		{
			ans = multi(ans, p);
			k--;
		}
		k /= 2;
		p = multi(p, p);
	}
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int k;
	while (~scanf("%d %d", &D, &k))
	{
		int sqx = sqrt(D+0.0);
		if (sqx*sqx == D)
		{
			puts("No answers can meet such conditions");
			continue;
		}
		search();
		
		n = 2;
		init();
		d = power(k-1);
		x = (d.m[0][0]*x%M + d.m[0][1]*y%M)%M;
		printf("%d\n", x);
	}

    return 0;
}