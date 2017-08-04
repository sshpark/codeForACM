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

const int maxn = 1000;

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	ll phi[1001];
	for (int i = 1; i <= maxn; i++)
		if (i & 1)
			phi[i] = i;
		else
			phi[i] = i/2;
	for (int i = 3; i <= maxn; i++)
		if (phi[i] == i)
		{
			for (int j = i; j <= maxn; j += i)
				phi[j] = phi[j]/i*(i - 1);
		}
	for (int i = 2; i < 1001; i++)
		phi[i] += phi[i-1];

	int t, n;
	cin >> t;
	for (int ca = 1; ca <= t; ca++)
	{
		cin >> n;
		printf("%d %d %lld\n", ca, n, phi[n]*2+1);
	}	

    return 0;
}