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
int a[15], book[15];
int n, k, ans;

bool check(int l)
{
	REPP(i, 1, l)
	if (a[i] > k)
		return false;
	REPP(i, 1, l-1)
	if (a[i]*a[i+1] > k)
		return false;
	return true;
}

void dfs(int l, int step)
{
	if (step == l+1)
	{
		if (a[1] != 0 && check(l))
		{
			ans++;
		}
		return ;
	}
	for (int i = 0; i <= k; i++)
	{
		a[step] = i;
		dfs(l, step+1);
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	

	while (~scanf("%d %d", &n, &k))
	{
		ans = 0;
		dfs(n, 1);	
		printf("%d\n", ans);
	}

    return 0;
}

10
94
892
8640
84657
834966
8267019
82052137
815725636
8118965902