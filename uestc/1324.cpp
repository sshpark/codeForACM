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
const int maxn = 1e5+7;
int block, belong[maxn], num, l[maxn], r[maxn], n, q;
ll a[maxn], Max[maxn];
void build()
{
	block = sqrt(n);
	num = n/block; if (n%block) num++;
	REPP(i, 1, num) l[i] = (i-1)*block+1, r[i] = i*block;
	r[num] = n;
	REPP(i, 1, n)
	belong[i] = (i-1)/block+1;

	REPP(i, 1, num)
	{
		REPP(j, l[i], r[i])
		Max[i] = max(Max[i], a[j]);
	}
}

void update(int x, int y)
{
	a[x]+=y;
	Max[belong[x]] = max(Max[belong[x]], a[x]);
}
ll ask(int x, int y)
{
	ll ans = 0;
	if (belong[x] == belong[y])
	{
		REPP(i, x, y) ans = max(a[i], ans);
		return ans;
	}
	REPP(i, x, r[belong[x]])
	ans = max(ans, a[i]);
	REP(i, belong[x]+1, belong[y])
	ans = max(ans, Max[i]);
	REPP(i, l[belong[y]], y)
	ans = max(ans, a[i]);
	return ans;
	
}
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &q);
	build();
	REP(i, 0, q)
	{
		int op, p, x;
		scanf("%d %d %d", &op, &p, &x);
		if(op == 1) update(p, x);
		else printf("%lld\n", ask(p, x));
	}

    return 0;
}