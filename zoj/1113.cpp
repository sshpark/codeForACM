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
// #define LOCAL
int fac(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return fac(n-1)*n;
}

double f(int n)
{
	if (n == 0)
		return 1;
	double ans = 1;
	for (int i = 1; i <= n; i++)
		ans += 1.0/fac(i);
	return ans;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	puts("n e");
	puts("- -----------");
	puts("0 1");
	puts("1 2");
	puts("2 2.5");
	int n = 0;
	double e = 0;
	for (int i = 3; i <= 9; i++)
		printf("%d %.9lf\n", i, f(i));



    return 0;
}