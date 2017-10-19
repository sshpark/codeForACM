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

bool ok(int n)
{
	int a[10], cnt = 0;
	while(n)
	{
		a[cnt++] = n%10;
		n /= 10;
	}
	rep(i, 0, cnt)
	if (a[i] == 4) return false;
	rep(i, 1, cnt)
	if (a[i] == 6 && a[i-1] == 2) return false;
	return true;
}
int pre[1000005];
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int l, r;

	repp(i, 1, 1000004)
		if (ok(i)) pre[i] = 1;
	repp(i, 2, 1000004)
		pre[i] += pre[i-1];
	
	while (~scanf("%d %d", &l, &r) && l+r)
	{
		printf("%d\n", pre[r]-pre[l-1]);
	}

    return 0;
}