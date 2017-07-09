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
//#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int c, v0, v1, a, l;

	while (~scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l))
	{
		int sum = 0, days = 0, pday = v0;
		if (v0 <= v1)
		{
			sum = v0;
			days = 1;
		}
		else
		{
			sum = v1 - v0;
			days = 1;
		}
		int flag = 0;
		while (true)
		{
			if (sum >= c)
			{
				printf("%d\n", days);
				break;
			}
			sum -= l;
			if (!flag)
				pday += a;
			if (pday > v1)
			{
				flag = 1;
				pday = v1;
			}
			sum += pday;
			days++;
		}
	}
    return 0;
}