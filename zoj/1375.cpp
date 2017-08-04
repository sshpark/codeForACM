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

int m_map[105][105];


int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, k, T, x, y, x1, y1;
	int max_x, max_y, sum_s;
	scanf("%d", &T);
	
	while (T--)
	{
		ms(m_map);
		max_x = 0, max_y = 0, sum_s = 0;
		scanf("%d %d", &n, &k);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d %d %d %d", &x, &y, &x1, &y1);
			if (x > max_x) max_x = x;
			if (x1 > max_x) max_x = x1;
			if (y > max_y) max_y = y;
			if (x < x1)
			{
				for (int j = x; j <= x1; j++)
					m_map[j][y] = i;
			}
			else
			{
				for (int j = x1; j <= x; j++)
					m_map[j][y] = i;
			}
		}

		for (int i = 0; i <= max_x; i++)
		{
			int tem = 0;
			for (int j = 0; j <= max_y; j++)
				if (m_map[i][j] > 0)
					tem++;
			int offset = tem - k;
			if (offset > 0)
			{
				sum_s += offset;
				while (offset--)
				{
					int max_s = 0, max_bh;
					for (int k = 0; k <= max_y; k++)
					{
						if (m_map[i][k] > 0)
						{
							int tem_s = 0;
							for (int z = i+1; z <= max_x; z++)
								if (m_map[z][k] == m_map[i][k])
									tem_s++;
								else
									break;
							if (max_s < tem_s)
							{
								max_s = tem_s;
								max_bh = k;
							}
						}
					}
					for (int a = i; a <= i+max_s; a++)
						m_map[a][max_bh] = 0;
				}
			}
		}
		printf("%d\n", sum_s);
	}

    return 0;
}