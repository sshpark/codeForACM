#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[105][105], m[105][105];
int r, c;
int nxt[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dp(int x, int y)
{	
	int ms = 0;
	if (m[x][y] != 0)   //	记忆化搜索
		return m[x][y];
	for (int i = 0; i < 4; i++)
	{
		int tx = x + nxt[i][0];
		int ty = y + nxt[i][1];
		if (tx < 0 || ty < 0 || tx > r-1 || ty > c-1)
			continue;
		if (a[tx][ty] < a[x][y])
		{
			int s = dp(tx, ty);
			ms = max(ms, s);
		}
	}
	m[x][y] = ms+1;
	return m[x][y];
}
int main()
{
	memset(m, 0, sizeof(m));
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
	int maxa = -1;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			maxa = max(maxa, dp(i, j));
	printf("%d\n", maxa);
}