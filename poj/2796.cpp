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

const int N = 200005;
int a[N], lef[N], rig[N];
ll sum[N];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	scanf("%d", &n);
	REPP(i, 1, n){scanf("%d", a+i); sum[i] = sum[i-1]+a[i]; lef[i] = i; rig[i] = i;}
	REPP(i, 2, n)
	while(lef[i] > 1 && a[lef[i]-1] >= a[i])	//最小值向左边延伸
		lef[i] = lef[lef[i] - 1];
	for (int i = n-1; i >= 1; i--)
		while(rig[i] < n && a[rig[i]+1] >= a[i])  //最小值向右边延伸
			rig[i] = rig[rig[i]+1];
	int l, r;
	ll maxa = -1, tem;
	REPP(i, 1, n)
	{
		tem = a[i]*(sum[rig[i]] - sum[lef[i]-1]);
		if (tem > maxa)
		{
			l = lef[i];
			r = rig[i];
			maxa = tem;
		}
	}
	printf("%lld\n%d %d\n", maxa, l, r);
    return 0;
}