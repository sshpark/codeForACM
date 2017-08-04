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
#define ms(s) memset(s, 1, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
int isprime[1005];

void shuai()
{
	ms(isprime);
	for (int i = 2; i < 1005; i++)
	{
		if (isprime[i])
		{
			for (int j = i*i; j < 1005; j+=i)
			{
				isprime[j] = 0;
			}
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
	shuai();
	while (~scanf("%d", &n))
	{
		int cnt = 0;
		for (int i = 2; i <= n/2; i++)
		{
			if (isprime[i] && isprime[n - i])
				cnt++;
		}
		printf("%d\n", cnt);
	}

    return 0;
}