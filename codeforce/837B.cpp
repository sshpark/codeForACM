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
char str[105][105];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m;
	set<char> s;
	vector<int> in;

	while (~scanf("%d %d", &n, &m))
	{
		s.clear();
		for (int i = 0; i < n; ++i)
			scanf("%s", str[i]);
		char c;
		int w = 0, flag;
		c = str[0][0];
		for (int i = 0; i < n; ++i)
		{
			if (str[i][0] != c)
			{
				c = str[i][0];
				in.push_back(w);
				w = 0;
			}
			flag = 1;
			for (int j = 0; j < m; ++j)
				if (str[i][j] != c)
				{
					flag = 0;
					break;
				}
			if (flag)
			{
				w++;
				s.insert(c);
			}
			else
			{
				break;
			}
		}
		int flag1 = 1;
		if (flag && s.size() == 3 && n%3 == 0)
		{
			for (int i = 1; i < in.size(); i++)
				if (in[i] != in[i-1])
					flag1 = 0;
		}
		else
			flag1 = 0;
		in.clear();
		s.clear();
		w = 0;
		c = str[0][0];
		for (int i = 0; i < m; ++i)
		{
			if (str[0][i] != c)
			{
				c = str[0][i];
				in.push_back(w);
				w = 0;
			}
			flag = 1;
			for (int j = 0; j < n; ++j)
			{
				if (str[j][i] != c)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				w++;
				s.insert(c);
			}
			else
				break;
		}
		// printf("%d\n", w);
		int flag2 = 1;
		if (flag && s.size() == 3 && m%3 == 0)
		{
			for (int i = 1; i < in.size(); i++)
				if (in[i] != in[i-1])
					flag2 = 0;
		}
		else
			flag2 = 0;
		if (flag2 || flag1)
			puts("YES");
		else
			puts("NO");

	}

    return 0;
}

3 5 3
3 4 2
3 3 1
3 0 0

6 3 1
6 0 0