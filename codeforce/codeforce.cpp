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
int a[10], x[10], book[10];
char str[10];
void dfs(int step, int n)
{
	if (step == n+1)
	{
		for (int i = 0; i < n-1; i++)
			printf("%d ", x[i]);
		printf("%d\n", x[n-1]);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!book[i])
		{
			book[a[i]] = 1;
			x[step] = a[i];
			dfs(step+1, n);
			book[a[i]] = 0;
		}
	}
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	while (~scanf("%s", str))
	{
		ms(book);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			a[i] = str[i] - '0';
		dfs(0, len);
	}

    return 0;
}