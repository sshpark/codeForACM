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

	int r, g, b;

	while (~scanf("%d %d %d", &r, &g, &b))
	{
		int t = 29, color = 0;
		while (true)
		{
			if (color == 0)
			{
				if (r - 2 >= 0)
					r -= 2;
				else
					r = 0;
			}
			else if (color == 1)
			{
				if (g - 2 >= 0)
					g -= 2;
				else
					g = 0;
			}
			else if (color == 2)
			{
				if (b - 2 >= 0)
					b -= 2;
				else
					b = 0;
			}
			color = (color+1)%3;
			t++;
			if (r == 0 && g == 0 && b == 0)
				break;

		}
		printf("%d\n", t);
	}

    return 0;
}