#include <iostream>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	int T, n, m;
	cin >> T;
	ll d[35];
	d[1] = 0, d[2] = 1;
	for (int i = 3; i <= 34; i++)
		d[i] = (i-1)*(d[i-1]+d[i-2]);
	while (T--) {
		cin >> n >> m;
		ll sum = 1;
		for (int i = 1, j = n; i <= m; i++, j--)
			sum = sum*j/i;
		printf("%lld\n", sum*d[m]);
	}
	return 0;
}