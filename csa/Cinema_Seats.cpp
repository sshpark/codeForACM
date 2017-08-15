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

char s[100005];
int a[100005];

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	while (~scanf("%s", s))
	{
		ms(a);
		if (s[0] == '1')
			a[0] = 0;
		else
			a[0] = 1;
		int len = strlen(s);
		for (int i = 1; i < len; i++)
		{
			a[i] = 0;
			if (s[i] == '0')
				a[i] = a[i-1]+1;
		}	
		int cur = 0, maxa = -1;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == 0)
			{
				if (i==0)
					cur = 1;
				else
					cur = 1+a[i-1];
				int loc = 0, j;
				for (j = i+1; j < len; j++)
					if (a[j] != 0)
						cur += 1;
					else
					{
						loc = 1;
						break;
					}
				i = j-1;
				maxa = max(maxa, cur);
				cur = 0;
			}
			
		}
		printf("%d\n", maxa);
	}

    return 0;
}