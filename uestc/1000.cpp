#include <iostream>
using namespace std;
#define ll long long
const ll m = 1000000000;
int cache[305];
ll f(int n) {
	if (n == 0 || n == 1)
		return 1;
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	return cache[n] = (f(n-1)%m + f(n-2)%m)%m;
}

int main(int argc, char const *argv[])
{
	int n;
	memset(cache, -1, sizeof cache);
	while (cin >> n)
	printf("%09lld\n", f(n));
	return 0;
}