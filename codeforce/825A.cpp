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



int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	char str[100];
	int n;

	while (~scanf("%d", &n))
	{
		scanf("%s", str);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '1')
				cnt++;
			if (str[i] == '0' || i == n - 1)
			{				
				printf("%d", cnt);
				cnt = 0;
				if (str[i+1] == '0')
				{
					printf("0");
					i += 1;
				}
			}
		}
		if (str[n-1] == '0' && n > 1)
			printf("0");
		printf("\n");
	}

    return 0;
}