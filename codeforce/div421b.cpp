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
	// freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, a;

	while (~scanf("%d %d", &n, &a))
	{
		double pd = (n - 2)*180.0/n;
		double d = (180 - pd)/2;
		double sum = d;
		int tn = n;

		while (true)
		{
			if (sum >= a)
			{
				if (abs(sum - d - a) < abs(sum-a) && (sum - d) >= d)
					printf("1 2 %d\n", tn+1);
				else
				{
					printf("1 2 %d\n", tn);
				}
				break;
			}
			if (sum <= pd)
			{
				sum += d;
				tn--;
			}
			if (sum > pd)
			{
				printf("1 2 3\n");
				break;
			}
		}
	}

    return 0;
}