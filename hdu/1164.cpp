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

int fac[1005];

void divide(int n)
{
	int len = sqrt(n+0.0);
	int j = 0;
	for (int i = 2; i <= len; i++)
	{
		while (n % i == 0)
		{
			if (j == 0)
				printf("%d", i);
			else
				printf("*%d", i);
			j++;
			n /= i;
		}
	}
	if (j == 0)
		printf("%d", n);
	else if (n != 1)
		printf("*%d", n);
	printf("\n");
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;

	while (~scanf("%d", &n))
	{
		divide(n);		
	}

    return 0;
}