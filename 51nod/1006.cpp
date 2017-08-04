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

	char a[1005], b[1005], ans[1005];
	int f[1005][1005];

	while (~scanf("%s", a))
	{
		scanf("%s", b);
		ms(f);
		int al = strlen(a);
		int bl = strlen(b);
		for (int i = 1; i <= al; i++)	
			for (int j = 1; j <= bl; j++)
			{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
				if (a[i-1] == b[j-1])
					f[i][i] = max(f[i][j], f[i-1][j-1]+1);
			}
	int i = al;
    int j = bl;
    while(i)
    {
        if (f[i][j] > f[i - 1][j])
        {
            if (f[i][j] > f[i][j - 1])
                ans[f[i][j] - 1] = a[i - 1];
            else i++;    //左平移
            j--;    //减小一个规模
        }
        i--;    //上平移
    }
		printf("%s\n", ans);
	}

    return 0;
}