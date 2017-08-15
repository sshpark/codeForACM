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

double c[15];

void pre()
{
	c[0] = c[1] = 1.0;
	for (int i = 2; i < 15; i++)
		c[i] = c[i-1]*i;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m, num[15];
	double a[15], b[15];

	pre();
	while (~scanf("%d %d", &n, &m))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);
		for (int i = 0; i < 15; i++)
			a[i] = b[i] = 0.0;
		for (int i = 0; i <= num[1]; i++)
			a[i] = 1.0/c[i];
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
				for (int k = 0; k+j <= m && k <= num[i]; k++)
					b[j+k] += a[j]/c[k];
			for (int j = 0; j <= m; j++)
			{
				a[j] = b[j];
				b[j] = 0;
			}
		}
		printf("%.0lf\n", a[m]*c[m]);
	}	
    return 0;
}