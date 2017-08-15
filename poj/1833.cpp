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

int getMaxi(int a[], int n)
{
	int loc = 0, maxa = -1;
	for (int i = 1; i < n; i++)
		if (a[i] > a[i-1])
			loc = i;	
	return loc;
}

int getMaxj(int a[], int n, int i)
{
	int loc = 0, maxa = a[i-1];
	for (int i = 0; i < n; i++)
		if (a[i] > maxa)
			loc = i;
	return loc;
}

bool isDec(int a[], int n)
{
	int flag = 1;
	for (int i = 0; i < n-1; i++)
		if (a[i] < a[i+1])
		{
			flag = 0;
			break;
		}
	return flag;
}

int main() __attribute__((optimize("-O3")));
int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int a[1030], k, T, n;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);

		}
		for (int i = 0; i < k; ++i)
		{

			int f = getMaxi(a, n);
			if (f == 0)
			{
				for (int i = 0; i < n/2; i++)
					swap(a[i], a[n-i-1]);
				continue;
			}
			int s = getMaxj(a, n, f);
			swap(a[f-1], a[s]);
			for (int i = 0; i < (n-f+1)/2; i++)
				swap(a[f+i], a[n-i-1]);
		}
		for (int j = 0; j < n-1; j++)
			printf("%d ", a[j]);
		printf("%d\n", a[n-1]);
	}

    return 0;
}