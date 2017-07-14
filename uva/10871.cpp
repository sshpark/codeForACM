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
int sum[10005];
int qmod(int a, int b, int c)
{
	int ans = 1;
	a %= c;
	while (b)
	{
		if (b & 01)
			ans = (ans * a) % c;
		a = (a*a)%c;
		b >>= 1;
	}
	return ans;
}

bool MillerRabin(int x, int n)
{
	int y = n - 1;
	while (!(y&1)) y >>= 1;
	x = qmod(x, y, n);
	while(y < n-1 && x != 1 && x != n-1)
		x = (x*x)%n, y <<= (ll)1;
	return (x == n-1) || ((y&1) == 1);
}

bool isprime(int n)
{
	if (n == 2 || n == 7 || n == 61)
		return 1;
	if (n == 1 || (n&1) == 0)
		return 0;
	return MillerRabin(2, n) && MillerRabin(7, n) && MillerRabin(61, n);
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int T, n, x, k;
	scanf("%d", &T);
	while (T--)
	{
		ms(sum);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			sum[i] = sum[i-1] + x;
		}
		bool ok = false;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j+i-1 <= n; j++)
			{
				k = sum[j+i-1] - sum[j-1];
				if (isprime(k))
				{
					ok = true;
					printf("Shortest primed subsequence is length %d:", i);
					for (k = 1; k <= i; k++)
						printf(" %d", sum[j+k-1] - sum[j+k-2]);
					printf("\n");
					break;
				}
			}
			if (ok)
				break;
		}
		if (!ok)
			puts("This sequence is anti-primed.");
	}

    return 0;
}