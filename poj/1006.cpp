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
int a[5];
int exgcd(int a, int b, int &x, int &y)
{
	int d, t;
	if (b == 0){x = 1; y = 0; return a;}
	d = exgcd(b, a%b, x, y);
	t = x;
	x = y;
	y = t - a/b*y;
	return d;
}


int china(int days)
{
	int M = 21252, mi, x, y, d, ans = 0;
	int m[4];
	m[1] = 23, m[2] = 28, m[3] = 33;
	for (int i = 1; i <= 3; ++i)
	{
		mi = M/m[i];
		d = exgcd(mi, m[i], x, y);
		ans = (ans + mi*x*a[i])%M;
	}
	while(ans <= days)
		ans += M;
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int d, p, e, i, kase = 0;

	while (~scanf("%d %d %d %d", &p, &e, &i, &d))
	{
		if (d == -1 && p == -1 && e == -1 && i == -1)
			break;
		a[1] = p, a[2] = e, a[3] = i;
		printf("Case %d: the next triple peak occurs in %d days.\n", ++kase, china(d) - d);
	}

    return 0;
}