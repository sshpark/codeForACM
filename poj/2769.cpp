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

int a[100001], book[100001];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, n;
	cin >> T;
	
	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		int flag = 1, m = 1;

		while (true)
		{
			flag = 1;
			for (int i = 0; i < m; i++)
				book[i] = 0;
			for (int i = 0; i < n; i++)
			{
				if (book[a[i]%m])
				{
					flag = 0;
					break;
				}
				book[a[i]%m] = 1;
			}
			if (flag)
				break;
			m++;
		}
		printf("%d\n", m);
	}

	
    return 0;
}