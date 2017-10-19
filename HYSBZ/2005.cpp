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
// #define LOCAL
const int N = 100010;

int mu[N], smu[N], u[N], su[N], num;

void cal_mu()
{
	mu[1] = smu[1] = 1;
	REP(i, 2, N)
	{
		if (!u[i])
			su[num++] = i, mu[i] = -1;
		REP(j, 0, num)
		{
			if ((ll)i*su[j] >= N)
				break;
			u[i*su[j]] = 1;
			if (i%su[j] == 0)
			{
				mu[i*su[j]] = 0;
				break;
			}
			else
				mu[i*su[j]] = -mu[i];
		}
		smu[i] = smu[i-1]+mu[i];
	}
}

ll getans(int n, int m)
{
	ll ans = 0;
	REPP(i, 1, n)
	{
		int l = min(n/(n/i), m/(m/i)) - i;
		ans += (ll)(smu[i+1]-smu[i-1])*(n/i)*(m/i);
		i+=l;
	}
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	cal_mu();
	int n, m;
	scanf("%d %d", &n, &m);
	if (n > m)
		swap(n, m);
	ll ans = 0;
	REPP(i, 1, n)
	{
		int d = min(n/(n/i), m/(m/i)), l = d-i+1;
		ans += (ll(d+i)*l/2)*getans(n/i, m/i);
		i = d;
	}
	ans = ans*2 - (ll)n*m;
	printf("%lld\n", ans);
    return 0;
}