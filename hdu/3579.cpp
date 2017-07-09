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

int a[10], b[10];

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

	int T;
	int n, kase = 1;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &b[i]);
		int a0 = a[0], b0 = b[0], x, y;
		int flag = 1;

		for (int i = 1; i < n; i++)
		{
			int a1 = a[i], c = b[i] - b0;
			int g = exgcd(a0, a1, x, y);
			if (c % g != 0)
			{
				flag = 0;
				break;
			}
			int t = a1/g;
			x = (x * (c/g) % t + t) % t;
			b0 = a0*x + b0;
			a0 = a0 * (a1/g);
		}
		printf("Case %d: ", kase++);
		if (flag)
		{
			if (b0 == 0)
				printf("%d\n", a0);
			else
				printf("%d\n", b0);
		}
		else
			puts("-1");
	}

    return 0;
}

 X
XXX


      A
     A A
    A   A
   A     A
  A       A
 A         A
AAAAAAAAAAAAA