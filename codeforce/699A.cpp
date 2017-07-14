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

char str[200005];
int a[200005];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	while (~scanf("%d", &n))
	{
		scanf("%s", str);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int minti = inf;
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			if (str[i - 1] == 'R' && str[i] == 'L')
			{
				flag = 1;
				minti = min(minti, (a[i] - a[i-1])/2);
			}
		}
		if (flag)
			printf("%d\n", minti);
		else
			puts("-1");
	}

    return 0;
}