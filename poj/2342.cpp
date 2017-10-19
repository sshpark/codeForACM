#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int v;
	int p;
}a[100005];
bool cmp(node a, node b)
{
	return a.v <= b.v;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].v);
		a[i].p = i;
	}
	sort(a, a+n, cmp);
	int mx = 0;
	for (int i = 0; i < n; i++)
		mx = max(mx, a[i].p-i);
	printf("%d\n", mx+1);
}