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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	char str[205];
	while (~scanf("%d", &n))
	{
		getchar();
		cin.getline(str, 205);
		int maxa = 0, cur = 0;
		for (int i = 0; i < n; i++)
		{
			if ('A' <= str[i] && str[i] <= 'Z')
				cur++;
			if (str[i] == ' ')
				cur = 0;
			maxa = max(maxa, cur);
		}
		printf("%d\n", maxa);
	}

    return 0;
}