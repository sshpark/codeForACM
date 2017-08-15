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
int a[50];
int getBin(ll n)
{
	int i = 0;
	while(n)
	{
		a[i++] = n&1;
		n = n/2;
	}
	return i;
}


int C(int n, int m)
{
	int ans = 1, end = n-m+1;
	for (int i = n; i >= end; i--)
		ans = ans*i/(m--);
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int l, r;
	
	while (~scanf("%d %d", &l, &r))
	{
		int len = getBin(r);
		int re = pow(2, len-1);
		int one = 0, zero = 0;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == 1)
				one++;
			else
			{
				zero++;
				
			}
		}

	}

    return 0;
}


// 1110111001101011001010000000000