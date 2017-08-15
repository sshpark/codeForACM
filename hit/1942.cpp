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

struct process
{
	int id;
	int na, nb, nc;	
}p[55];

bool cmp(struct process a, struct process b)
{
	return a.na < b.na;
}

bool cmp1(struct process a, struct process b)
{
	return a.nb < b.nb;
}
bool cmp2(struct process a, struct process b)
{
	return a.nc < b.nc;
}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int a, b, c, n;

	while (~scanf("%d %d %d", &a, &b, &c) && a+b+c)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &p[i].na, &p[i].nb, &p[i].nc);
			p[i].id = i+1;
		}
		sort(p, p+n, cmp);
		sort(p, p+n, cmp1);
		sort(p, p+n, cmp2);
		for (int i = 0; i < n; i++)
		{
			printf("%d %d %d\n", p[i].na, p[i].nb, p[i].nc);
		}
		int re = 0, ca = 0, cb = 0, cc = 0;
		std::vector<int> v;
		for (int i = 0; i < n; i++)
		{
			if (ca > a || cb > b || cc > c)
				break;
			ca += p[i].na;
			cb += p[i].nb;
			cc += p[i].nc;
			re++;
			v.push_back(p[i].id);
		}
		printf("%d\n", re);
		if (v.size() != 0)
		{
			printf("%d", v[0]);
			for (int i = 1; i < v.size(); ++i)
				printf(" %d", v[i]);
			printf("\n");
		}
		else
			puts("0");
	}

    return 0;
}