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

	char S[1005], A[1005], B[1005];

	while (~scanf("%s", S))
	{
		scanf("%s", A);
		scanf("%s", B);
		int lens = strlen(S);
		int len = strlen(A);
		int f, s, k, f1;
		for (int i = 0; i < lens; i++)
		{
			f = 0;
			s = 0;
			k = 0;
			f1 = 0;
			for (int j = i; j < i+len && i+len <= lens; j++)
				if (S[j] != A[k++])
				{
					f = 1;
					break;
				}
			if (k == len)
				f1 = 1;
			k = 0;
			if (!f && f1)
			{
				for (int j = i; j < i+len; j++)
					S[j] = B[k++];
				i += len-1;
				continue;
			}
			k = 0;
			f1 = 0;
			for (int j = i; j < i+len && i+len <= lens; j++)
				if (S[j] != B[k++])
				{
					s = 1;
					break;
				}
			if (k == len)
				f1 = 1;
			k = 0;
			if (!s && f1)
			{
				for (int j = i; j < i+len; j++)
					S[j] = A[k++];
				i += len-1;
				continue;
			}
		}
		for (int i = 0; i < lens; i++)
			printf("%c", S[i]);
		printf("\n");
	}

    return 0;
}