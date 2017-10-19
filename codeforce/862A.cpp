#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, a[105], x, q;
	memset(a, 0, sizeof a);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> q;
		a[q] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < x; i++)
		if (!a[i]) cnt++;
	if (a[x])
		cnt++;
	printf("%d\n", cnt);
	return 0;
}