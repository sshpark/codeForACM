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
#define N (1024)

struct text
{
	int num;
	string word[1024];
}t1, t2;

string s1, s2;
int f[N][N];

void devide(string s, text &t)
{
	int l = s.size();
	t.num = 1;
	for (int i = 0; i < 1000; i++)
		t.word[i].clear();
	for (int i = 0; i < l; i++)
		if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9'))
			t.word[t.num] += s[i];
		else
			++t.num;
	int now = 0;
	for (int i = 1; i <= t.num; i++)
		if (!t.word[i].empty())
			t.word[++now] = t.word[i];
	t.num = now;

}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int test = 0;

	while (!cin.eof())
	{
		++test;
		getline(cin, s1);
		devide(s1, t1);
		getline(cin, s2);
		devide(s2, t2);
		printf("%2d. ", test);
		if (s1.empty() || s2.empty())
		{
			printf("Blank!\n");
			continue;
		}
		ms(f);
		for (int i = 1; i <= t1.num; i++)
			for (int j = 1; j <= t2.num; j++)
			{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
				if (t1.word[i] == t2.word[j])
					f[i][j] = max(f[i][j], f[i-1][j-1]+1);
			}
		printf("Length of longest match: %d\n", f[t1.num][t2.num]);
	}

    return 0;
}

// 1. Length of longest match: 1
// 2. Blank!
// 3. Length of longest match: 2