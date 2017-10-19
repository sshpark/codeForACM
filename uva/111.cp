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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, x, a[25], b[25], t[25], dp[25][25];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		a[t[i]] = i;
	}
	while(! cin.eof())
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> t[i];
			b[t[i]] = i;
		}
		ms(dp);
		if (cin.eof())
			break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
				if (a[i] == b[j])
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		cout << dp[n][n] << endl;
	}
    return 0;
}