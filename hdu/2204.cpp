#include <iostream>
#include <cmath>
#include <stdio.h>
#define ll long long
using namespace std;
int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int main(int argc, char const *argv[])
{
	ll n, temp;
	while (~scanf("%lld", &n)) {
		ll ans = 1;
		for (int i = 0; ; i++) {
			temp = (ll)(pow(n, 1.0/p[i]));
			if (temp < 2) break;
			ans += temp-1;
			for (int j = i+1; ; j++) {
				temp = (ll)pow(n, 1.0/(p[i]*p[j]));
				if (temp < 2) break;
				ans -= temp - 1;
				for (int k = j+1; ; k++) {
					temp = (ll)pow(n, 1.0/(p[i]*p[j]*p[k]));
					if (temp < 2) break;
					ans += temp - 1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}