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

	int T, a[55], b[55], x;
	scanf("%d", &T);
	while (T--)
	{
		ms(a);
		ms(b);
		a[0] = 1;
		for (int i = 1; i <= 26; i++)
		{
			scanf("%d", &x);
			if (x == 0)
				continue;
			for (int j = 0; j <= 50; j++)
				for (int k = 0; k <= x && k*i+j <= 50; k++)
					b[k*i+j] += a[j];
			for (int j = 0; j <= 50; j++)
			{
				a[j] = b[j];
				b[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 1; i <= 50; i++)
			sum += a[i];
		printf("%d\n", sum);
	}

    return 0;
}