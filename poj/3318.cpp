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
const int N = 505;
int A[N][N], B[N][N], C[N][N];
int n;
bool ok()
{
	int c, r, tem;
	REP(i, 0, 10000)
	{
		r = rand()%n;
		c = rand()%n;
		tem = 0;
		REP(j, 0, n) tem += A[r][j]*B[j][c];
		if (tem != C[r][c]) return false;
	}
	return true;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif


	while (~scanf("%d", &n))
	{
		srand(time(NULL));
		REP(i, 0, n)
		REP(j, 0, n) scanf("%d", &A[i][j]);
		REP(i, 0, n)
		REP(j, 0, n) scanf("%d", &B[i][j]);
		REP(i, 0, n)
		REP(j, 0, n) scanf("%d", &C[i][j]);
		if (ok())
			puts("YES");
		else
			puts("NO");
	}

    return 0;
}