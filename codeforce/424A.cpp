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

int a[105];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	int s1, f1, s2, f2, s3, f3, s4, f4;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		int flag = 1;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] > a[i-1])
			{
				s1 = 1;
				f1 = 1;
			}
			if (a[i] == a[i-1])
			{
				s2 = 1;
				f2 = 1;
			}
			if (a[i] < a[i-1])
			{
				s3 = 1;
				f3 = 1;
			}
		}
		
	}

    return 0;
}