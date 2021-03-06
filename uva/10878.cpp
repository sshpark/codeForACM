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

int getsum(int i)
{
	if (i <= 5 && i >= 2)
		return 1 << (8 - i);
	else
		return 1 << (9 - i);
}

int main() 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	// freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	
	string str;

	while (getline(cin, str))
	{
		if (str == "___________")
			continue;
		int sum = 0;
		for (int i = 1; i < str.size()-1; i++)
		{
			if (str[i] == 'o')
				sum += getsum(i);
		}
		printf("%c", sum);
	}

    return 0;
}	