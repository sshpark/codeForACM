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
pair<int, int> ans[100005];
bool isp[20000005];
int cnt[20000005];
int r = 0;
void shuai()
{
	memset(isp, true, sizeof(isp));
	for (ll i = 2; i < 20000005; i++)
	if (isp[i])
	{
		cnt[r++] = i;
		for (ll j = i*i; j < 20000005; j+=i)
		isp[j] = false;
	}
}
void pre()
{
	int k = 0;
	REP(i, 1, r)
	{
		if (cnt[i] - cnt[i-1] == 2)
			ans[k].first = cnt[i-1], ans[k++].second = cnt[i];
		if (k > 100000)
			break;
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	shuai();
	REPP(i, 1, 10)

	pre();
	while (~scanf("%d", &n))
	printf("(%d, %d)\n", ans[n-1].first, ans[n-1].second);
			
	

    return 0;
}