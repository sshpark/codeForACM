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
char A[105], B[105];
int a[105], b[105];

void trans(char s[], char s1[])
{
	int lens = strlen(s);
	int lens_1 = strlen(s1);
	for (int i = 0; i < lens; i++) 
		a[i] = s[i] - '0';
	for (int i = 0; i < lens_1; i++) 
		b[i] = s1[i] - '0';
}

void solve()
{
	int lena = strlen(A);
	int lenb = strlen(B);
	
}



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif


	while (~scanf("%s %s", A, B))
	{
		trans(A, B);
		solve();
	}

    return 0;
}