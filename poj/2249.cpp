#include <iostream>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	ll n, m;
	while (~scanf("%lld %lld", &n, &m) && n+m) {
		ll sum = 1;
		if (m*2 > n) m = n-m;
		for (ll i = 1, j = n; i <= m; i++, j--)
			sum = sum*j/i;
		printf("%lld\n", sum);
	}
	return 0;
}