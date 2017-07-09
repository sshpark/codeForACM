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
#define ms(s) memset(s, true, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
const int N = 1300000;
bool isprime[N];
int prime[N];

void Euler()
{
	int num = 1;
	ms(isprime);
	for (int i = 2; i <= N; i++)
	{
		if (isprime[i])
			prime[num++] = i;
		for (int j = 1; j < num; j++)
		{
			if (i * prime[j] > N)
				break;
			isprime[i*prime[j]] = false;
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	Euler();
	while (~scanf("%d", &n) & n)
	{
		if (isprime[n])
			puts("0");
		else
		{
			int l = n, r = n;
			while (!isprime[l--]);
			while (!isprime[r++]);
			// printf("%d %d\n", l+1, r-1);
			printf("%d\n", r - l - 2);
		}
	}

    return 0;
}