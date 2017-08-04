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
#define ms(s) memset(s, true, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL
bool is[2017];
void shuai()
{
	ms(is);
	is[0] = is[1] = 0;
	for (int i = 2; i <= 2010; i++)
		if (is[i])
			for (int j = i*i; j <= 2010; j+=i)
				is[j] = false;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif
	shuai();
	int T, p[1000], kase = 0;
	char str[2017];
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < 1000; ++i)
			p[i] = 0;
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++)
		{
			p[str[i]]++;
		}
		printf("Case %d: ", ++kase);
		int flag = 0;
		for (int i = 0; i < 1000; i++)
		{
			if (is[p[i]])
			{
				flag = 1;
				printf("%c", i);
			}
		}
		if (!flag)
			printf("empty");
		printf("\n");
	}

    return 0;
}