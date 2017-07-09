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
const int N = 9999999;
bool isPrime[N+5];
int Prime[5000005];


int shuai()
{
	int num = 0;
	ms(isPrime);
	for (int i = 2; i <= N; i++)
	{
		if (isPrime[i])
			Prime[++num] = i;
		for (int j = 1; j<= num; j++)
		{
			if (i*Prime[j] > N) break;
			isPrime[i*Prime[j]] = false;
			if (i % Prime[j] == 0) break;
		}
	}
	return num;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, f;
	int len = shuai();

	while (~scanf("%d", &n))
	{
		if (n < 8)
		{
			puts("Impossible.");
			continue;
		}
		if (n == 8)
		{
			puts("2 2 2 2");
			continue;
		}
		if (n == 9)
		{
			puts("2 2 2 3");
			continue;
		}
		if (n == 10)
		{
			puts("2 2 3 3");
			continue;
		}
		if (n == 11)
		{
			puts("2 3 3 3");
			continue;
		}
		if (n == 12)
		{
			puts("3 3 3 3");
			continue;
		}
		int flag = 1;
		if (n % 2 == 0)
			n -= 4;
		else
		{
			flag = 0;
			n -= 5;
		}
		for (int i = 1; i <= len; i++)
		{
			if (Prime[i] * 2 > n)
				break;
			if (isPrime[n - Prime[i]])
			{
				if (flag)
					printf("2 2");
				else
					printf("2 3");
				printf(" %d %d\n", Prime[i], n - Prime[i]);
				break;
			}
		}
	}

    return 0;
}