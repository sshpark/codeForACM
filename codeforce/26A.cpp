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

int is[3005];
int p[3005];
int re[3005];
int cnt = 1;
void shuai()
{
	for (int i = 0; i <= 3002; i++)
		is[i] = 1;
	is[0] = is[1] = 0;
	p[0] = 2;
	for (int i = 2; i <= 3002; i++)
		if (is[i])
		{
			p[cnt++] = i;
			for (int j = i*i; j <= 3002; j+=i)
				is[j] = 0;
		}
}

int divide(int n)
{
	int s = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (p[i] > n)
			break;
		if (n % p[i] == 0)
		{
			s++;
			do
			{
				n /= p[i];
			}while(n % p[i] == 0);
		}
	}
	return s;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	int n;
	shuai();
	ms(re);
	for (int i = 1; i <= 3002; i++)
		if (divide(i) == 2)
			re[i]++;
	for (int i = 1; i <= 3002; i++)
		re[i] += re[i-1];
	while (~scanf("%d", &n))
		printf("%d\n", re[n]);

    return 0;
}