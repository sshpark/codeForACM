#include <iostream>
using namespace std;
int pre[505];
void init(int n)
{
	for (int i = 1; i <= n; i++)
		pre[i] = i;
}

int findx(int x)
{
	int r = x, j = x;

  	while (r != pre[r])
    	r = pre[r];

  	while (j != r)
  	{
		int k = pre[j];
     	pre[j] = r;
     	j = k;
  	}
  	return r;
}

void unite(int x, int y)
{
	x = findx(x);
	y = findx(y);
	if (x != y)
		pre[x] = y;
}

bool isConnect(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (pre[i] == i)
			cnt++;
	return cnt == 1;
}
int main()
{
	int in[505], out[505], deg[505];
	int T, n, m;
	scanf("%d", &T);
	while (T--)
	{
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(deg, 0, sizeof(deg));
		scanf("%d %d", &n, &m);
		int from, to;
		init(n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &from, &to);
			unite(from, to);
			deg[from]++, deg[to]++;
			out[to]++, in[from]++;
		}
		if (n == 1 && m == 0)
		{
			puts("Yes Yes");
			continue;
		}
		if (!isConnect(n))
		{
			puts("No No");
			continue;
		}
		int oddF = 0, mark = 0;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] & 1)
				oddF++;
			if (in[i] == out[i])
				continue;
			else if (abs(in[i] - out[i]) == 1 && ~mark)
				mark++;
			else
				mark = -1;
		}
		printf("%s %s\n", oddF <= 2 ? "Yes" : "No", mark == 0 || mark == 2 ? "Yes" : "No");
	}
}