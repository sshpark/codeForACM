#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, m;
	int a[105][105], b[105][105];
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		for (int i = 0; i <= n; i++) a[i][i] = 1;
		for (int i = 1; i <= m; i++){
			for (int j = 0; j <= m; j++)
				for (int k = 0; k <= n && k*i+j <= m; k++)
					for (int l = 0; k+l <= n; l++)
						b[k*i+j][l+k] += a[j][l];
			for (int j = 0; j <= m; j++)
				for (int k = 0; k <= n; k++) {
					a[j][k] = b[j][k];
					b[j][k] = 0;
				}
		}
		printf("%d\n", a[m][n]);
	}
	return 0;
}