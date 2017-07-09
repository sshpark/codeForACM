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

int exgcd(int a, int b, int &x, int &y)
{
	int t, d;
	if (b == 0) {x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a/b*y;
	return d;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m, a[15], b[15];
	int T;
	cin >> T;
	while(T--)
	{
	scanf("%d %d", &n, &m);
	
		int a1, b1, a2, b2, x, y, flag = 1;

		for (int i = 0; i < m; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &b[i]);
		
		a1 = a[0], b1 = b[0];
		for (int i = 1; i < m; i++)
		{
			a2 = a[i], b2 = b[i];
			int g = exgcd(a1, a2, x, y);
			if ((b2-b1) % g != 0)
			{
				flag = 0;
			}
			int t = a2/g;
			x = (x*((b2-b1)/g)%t+t)%t;
			b1 = a1*x + b1;
			a1 = a1*(a2/g);
		}
		if (flag)
		{
			int sum = 0;
			while (b1 + sum*a1 <= n)
			{
				sum++;
			}
			if (b1 != 0)
				printf("%d\n", sum);
			else
				printf("%d\n", sum-1);
		}
		else
			puts("0");
		
	}

    return 0;
}