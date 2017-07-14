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

map<char, char> _hash;

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	char str[30], str1[30], re[1005];

	while (~scanf("%s %s %s", str, str1, re))
	{
		// printf("%s %s %s\n", str, str1, re);
		for (int i = 0; i < 26; i++)
			_hash[str[i]] = str1[i];
		int len = strlen(re);
		for (int i = 0; i < len; ++i)
		{
			if (re[i] >= 'A' && re[i] <= 'Z')
			{
				printf("%c", _hash[re[i]+32]-32);
			}
			else if (re[i] <= '9' && re[i] >= '0')
				printf("%c", re[i]);
			else
				printf("%c", _hash[re[i]]);
		}
		printf("\n");
	}

    return 0;
}