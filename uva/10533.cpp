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

const int N = 1000005;
bool isprime[N+5];
int isprime1[N+5];
int prime[N >> 1];

int getsum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

void shuai()
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
	shuai();
	memset(isprime1, 0, sizeof(isprime1));
	for (int i = 2; i < N; i++)
	{
		if (isprime[i] && isprime[getsum(i)])
			isprime1[i] = 1;			
	}
	for (int i = 2; i < N; i++)
	{
		isprime1[i+1] += isprime1[i];
	}
	// for (int i = 1; i < 100; i++)
	// 	printf("%d ", isprime[i]);
	while (~scanf("%d", &n))
	{
		int t1, t2;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &t1, &t2);
			printf("%d\n", isprime1[t2] - isprime1[t1-1]);
		}
	}

    return 0;
}