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
#include <bitset>
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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
const int maxn = 10005;
bool isp[maxn];
int ans[maxn], len = 0, n;
void shuai()
{
	memset(isp, true, sizeof(isp));
	for (ll i = 2; i < maxn; i++)
	{
		if (isp[i])
		{
			ans[len++] = i;
			for (ll j = i*i; j < maxn; j+=i)
				isp[j] = false;
		}
	}
}
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	shuai();
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int maxa = -1, r = 0;
		REP(i, 0, len)
		{
			if (ans[i] > n)
				break;
			if (maxa < n%ans[i])
			{
				maxa = n%ans[i];
				r = ans[i];
			}
		}
		printf("%d\n", r);
	}

    return 0;
}