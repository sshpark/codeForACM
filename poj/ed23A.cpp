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

	int x1, x2, y1, y2, x, y;

	while (~scanf("%d%d%d%d", &x1, &y1, &x2, &y2))
	{
		scanf("%d%d", &x, &y);
		if ((abs(x1-x2)%x == 0) && (abs(y1-y2)%y == 0) && (abs(x1-x2)/x%2 == abs(y1-y2)/y%2))
			puts("YES");
		else
			puts("NO");
	}

    return 0;
}