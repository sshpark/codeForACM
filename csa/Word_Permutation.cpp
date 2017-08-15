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

void me()
{
	ios::sync_with_stdio(0);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.first < b.first;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	me();
	int n;
	cin >> n;
	vector<pair<string, int> > v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n-1; i++)
		cout << v[i].second << " ";
	cout << v[n-1].second << endl;
    return 0;
}