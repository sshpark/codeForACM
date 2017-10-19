#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 105;
const int inf = (1<<31)-1;
int dis[maxn][maxn], g[maxn][maxn];
int fa[maxn][maxn], path[maxn];
int num, n, m;
int mina;
void floyd() {
	int tem, p;
	mina = inf;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++)
			for (int j = i+1; j < k; j++) {
				tem = dis[i][j] + g[i][k] + g[k][j];
				if (tem < mina) {
					mina = tem;
					num = 0;
					p = j;
					while (p != i) {
						path[num++] = p;
						p = fa[i][p];
					}
					path[num++] = i;
					path[num++] = k;
				}
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				tem = dis[i][k] + dis[k][j];
				if (dis[i][j] > tem) {
					dis[i][j] = tem;
					fa[i][j] = fa[k][j];
				}
			}
	}
}
int main(int argc, char const *argv[])
{
	int x, y, w;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				g[i][j] = inf;
				dis[i][j] = inf;
				fa[i][j] = i;
			}

		for (int i = 0; i < m; i++) {
			cin >> x >> y >> w;
			w = min(g[x][y], w);
			g[x][y] = g[y][x] = dis[x][y] = dis[y][x] = w;
		}
		floyd();
		if (mina == inf)  puts("No solution.");
		else {
			printf("%d", path[0]);
			for (int i = 1; i < num; i++)
				printf(" %d", path[i]);
			printf("\n");
		}
	}
	return 0;
}