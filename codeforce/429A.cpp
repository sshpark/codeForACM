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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, k;
	char str[105];
	int a[30];

	while (~scanf("%d%d", &n, &k))
	{
		ms(a);
		scanf("%s", str);
		int len = strlen(str);
		REP(i, 0, len)
			a[str[i]-'0'-49]++;
		int flag = 0;
		REP(i, 0, 30)
		{
			if (a[i] > k)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			puts("NO");
		else
			puts("YES");

		
	}

    return 0;
}