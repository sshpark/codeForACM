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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	char str[1005];
	int a[15];
	while (~scanf("%s", str))
	{
		ms(a);
		int n = strlen(str);
		bool flag = false;
		for (int i = 0; i < n; i++)
			a[str[i] - '0']++;
		for (int i = 0; i <= 8; i++)
		{
			if (a[i] != a[i+1])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
			puts("1");
		else
			puts("0");

	}

    return 0;
}