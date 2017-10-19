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

int w[6] = {1, 2, 3, 5, 10, 20};

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, a[1005], b[1005], num[6];
	REP(i, 0, 6)
	scanf("%d", num+i);
	ms(a);
	ms(b);
	a[0] = 1;
	REP(i, 0, 6)
	{
		if (!num[i])
			continue;
		REP(j, 0, 1005)
		for (int k = 0; k <= num[i] && k*w[i]+j < 1005; k++)
			b[k*w[i]+j] += a[j];
		REP(j, 0, 1005)
		{
			a[j] = b[j];
			b[j] = 0;
		}
	}
	ll sum = 0;
	for (int i = 1; i < 1005; i++)
		if (a[i])
			sum++;
	printf("Total=%lld\n", sum);
    return 0;
}