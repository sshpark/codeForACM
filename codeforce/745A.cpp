#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <regex>
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

	string temp;
	char str[55];
	set<string> s;
	set<string>::iterator it;
	while (~scanf("%s", str))
	{
		s.clear();
		int k, len = strlen(str);
		for (int i = len - 1; i >= 0; i--)
		{
			temp.clear();
			k = i;
			for (int j = 0; j < len; j++)
			{
				temp += (str[(k)%len]);
				k++;
			}
			s.insert(temp);
		}	
		printf("%lu\n", s.size());
	}

    return 0;
}