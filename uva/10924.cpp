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
bool isp[1100];
void shuai()
{
	memset(isp, true, sizeof(isp));
	isp[1] = false;
	for (int i = 2; i < 1100; i++)
		if (isp[i])
			for (int j = i*i; j < 1100; j+=i)
				isp[j] = false;
}


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	char str[30];
	shuai();
	while (~scanf("%s", str))
	{
		int len = strlen(str), sum = 0;
		REP(i, 0, len)
		if (islower(str[i])) sum += str[i]-'a'+1;
		else sum += str[i]-'A'+27;
		if (isp[sum]) puts("It is a prime word.");
		else puts("It is not a prime word.");
	}

    return 0;
}