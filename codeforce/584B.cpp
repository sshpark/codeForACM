#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
ll qmod(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans*a%mod;
		b >>= 1;
		a = a*a%mod;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << (qmod(27, n)%mod-qmod(7, n)%mod)%mod<< endl;
	return 0;
}