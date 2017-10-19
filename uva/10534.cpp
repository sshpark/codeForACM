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
const int inf = 2147483647;
// #define LOCAL

const int maxn = 10010;
int N, A[maxn], F[maxn], G[maxn], L[maxn];

int binary(int l, int r, int x)
{
	int mid;
	l = 0, r = N;
	while(l < r)
	{
		mid = (l+r) >> 1;
		if (L[mid+1] >= x)
			r = mid;
		else
			l = mid+1;
	}
	return l;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int j, k, ans;

	while (~scanf("%d", &N))
	{
		for (int i = 1; i <= N; i++)
			scanf("%d", A+i);
		for (int i = 1; i <= N; i++)
			L[i] = inf;
		L[0] = -inf-1;
		for (int i = 1; i <= N; i++)
		{
			F[i] = binary(1, N, A[i])+1;
			if (A[i] < L[F[i]])
				L[F[i]] = A[i];
		}
		for (int i = 1; i <= N; i++)
			L[i] = inf;
		L[0] = -inf-1;
		for (int i = N; i >= 1; i--)
		{
			G[i] = binary(1, N, A[i])+1;
			if (A[i] < L[G[i]])
				L[G[i]] = A[i];
		}
		ans = 0;
		for (int i = 1; i <= N; i++)
			if ((k = min(F[i], G[i])) > ans)
				ans = k;
			printf("%d\n", ans*2-1);
	}


    return 0;
}