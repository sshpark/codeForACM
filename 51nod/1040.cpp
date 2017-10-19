#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll get(int n) {
	ll cnt = n;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			cnt -= cnt/i;
			while (n%i == 0) n/=i;
		}
	}
	if (n > 1) cnt -= cnt/n;
	return cnt;
}
int main() {
	ll n;
	while (cin >> n) {
		ll ans = 0;
		for (int i = 1; i <= sqrt(n); i++) {
			if (n%i == 0) {
				ans += get(n/i)*i;
				if (n/i != i)
					ans += get(i)*(n/i);
			}
		}
		cout << ans << endl;
	}
}