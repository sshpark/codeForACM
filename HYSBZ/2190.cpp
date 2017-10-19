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
#define rep(i, k, n) for (int i = k; i < n; i++)
#define repp(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
const int maxn = 40010;
bool isp[maxn];
ll p[maxn];
ll phi[maxn];
int cnt = 0;
void gphi(int n)
{
	memset(isp, true, sizeof(isp));
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (isp[i])
		{
			p[cnt++] = i;
			phi[i] = i-1;
		}
		for (int j = 0; j < cnt && i*p[j] <= n; j++)
		{
			isp[i*p[j]] = false;
			if (i%p[j] == 0)
			{
				phi[i*p[j]] = phi[i]*p[j];
				break;
			}
			else
				phi[i*p[j]] = phi[i]*(p[j]-1);
		}
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	while (~scanf("%d", &n))
	{
		cnt = 0;
		gphi(n);
		ll sum = 0;
		repp(i, 1, n-1) sum += 2*phi[i];
		printf("%lld\n", sum+1);
	}

    return 0;
}