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
map<string, int> mm;

int judge(string a, string b, string c)
{
	int x = (mm[b] - mm[a] + 12)%12;
	int y = (mm[c] - mm[b] + 12)%12;
	int z = (mm[c] - mm[a] + 12)%12;
	if (x == 4 && y == 3 && z == 7)
		return 2;
	if (x == 3 && y == 4)
		return 1;
	return 0;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	string a, b, c;
	mm["C"] = 1, mm["C#"] = 2, mm["D"] = 3, mm["D#"]= 4, mm["E"] = 5, mm["F"] = 6;
	mm["F#"] = 7, mm["G"] = 8, mm["G#"] = 9, mm["A"] = 10, mm["B"] = 11, mm["H"] = 12;
	while (cin >> a >> b >> c)
	{
		if (judge(a, b, c) == 2 || judge(a, c, b) == 2 || judge(b, a, c) == 2 || judge(b, c, a) == 2 || judge(c, a, b) == 2 || judge(c, b, a) == 2)
			puts("major");
		else if (judge(a, b, c) == 1 || judge(a, c, b) == 1 || judge(b, a, c) == 1 || judge(b, c, a) == 1 || judge(c, a, b) == 1 || judge(c, b, a) == 1)
			puts("minor");
		else
			puts("strange");
	}

    return 0;
}