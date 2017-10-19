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
#include <bitset>
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
#define REP(i, k, n) for (int i = k; i < n; i++)
#define REPP(i, k, n) for (int i = k; i <= n; i++)
const int inf = 0x3f3f3f3f;
#define LOCAL
string save[2005];
int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n;
	map<string, int> m;
	set<string> ss;
	string f, s;
	while (~scanf("%d", &n) && n) {
		ss.clear();
		m.clear();
		REP(i, 0, n) {
			cin >> f >> s;
			save[i] = s;
			ss.insert(f), ss.insert(s);
		}
		int cnt = 0, in[2005];
		ms(in);
		for (auto i = ss.begin(); i != ss.end(); i++) m[*i] = cnt++;
		REP(i, 0, n) in[m[save[i]]]++;
		int ans = 0;
		REP(i, 0, cnt)
		if (in[i] == 0) ans++;
		if (ans == 1) puts("Yes");
		else puts("No");
	}
    return 0;
}