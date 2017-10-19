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
#include <bitset>
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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	double a[10];
	REP (i, 0, 6) scanf("%lf", a+i);
	if ((a[2]-a[0])*(a[5]-a[3]) == (a[3]-a[1])*(a[4]-a[2]))
	{
		puts("NO");
		return 0;
	}
	double m1 = (a[4]+a[0])/2;
	double m2 = (a[5]+a[1])/2;
	if ((a[2]-m1)*(a[4]-a[0])+(a[3]-m2)*(a[5]-a[1]) == 0) puts("YES");
	else puts("NO");

    return 0;
}