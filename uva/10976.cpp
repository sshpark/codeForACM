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

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int k;

	while (~scanf("%d", &k))
	{
		int count = 0;
		for (int i = k+1; i <= 2*k; i++)
			if ((k * i) % (i - k) == 0)
				count++;
		printf("%d\n", count);
		for (int i = k+1; i <= 2*k; i++)
			if ((k * i) % (i - k) == 0)
				printf("1/%d = 1/%d + 1/%d\n", k, (k * i) / (i - k), i);
	}

    return 0;
}