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

struct matrax
{
	int m[35][35];
};

matrax a, per;
int n, M;

void init()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &a.m[i][j]);
			a.m[i][j] %= M;
			per.m[i][j] = (i == j);
		}
}

matrax multi(matrax a, matrax b)
{
	matrax c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c.m[i][j] = 0;
			for (int k = 0; k < n; k++)
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			c.m[i][j] %= M;
		}
	}
	return c;
}

matrax add(matrax a, matrax b)
{
	matrax c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c.m[i][j] = (a.m[i][j] + b.m[i][j])%M;
		}
	}
	return c;
}

matrax power(int k)
{
	matrax c, p, ans= per;
	p = a;
	while(k)
	{
		if (k & 1)
		{
			ans = multi(ans, p);
			k--;
		}
		else
		{
			k /= 2;
			p = multi(p, p);
		}	
	}
	return ans;
}

matrax sum(int k)
{
	if (k == 1)
		return a;
	matrax tmp, b;
	tmp = sum(k/2);
	if (k & 1)
	{
		b = power(k/2+1);
		tmp = add(tmp, multi(tmp, b));
		tmp = add(tmp, b);
	}
	else
	{
		b = power(k/2);
		tmp = add(tmp, multi(tmp, b));
	}
	return tmp;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif	
	int k;
	while (~scanf("%d %d %d", &n, &k, &M))
	{
		init();
		
		matrax re = sum(k);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%d ", re.m[i][j]);
			printf("\n");
		}

	}

    return 0;
}