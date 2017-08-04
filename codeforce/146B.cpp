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
int a[102][102][13];

int sum(int x1, int y1, int x2, int y2,int k)
{
	return a[x2][y2][k] + a[x1 - 1][y1 - 1][k] - a[x1 - 1][y2][k] - a[x2][y1 - 1][k];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q, c;
	cin >> n >> q >> c;
	for (int i = 0; i < n; i++)
	{
		int x, y, s; cin >> x >> y >> s;
		a[x][y][s]++;
	}
	for (int k = 0; k < 13; k++)
		for (int i = 1; i < 101; i++)
			for (int j = 1; j < 101; j++)
				a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] - a[i - 1][j - 1][k];
	int mod = c + 1;
	for (int j = 0; j < q; j++)
	{
		int t,x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
		ll s = 0;
		for (int i = 0; i <= c; i++)
		{
			s += sum(x1, y1, x2, y2, i)*((t+i)%mod);
		}
		cout << s << endl;
	}
	return 0;
}