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

const int maxn = 5000005;
unsigned long long phi[maxn+5];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int a, b;

	for (int i = 1; i <= maxn; i++)
		phi[i] = i;
	for (int i = 2; i <= maxn; i+=2)
		phi[i] /= 2;
	for (int i = 3; i <= maxn; i+=2)
		if (phi[i] == i)
		{
			for (int j = i; j <= maxn; j+=i)
				phi[j] = phi[j]/i*(i-1);
		}
	for (int i = 1; i <= maxn; i++)
		phi[i] *= phi[i];
	for (int i = 2; i <= maxn; i++)
		phi[i] += phi[i-1];
	
	int T, kase = 0;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &a, &b);
		printf("Case %d: %llu\n", ++kase, phi[b] - phi[a-1]);
	}

    return 0;
}