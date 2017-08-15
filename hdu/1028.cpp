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

	int n, a[125], b[125];

	while (~scanf("%d", &n))
	{
		ms(a);
		ms(b);
		a[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				for (int k = 0; j+k <= n; k+=i)
					b[j+k] += a[j];
			for (int j = 0; j <= n; j++)
			{
				a[j] = b[j];
				b[j] = 0;
			}
		}
		printf("%d\n", a[n]);
	}
		
    return 0;
}