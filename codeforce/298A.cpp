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

	int n, s, t;
	char str[1005];
	while (~scanf("%d", &n))
	{
		s = t = 0;
		int L, R;
		L = R = 0;
		scanf("%s", str);
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'R')
			{
				R++;
				s = i;
			}
			if (str[i] == 'L')
			{
				L++;
				t = i;
			}
		}
		if (s == 0)
		{
			s = t+2;
			t = s-L;
			printf("%d %d\n", s, t);
			continue;
		}
		if (t == 0)
		{
			t = s+2;
			s = s+2 - R;
			printf("%d %d\n", s, t);
			continue;
		}
		printf("%d %d\n", s, t-L+1);
	}

    return 0;
}
