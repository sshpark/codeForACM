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
set<int> s;
vector<int> l[8888];
int a[105][105];

void dijkstra(int start, int n)
{
	int vis[9999];
	int dis[9999];
	ms(vis);
	ms(dis);
    //初始化v[0]到v[i]的距离
    // for (int i = start; i < l[start].size(); i++)
    // {
    // 	dis[l[start][i]] = 1;
    // }

    vis[start] = 1;//标记v[0]点
    for(int i = start; i <= n; i++)
    {
        //查找最近点
        int minx = 99999999,k = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dis[j] < minx)
            {
                minx = dis[j];
                k = j;
            }
        vis[k] = 1;//标记查找到的最近点
        //判断是直接v[0]连接v[j]短，还是经过v[k]连接v[j]更短
        for(int j = 1; j <= n; j++)
            if(!vis[j] && minx+l[k][j] < dis[j])
            {
                dis[j] = minx+l[k][j];
            }
    }

}

int main(int argc, char * argv[]) 
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	int n, m, from, to, maxn = -1;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		a[i][0] = m;
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
			maxn = max(maxn, a[i][j]);
		}
	}
	// puts("Sorry, no line is available.");

	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 0; j <= a[i][0]; j++)
	// 		printf("%d ", a[i][j]);
	// 	printf("\n");
	// }

	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= a[i][0]; j++)
		{
			l[a[i][j-1]].push_back(a[i][j]);
			l[a[i][j]].push_back(a[i][j-1]);
		}

	dijkstra(a[1][1], maxn);






    return 0;
}