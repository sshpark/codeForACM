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

int getsum(int n)
{
	int sum = 0, t = 0;
	int len = sqrt(n+0.0);
	for (int i = 2; i <= len; i++)
	{
		if (n % i == 0)
		{
			if (i == len && n/i == i)
				sum += i;
			else
			{
				sum += i;
				sum += n/i;
			}
		}
	}
	return sum+1;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, n;
	scanf("%d", &T);

  	while (T--)
  	{
    	scanf("%d", &n);
    	printf("%d\n", getsum(n));
  	}

    return 0;
}