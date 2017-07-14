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

	int a1, b1, a2, b2, a3, b3;

	while (~scanf("%d %d", &a1, &b1))
	{
		scanf("%d %d", &a2, &b2);
		scanf("%d %d", &a3, &b3);
		if (a1 < b1)
			swap(a1, b1);
		if (a2 < b2)
			swap(a2, b2);
		if (a3 < b3)
			swap(a3, b3);
		if ((a3 + a2 <= a1 && max(b2, b3) <= b1) || (max(a2, a3) <= a1 && (b2+b3) <= b1))
			puts("YES");
		else if ((b2 + b3 <= a1 && max(a2, a3) <= b1))
			puts("YES");
		else if ((b2 + a3 <= a1 && max(a2, b3) <= b1) || (max(b2, a3) <= a1 && a2 + b3 <= b1))
			puts("YES");
		else if ((b3 + a2 <= a1 && max(a3, b2) <= b1) || (max(b3, a2) <= a1 && a3 + b2 <= b1))
			puts("YES");
		else
			puts("NO");
	}

    return 0;
}